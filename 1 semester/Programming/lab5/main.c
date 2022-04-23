#include<stdio.h>
#include<math.h>

int main(){
	int x,m,n;
	scanf("%d%d%d",&x,&m,&n);
	double ans=0;
    double buf2=0;
    for(int i=1;i<=m;++i){
			buf2+=1/((double)i);
    }
    buf2*=x;
	for(int j=1;j<=n;++j){
		double buf1=0;
		buf1+=j*x;
		for(int k=1;k<=m;++k){
			buf1+=k/((double)j)+j/((double)k);
		}
		ans+=buf1/(buf2+2*j);
	}
	printf("%lf\n",ans);
	return 0;
}
