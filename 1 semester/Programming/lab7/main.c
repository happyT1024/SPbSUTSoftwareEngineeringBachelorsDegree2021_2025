#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "lib.h"

int main()
{
    int n=getSize();
    double *a,*b,*c,*x,*y;
    double max_a,max_b,max_c;
    a=getArray(n,&max_a);
    b=getArray(n,&max_b);
    c=getArray(n,&max_c);
    x=initArray(a,b,n,max_a,max_b);
    y=initArray(b,c,n,max_b,max_c);
    printf("1 последовательность:\n");
    for(double *i=x;i!=&x[n];i++)printf("%lf  ",*i);
    printf("\n2 последовательность:\n");
    for(double *i=y;i!=&y[n];i++)printf("%lf  ",*i);
    printf("\n");
    return 0;
}
