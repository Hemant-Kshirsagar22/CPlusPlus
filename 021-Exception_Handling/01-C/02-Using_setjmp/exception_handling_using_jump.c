#include <stdio.h>
#include <stdbool.h>
#include <setjmp.h>

jmp_buf jbuf;

void g(void)
{
    bool error = true;  // if we make this true it will make jump from line 12 to line no 18 and make jbuf = 1
    printf("g() started\n");
    if(error)
        longjmp(jbuf,1);
    printf("g() ended\n");
    return;
}
int main(void)
{
    if(setjmp(jbuf) == 0)
    {
        printf("g() called\n");
        g();
        printf("g() returned\n");
    }
    else
    {
        printf("g() failed\n");
    }
    
    return(0);
}
