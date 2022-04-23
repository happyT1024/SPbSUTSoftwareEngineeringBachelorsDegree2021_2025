#include<stdio.h>
#include<math.h>


void f(int begin, int end, int a, int b, double * ans){
	*ans=0;
	for(int j = begin;j<=end;++j){
		*ans+=a*pow(j,3)+2*pow(j,2)+b;
	}
}


int main(){
	int m, n;
	double y=0;
	scanf("%d%d",&m,&n);
    double buf=0;
	f(1, m, 1, 3, &buf);
    y+=1+buf;
    f(3, n, 0, -1, &buf);
	y/=2+buf;
	printf("%lf\n",y);
	return 0;
}


