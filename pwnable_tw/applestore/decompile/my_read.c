
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

