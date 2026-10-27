// FemboyBuilder.Windows.exe - Complete reconstructed source
// Decompiled via Ghidra 12.1.4

#include <windows.h>

// Entry point
void entry(void)
{
  code *pcVar1;
  
  FUN_00401011();
  RtlExitUserProcess(0);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

// ChaCha20-like round function
void FUN_00404061(longlong param_1, longlong param_2, longlong param_3, longlong param_4, longlong param_5)
{
  uint uVar1;
  
  uVar1 = *(int *)(param_1 + param_3 * 4) + *(int *)(param_1 + param_2 * 4);
  *(uint *)(param_1 + param_2 * 4) = uVar1;
  uVar1 = uVar1 ^ *(uint *)(param_1 + param_5 * 4);
  uVar1 = uVar1 << 0x10 | uVar1 >> 0x10;
  *(uint *)(param_1 + param_5 * 4) = uVar1;
  uVar1 = uVar1 + *(int *)(param_1 + param_4 * 4);
  *(uint *)(param_1 + param_4 * 4) = uVar1;
  uVar1 = uVar1 ^ *(uint *)(param_1 + param_3 * 4);
  uVar1 = uVar1 << 0xc | uVar1 >> 0x14;
  *(uint *)(param_1 + param_3 * 4) = uVar1;
  uVar1 = uVar1 + *(int *)(param_1 + param_2 * 4);
  *(uint *)(param_1 + param_2 * 4) = uVar1;
  uVar1 = uVar1 ^ *(uint *)(param_1 + param_5 * 4);
  uVar1 = uVar1 << 8 | uVar1 >> 0x18;
  *(uint *)(param_1 + param_5 * 4) = uVar1;
  uVar1 = uVar1 + *(int *)(param_1 + param_4 * 4);
  *(uint *)(param_1 + param_4 * 4) = uVar1;
  uVar1 = uVar1 ^ *(uint *)(param_1 + param_3 * 4);
  *(uint *)(param_1 + param_3 * 4) = uVar1 << 7 | uVar1 >> 0x19;
  return;
}

// Memory loader callback
ulonglong * FUN_00404201(ulonglong *param_1, longlong *param_2, longlong param_3, ulonglong param_4)
{
  longlong *plVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  plVar1 = (longlong *)*param_2;
  lVar2 = plVar1[2];
  uVar3 = plVar1[1] - lVar2;
  if (param_4 < (ulonglong)(plVar1[1] - lVar2)) {
    uVar3 = param_4;
  }
  FUN_00405064(param_3, lVar2 + *plVar1, uVar3);
  plVar1[2] = uVar3 + lVar2;
  *param_1 = uVar3;
  *(undefined2 *)(param_1 + 1) = 0;
  return param_1;
}

// Stack alignment helper
ulonglong FUN_00405034(void)
{
  ulonglong in_RAX;
  ulonglong uVar1;
  
  uVar1 = in_RAX;
  if (0xfff < in_RAX) {
    do {
      uVar1 = uVar1 - 0x1000;
    } while (0x1000 < uVar1);
  }
  return in_RAX;
}

// Resource loader
longlong * FUN_00401814(longlong *param_1, undefined8 *param_2, longlong param_3)
{
  longlong lVar1;
  longlong *plVar2;
  undefined8 unaff_retaddr;
  longlong local_48 [2];
  undefined2 local_38;
  longlong local_30;
  longlong local_28;
  undefined2 local_20;
  
  if (param_3 == 0) {
    local_30 = -1;
  }
  else {
    local_30 = (**(code **)param_2[1])(*param_2, param_3, 0, unaff_retaddr);
    if (local_30 == 0) {
      plVar2 = local_48;
      local_38 = 1;
      goto LAB_00401869;
    }
  }
  plVar2 = &local_30;
  local_20 = 0;
  local_28 = param_3;
LAB_00401869:
  param_1[2] = plVar2[2];
  lVar1 = plVar2[1];
  *param_1 = *plVar2;
  param_1[1] = lVar1;
  return param_1;
}
