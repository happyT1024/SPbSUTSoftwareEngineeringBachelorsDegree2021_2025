#include<stdio.h>
#include<math.h>

double f1(int m){
	double ans=0;
	for(int j = 1;j<=m;++j){
		ans+=pow(j,3)+2*pow(j,2)+3;
	}
	return ans;
}


double f2(int m){
	double ans=0;
	for(int k = 3;k<=m;++k){
		ans+=2*pow(k,2)-1;
	}
	return ans;
}


int main(){
	int m, n;
	double y=0;
	scanf("%d%d",&m,&n);
	y=1+f1(m);
	y/=2+f2(n);
	printf("%lf\n",y);
	return 0;
}
