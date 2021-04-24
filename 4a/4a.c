#include<stdio.h>
#include<setjmp.h>

jmp_buf buf;

void func()
{
    printf("example program\n");
    longjmp(buf, 1);
    printf("Exit from setjmp and longjmp\n");
}

int main()
{
    if (setjmp(buf))
        printf("setjmp called\n");
    else
    {
        printf("longjmp called\n");
        func();
    }
    return 0;
}