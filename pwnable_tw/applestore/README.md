# Intro
This challenge is kind of hard in my opinion.
Here we go through each part of process

# Program behavior
This is a shopping application to where we can add/remove items from the shopping cart.

The cart is managed as a global data in an doubly linked list structure.
see './decompile/reverse.c' for detail.
```
struct _AppleProduct {
  char* name;
  int price;
  struct _AppleProduct *next;
  struct _AppleProduct *prev;
} AppleProduct;
```


# The vulnerability
In checkout() function, we can make a secret perchase-an iphone8 in $1
However, the purchase, unlike regular ones, linked the linked list on the stack.
Moreover, add()/delete()/cart() functions's command buffers are overlapping with 
this area of structure, giving advasary full control of this iphone8's data.

If we are careful with the 'iphone8->next' and 'iphone8->prev', we can do all the operation normally.


# Arbitrary read
As mentioned, cart() function's command buffer get the control to the full 
iphone8 data, and because `AppleProduct->name` will be print out in 
cart() function, we get to perform arbitrary write as much time as possible.


# Arbitrary write (nearly) - what we can/cannot do
Another interesting trick is use delete() to perform arbitrary write,
pseudocode in delete():
```
node = node_to_delete
if node.next is not None:
  node.prev.next = node.next
if node.prev is not None:
  node.next.prev = node.prev
```

As mentioned, delete()'s command buffer overlaps the iphone8's data; therefore,
we get to write the data with proper adjustment.

However, if we want to make `node.prev.next` written with `node.next`, 
we also need to make `node.next.prev` written with `node.prev`.
That is, both pointers `node.prev` and `node.next` SHOULD POINT TO A WRITABLE
AREA!. As a counterexample, say we try to write some GOT value into libc's execve,
it won't work because libc .text area are not writable.


# Arbitrary write -- write the EBP
The final decision are made to write the saved EBP value, which is brilliant attack.

### summarized steps:
1. overwrite the saved ebp in delete()
2. After returning from the delete() function,
   delete()'s caller, handler(), will have the ebp value in attacker's control, and we choose area around `got['atoi']`

3. In handler()'s command reading, it goes through `read(0, buf, ..)` and 
`atoi(buf)`. Here, because the buf is accessed by `ebp - offset`, the read operation allowed advasary to change `got['atoi']` and the buffer itself is passed into `atoi`. So, by placing


### relavent assembly code
```
0x8048c05 lea eax, [ebp - 0x22]
0x8048c08 mov DWORD PTR [esp], eax
0x8048c0b call 0x8048799 <my_read>
0x8048c10 lea eax, [ebp - 0x22]
0x8048c13 mov DWORD PTR [esp], eax
0x8048c16 call 0x8048560 <atoi@plt>
```

### Graphical ebp stack access
Our attack only works because `ebp` is used for accessing the buffer.
```
In handler():
    v --- got[atoi]   |                                      v ebp
    |  -------------------------- 0x22 --------------------- |
    ^
    buf: [ebp - 0x22]
    
what we are writing
    
    | libc['system']  | ;/bin/sh'|

so the atoi(buf) will become:
    system("\xff\x96\xef\x00;/bin/sh;")
```

Alternative:
```
In handler():
                  v--- got[atoi]   |                          v ebp
    | ------------|--------------- 0x22 --------------------- |
    ^
    buf: [ebp - 0x22]
what we are writing
    
    | /bin/sh\x00 | libc['system']

so the atoi(buf) will become:
    system("/bin/sh")
```


