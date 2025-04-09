#include <stdio.h>
extern int a;

void bar();

void main()
{
   a = a+1;
    printf("main:a %d\n",a);
    bar();

    return;
}

/* for the sake of assembly the #include and printf is commented*/
/*riscv64-unknown-elf-gcc -O0 -S auto.c : cmd for converting c code to assembly which uses default 64 bit */