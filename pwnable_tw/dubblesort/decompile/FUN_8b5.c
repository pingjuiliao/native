
/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000108b5(void)

{
  int iVar1;
  int in_GS_OFFSET;
  
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  setvbuf(_stdout,(char *)0x0,2,0);
  signal(0xe,FUN_00010880);
  alarm(0x3c);
  if (iVar1 != *(int *)(in_GS_OFFSET + 0x14)) {
    FUN_00010ba0();
  }
  return;
}

