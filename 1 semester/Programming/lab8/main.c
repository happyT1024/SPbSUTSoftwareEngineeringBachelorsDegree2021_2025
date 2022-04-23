#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void in(double **a,int n,int m);
double * sum(double **a,int n,int m);
int getMinPos(double *a,int n);
int getMaxPos(double *a,int n);
void out(double **a,int pos,int m);

int main()
{
    double **a;
    int n,m;
    printf("Введите N, M: ");
    scanf("%d%d",&n,&m);
    a=(double**)malloc(n*m*sizeof(double)+n*sizeof(double*));
    double *prt=(double*)(a+n);
    for(int i=0;i!=n;i++)a[i]=(prt+m*i);
    in(a,n,m);
    double *s=sum(a,n,m);
    printf("Максимум\n");
    out(a,getMaxPos(s,n),m);
    printf("Минимум\n");
    out(a,getMinPos(s,n),m);
    return 0;
}


void in(double **a,int n,int m){
    printf("Введите %d чисел\n",n*m);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%lf",&a[i][j]);
        }
    }
}

double * sum(double **a,int n,int m){
    double *ans=(double*)malloc(sizeof(double)*n);
    for(double *i=ans;i!=ans+n;i++)*i=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            ans[i]+=a[i][j];
        }
    }
    return ans;
}

int getMinPos(double *a,int n){
    double ans=999999.0;
    int pos=-1;
    for(int i=0;i<n;i++){
        if(ans>a[i]){
            ans=a[i];
            pos=i;
        }
    }
    return pos;
}

int getMaxPos(double *a,int n){
    double ans=-999999.0;
    int pos=-1;
    for(int i=0;i<n;i++){
        if(ans<a[i]){
            ans=a[i];
            pos=i;
        }
    }
    return pos;
}

void out(double **a,int pos,int m){
	double s=0;
    for(int j=0;j<m;j++){
	s+=a[pos][j];
        printf("%lf ",a[pos][j]);
    }
    printf("\n%lf",s);
    printf("\n");
}
