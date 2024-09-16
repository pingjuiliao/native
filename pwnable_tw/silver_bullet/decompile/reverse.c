
undefined4 beat(char *param_1,int *param_2)
{
  undefined4 uVar1;
  
  if (*param_1 == '\0') {
    puts("You need create the bullet first !");
    uVar1 = 0;
  }
  else {
    puts(">----------- Werewolf -----------<");
    printf(" + NAME : %s\n",param_2[1]);
    printf(" + HP : %d\n",*param_2);
    puts(">--------------------------------<");
    puts("Try to beat it .....");
    usleep(1000000);
    *param_2 = *param_2 - *(int *)(param_1 + 0x30);
    if (*param_2 < 1) {
      puts("Oh ! You win !!");
      uVar1 = 1;
    }
    else {
      puts("Sorry ... It still alive !!");
      uVar1 = 0;
    }
  }
  return uVar1;
}


void create_bullet(char *param_1)
{
  size_t sVar1;
  
  if (*param_1 == '\0') {
    printf("Give me your description of bullet :",0);
    read_input(param_1,0x30);
    sVar1 = strlen(param_1);
    printf("Your power is : %u\n",sVar1);
    *(size_t *)(param_1 + 0x30) = sVar1;
    puts("Good luck !!");
  }
  else {
    puts("You have been created the Bullet !");
  }
  return;
}


undefined4 main(void)
{
  int iVar1;
  undefined4 local_40;
  undefined *local_3c;
  undefined local_38 [48]; // ebp - 0x34
  undefined4 local_8; // ebp - 4
  
  init_proc();
  local_8 = 0;
  memset(local_38,0,0x30);
  local_40 = 0x7fffffff;
  local_3c = &DAT_08048d06;
  do {
    while( true ) {
      while( true ) {
        menu();
        iVar1 = read_int();
        if (iVar1 != 2) break;
        power_up(local_38);
      }
      if (2 < iVar1) break;
      if (iVar1 == 1) {
        create_bullet(local_38);
      }
      else {
LAB_08048a05:
        puts("Invalid choice");
      }
    }
    if (iVar1 != 3) {
      if (iVar1 == 4) {
        puts("Don\'t give up !");
                    /* WARNING: Subroutine does not return */
        exit(0);
      }
      goto LAB_08048a05;
    }
    iVar1 = beat(local_38,&local_40);
    if (iVar1 != 0) {
      return 0;
    }
    puts("Give me more power !!");
  } while( true );
}


void menu(void)

{
  puts("+++++++++++++++++++++++++++");
  puts("       Silver Bullet       ");
  puts("+++++++++++++++++++++++++++");
  puts(" 1. Create a Silver Bullet ");
  puts(" 2. Power up Silver Bullet ");
  puts(" 3. Beat the Werewolf      ");
  puts(" 4. Return                 ");
  puts("+++++++++++++++++++++++++++");
  printf("Your choice :");
  return;
}


void power_up(char *param_1)

{
  size_t sVar1;
  char local_38 [48];
  int local_8;
  
  local_8 = 0;
  memset(local_38,0,0x30);
  if (*param_1 == '\0') {
    puts("You need create the bullet first !");
  }
  else if (*(uint *)(param_1 + 0x30) < 0x30) {
    printf("Give me your another description of bullet :");
    read_input(local_38,0x30 - *(int *)(param_1 + 0x30));
    strncat(param_1,local_38,0x30 - *(int *)(param_1 + 0x30));
    sVar1 = strlen(local_38);
    local_8 = *(int *)(param_1 + 0x30) + sVar1;
    printf("Your new power is : %u\n",local_8);
    *(int *)(param_1 + 0x30) = local_8;
    puts("Enjoy it !");
  }
  else {
    puts("You can\'t power up any more !");
  }
  return;
}


ssize_t read_input(void *param_1,size_t param_2)

{
  ssize_t sVar1;
  
  sVar1 = read(0,param_1,param_2);
  if (sVar1 < 1) {
    puts("read error");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  if (*(char *)((int)param_1 + sVar1 + -1) == '\n') {
    *(undefined *)((int)param_1 + sVar1 + -1) = 0;
  }
  return sVar1;
}


int read_int(void)

{
  int iVar1;
  char local_1c [20];
  ssize_t local_8;
  
  local_8 = read(0,local_1c,0xf);
  if (local_8 < 1) {
    puts("read error");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  iVar1 = atoi(local_1c);
  return iVar1;
}

