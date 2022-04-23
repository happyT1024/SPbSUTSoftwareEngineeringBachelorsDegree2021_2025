#include<stdio.h>
#include<math.h>

void f1(int m, double * ans){
	*ans=0;
	for(int j = 1;j<=m;++j){
		*ans+=pow(j,3)+2*pow(j,2)+3;
	}
}


void f2(int m, double * ans){
	*ans=0;
        for(int k = 3;k<=m;++k){
		*ans+=2*pow(k,2)-1;
	}
}


int main(){
        int m, n;
        double y=0;
        scanf("%d%d",&m,&n);
	double ans1,ans2;
	f1(m,&ans1),f2(n,&ans2);
        y=1+ans1;
        y/=2+ans2;
        printf("%lf\n",y);
        return 0;
}

