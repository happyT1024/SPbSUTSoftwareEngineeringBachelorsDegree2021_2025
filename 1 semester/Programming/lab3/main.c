#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef double D;
D f(D x,D a){
	return 1.5*(pow(cos((a+x)/(2*a*a+x*x)), 4));
}

int main(){
	D x1,x2,N,a,tx;
	scanf("%lf%lf%lf%lf",&N,&a,&x1,&x2);
	D dx=(x2-x1)/(N-1);
	int i=1;
	for(;x1<=x2;x1+=dx,i++)printf("%2d  %lf\n",i,f(x1,a));
	return 0;
}
