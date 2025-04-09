#include <stdio.h>
int a =10;

static void foo()
{
    a = a+1;
    printf("foo:a %d\n",a);

    return;
}

void bar()
{
    static int b =3;
    b = b+1;
    printf("bar:b %d\n",b);
    foo();
}

//static when declared within the function retains the value from the previous call and the scope in within the function block
//static when declared global, scope is within the file cannot be used in other file, even with extern 