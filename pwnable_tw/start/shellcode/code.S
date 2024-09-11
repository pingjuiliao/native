.globl main
.type main, @function

main:
  xor %ecx, %ecx;
  xor %edx, %edx;
  push %edx;
  push $0x68732f6e;
  push $0x69622f2f;
  mov %esp, %ebx;
  mov $0xb, %eax;
  int $0x80;
