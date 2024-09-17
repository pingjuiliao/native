
typedef struct _AppleProduct {
  char* name;
  int price;
  struct _MyCart *next;
  struct _MyCart *prev; // sizeof(MyCart) == 0x10
} AppleProduct; 

AppleProduct myCart; // 0x804b068


void add(void)
{
  int iVar1;
  int in_GS_OFFSET;
  undefined4 *local_30;
  char local_26 [22];     // ebp - 0x22
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  printf("Device Number> ");
  fflush(stdout);
  my_read(local_26,0x15);
  iVar1 = atoi(local_26);
  switch(iVar1) {
  default:
    puts("Stop doing that. Idiot!");
    goto LAB_08048986;
  case 1:
    local_30 = (undefined4 *)create("iPhone 6",199);
    break;
  case 2:
    local_30 = (undefined4 *)create("iPhone 6 Plus",299);
    break;
  case 3:
    local_30 = (undefined4 *)create("iPad Air 2",499);
    break;
  case 4:
    local_30 = (undefined4 *)create("iPad Mini 3",399);
    break;
  case 5:
    local_30 = (undefined4 *)create("iPod Touch",199);
  }
  insert(local_30);
  printf("You\'ve put *%s* in your shopping cart.\n",*local_30);
  puts("Brilliant! That\'s an amazing idea.");
LAB_08048986:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


int cart(void)
{
  int in_GS_OFFSET;
  int local_34;
  int local_30;
  undefined4 *local_2c;
  char local_26 [22];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_34 = 1;
  local_30 = 0;
  printf("Let me check your cart. ok? (y/n) > ");
  fflush(stdout);
  my_read(local_26,0x15);
  if (local_26[0] == 'y') {
    puts("==== Cart ====");
    for (local_2c = (undefined4 *)myCart._8_4_; local_2c != (undefined4 *)0x0;
        local_2c = (undefined4 *)local_2c[2]) {
      printf("%d: %s - $%d\n",local_34,*local_2c,local_2c[1]);
      local_30 = local_30 + local_2c[1];
      local_34 = local_34 + 1;
    }
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_30;
}


void checkout(void)
{
  int in_GS_OFFSET;
  int local_2c;
  char *local_24;      // ebp - 0x20: AppleProduct.name
  undefined4 local_20; // ebp - 0x1c: AppleProduct.price
  int local_10;        // ebp - 0x18: AppleProduct.next
                       // epb - 0x14: AppleProduct.prev
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_2c = cart();
  if (local_2c == 0x1c06) {
    puts("*: iPhone 8 - $1");
    asprintf(&local_24,"%s","iPhone 8");
    local_20 = 1;
    insert(&local_24);
    local_2c = 0x1c07;
  }
  printf("Total: $%d\n",local_2c);
  puts("Want to checkout? Maybe next time!");
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


char ** create(undefined4 param_1,char *param_2)
{
  char **__ptr;
  
  __ptr = (char **)malloc(0x10);
  __ptr[1] = param_2;
  asprintf(__ptr,"%s",param_1);
  __ptr[2] = (char *)0x0;
  __ptr[3] = (char *)0x0;
  return __ptr;
}


void delete(void)
{
  int iVar1;
  int iVar2;
  int in_GS_OFFSET;
  int local_3c;
  undefined4 *local_38;
  char local_26 [22];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_3c = 1;
  local_38 = (undefined4 *)myCart._8_4_;
  printf("Item Number> ");
  fflush(stdout);
  my_read(local_26,0x15);
  iVar2 = atoi(local_26);
  do {
    if (local_38 == (undefined4 *)0x0) {
LAB_08048a5e:
      if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
    if (local_3c == iVar2) {
      iVar2 = local_38[2];
      iVar1 = local_38[3];
      if (iVar1 != 0) {
        *(int *)(iVar1 + 8) = iVar2;
      }
      if (iVar2 != 0) {
        *(int *)(iVar2 + 0xc) = iVar1;
      }
      printf("Remove %d:%s from your shopping cart.\n",local_3c,*local_38);
      goto LAB_08048a5e;
    }
    local_3c = local_3c + 1;
    local_38 = (undefined4 *)local_38[2];
  } while( true );
}


void handler(void)
{
  int iVar1;
  int in_GS_OFFSET;
  char local_26 [22];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  do {
    printf("> ");
    fflush(stdout);
    my_read(local_26,0x15);
    iVar1 = atoi(local_26);
    switch(iVar1) {
    default:
      puts("It\'s not a choice! Idiot.");
      break;
    case 1:
      list();
      break;
    case 2:
      add();
      break;
    case 3:
      delete();
      break;
    case 4:
      cart();
      break;
    case 5:
      checkout();
      break;
    case 6:
      puts("Thank You for Your Purchase!");
      if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
  } while( true );
}


void insert(int param_1)
{
  undefined1 *local_8;
  
  for (local_8 = myCart; *(int *)(local_8 + 8) != 0; local_8 = *(undefined1 **)(local_8 + 8)) {
  }
  *(int *)(local_8 + 8) = param_1;
  *(undefined1 **)(param_1 + 0xc) = local_8;
  return;
}


void list(void)
{
  puts("=== Device List ===");
  printf("%d: iPhone 6 - $%d\n",1,199);
  printf("%d: iPhone 6 Plus - $%d\n",2,299);
  printf("%d: iPad Air 2 - $%d\n",3,499);
  printf("%d: iPad Mini 3 - $%d\n",4,399);
  printf("%d: iPod Touch - $%d\n",5,199);
  return;
}


void menu(void)
{
  puts("=== Menu ===");
  printf("%d: Apple Store\n",1);
  printf("%d: Add into your shopping cart\n",2);
  printf("%d: Remove from your shopping cart\n",3);
  printf("%d: List your shopping cart\n",4);
  printf("%d: Checkout\n",5);
  printf("%d: Exit\n",6);
  return;
}


void my_read(void *param_1,size_t param_2)
{
  ssize_t sVar1;
  
  sVar1 = read(0,param_1,param_2);
  if (sVar1 == -1) {
    puts("Input Error.");
  }
  else {
    *(undefined *)((int)param_1 + sVar1) = 0;
  }
  return;
}


void timeout(void)

{
  puts("Times Up!");
                    /* WARNING: Subroutine does not return */
  exit(0);
}

