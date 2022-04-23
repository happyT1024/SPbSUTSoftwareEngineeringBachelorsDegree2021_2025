#include<stdio.h>
#include<math.h>


double f(int begin, int end, int a, int b){
	double ans=0;
	for(int j = begin;j<=end;++j){
		ans+=a*pow(j,3)+2*pow(j,2)+b;
	}
	return ans;
}


int main(){
	int m, n;
	double y=0;
	scanf("%d%d",&m,&n);
	y=1+f(1, m, 1, 3);
	y/=2+f(3, n, 0, -1);
	printf("%lf\n",y);
	return 0;
}

