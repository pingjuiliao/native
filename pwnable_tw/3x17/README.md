# Pwnable_tw 3x17 Exploit

# find the read-only data
Based on what we will see by executing the program
```
addr: <my input>
data: <my another input>
```

## Find the RODATA

```
# via objdump
objdump -d -j .rodata ./given/3x17
```

Result:
```
# grep "data:"
 48f000 01000200 61646472 3a006461 74613a00  ....addr:.data:.
 
# then seach for uses of it
  401bb0:	48 8d 35 4d d4 08 00 	lea    0x8d44d(%rip),%rsi        # 0x48f004
  401bfd:	48 8d 35 06 d4 08 00 	lea    0x8d406(%rip),%rsi        # 0x48f00a
```
