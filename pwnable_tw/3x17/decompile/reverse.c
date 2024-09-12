
// The main function: 
// allow an aribtrary write
char FUN_00401b6d(void)
{
  char cVar1;
  int iVar2;
  long in_FS_OFFSET;
  undefined local_28 [24];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  DAT_004b9330 = DAT_004b9330 + '\x01'; // VULN: it's an integer overflow
                                        // it will cycle every 256 times
  cVar1 = DAT_004b9330;
  if (DAT_004b9330 == '\x01') {
    FUN_00446ec0(1,"addr:",5);
    FUN_00446e20(0,local_28,0x18);
    iVar2 = FUN_0040ee70(local_28);
    FUN_00446ec0(1,"data:",5);
    FUN_00446e20(0,(long)iVar2,0x18);
    cVar1 = '\0';
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    FUN_0044a3e0();
  }
  return cVar1;
}


void FUN_00402960(void)

{
  long lVar1;
  
  lVar1 = 1;
  do {
    (*(code *)(&PTR_FUN_004b40f0)[lVar1])(); // 0x402988
    lVar1 = lVar1 + -1;
  } while (lVar1 != -1);
  FUN_0048e32c();
  return;
}


/* WARNING: Removing unreachable block (ram,0x0040f6e0) */
/* WARNING: Removing unreachable block (ram,0x0040f92a) */

void FUN_0040f6c0(undefined4 param_1,long **param_2,char param_3)

{
  long *plVar1;
  long lVar2;
  long *plVar3;
  long lVar4;
  int iVar5;
  long extraout_RDX;
  long lVar6;
  undefined **ppuVar7;
  long in_FS_OFFSET;
  bool bVar8;
  
  iVar5 = DAT_004ba7f0;
LAB_0040f6f0:
  DAT_004ba7f0 = iVar5;
  if (DAT_004ba80c == 0) {
    if (DAT_004ba7f0 == 0) {
      DAT_004ba7f0 = 1;
      goto LAB_0040f72c;
    }
  }
  else {
    LOCK();
    bVar8 = DAT_004ba7f0 == 0;
    if (bVar8) {
      DAT_004ba7f0 = 1;
    }
    UNLOCK();
    if (bVar8) goto LAB_0040f72c;
  }
  FUN_0044a2c0(&DAT_004ba7f0);
LAB_0040f72c:
  do {
    plVar1 = *param_2;
    if (plVar1 == (long *)0x0) {
      DAT_004b98d4 = 1;
      if (DAT_004ba80c != 0) {
        LOCK();
        UNLOCK();
      }
      iVar5 = DAT_004ba7f0 + -1;
      if (DAT_004ba7f0 + -1 != 0) {
        DAT_004ba7f0 = DAT_004ba7f0 + -1;
        FUN_0044a2f0(&DAT_004ba7f0);
        iVar5 = DAT_004ba7f0;
      }
      DAT_004ba7f0 = iVar5;
      if (param_3 != '\0') {
        ppuVar7 = &PTR_FUN_004b92c8;
        do {
          (*(code *)*ppuVar7)();
          ppuVar7 = (code **)ppuVar7 + 1;
        } while (ppuVar7 != (undefined **)&DAT_004b92d0);
      }
                    /* WARNING: Subroutine does not return */
      FUN_00446680(param_1);
    }
    do {
      lVar4 = DAT_004ba7f8;
      if (plVar1[1] == 0) {
        plVar3 = (long *)*plVar1;
        *param_2 = plVar3;
        if (plVar3 != (long *)0x0) {
          FUN_0041f320(plVar1);
        }
        if (DAT_004ba80c != 0) {
          LOCK();
          UNLOCK();
        }
        iVar5 = DAT_004ba7f0 + -1;
        if (DAT_004ba7f0 + -1 != 0) {
          DAT_004ba7f0 = DAT_004ba7f0 + -1;
          FUN_0044a2f0(&DAT_004ba7f0);
          iVar5 = DAT_004ba7f0;
        }
        goto LAB_0040f6f0;
      }
      lVar6 = plVar1[1] + -1;
      plVar1[1] = lVar6;
      if (DAT_004ba80c != 0) {
        LOCK();
        UNLOCK();
      }
      iVar5 = DAT_004ba7f0 + -1;
      if (DAT_004ba7f0 + -1 != 0) {
        DAT_004ba7f0 = DAT_004ba7f0 + -1;
        FUN_0044a2f0(&DAT_004ba7f0);
        lVar6 = extraout_RDX;
        iVar5 = DAT_004ba7f0;
      }
      DAT_004ba7f0 = iVar5;
      lVar2 = plVar1[lVar6 * 4 + 2];
      if (lVar2 == 3) {
        (*(code *)(((ulong)plVar1[lVar6 * 4 + 3] >> 0x11 | plVar1[lVar6 * 4 + 3] << 0x2f) ^
                  *(ulong *)(in_FS_OFFSET + 0x30)))();
      }
      else if (lVar2 == 4) {
        plVar1[lVar6 * 4 + 2] = 0;
        (*(code *)(((ulong)plVar1[lVar6 * 4 + 3] >> 0x11 | plVar1[lVar6 * 4 + 3] << 0x2f) ^
                  *(ulong *)(in_FS_OFFSET + 0x30)))(plVar1[lVar6 * 4 + 4],param_1);
      }
      else if (lVar2 == 2) {
        (*(code *)(((ulong)plVar1[lVar6 * 4 + 3] >> 0x11 | plVar1[lVar6 * 4 + 3] << 0x2f) ^
                  *(ulong *)(in_FS_OFFSET + 0x30)))(param_1,plVar1[lVar6 * 4 + 4]);
      }
      if (DAT_004ba80c == 0) {
        if (DAT_004ba7f0 != 0) goto LAB_0040f76c;
        DAT_004ba7f0 = 1;
      }
      else {
        LOCK();
        bVar8 = DAT_004ba7f0 == 0;
        if (bVar8) {
          DAT_004ba7f0 = 1;
        }
        UNLOCK();
        if (!bVar8) {
LAB_0040f76c:
          FUN_0044a2c0(&DAT_004ba7f0);
        }
      }
    } while (DAT_004ba7f8 == lVar4);
  } while( true );
}

