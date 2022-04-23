#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

int getSize();
double * getArray(int n,double *MAX);
double * initArray(double * a,double * b,int n,double max_a, double max_b);

int getSize(){
    int n;
    printf("Введите размер массива:\n");
    scanf("%d",&n);
    return n;
}

double * getArray(int n,double *MAX){
    printf("Введите %d чисел:\n",n);
    double *a;
    *MAX=-9999999;
    a=(double*)malloc(n * sizeof(double));
    for(double * i=a;i!=&a[n];i++){
        scanf("%lf",i);
        if(*i>*MAX){
            *MAX=*i;
        }
    }
    return a;
}

double * initArray(double * a,double * b,int n,double max_a, double max_b){
    double *c=(double*)malloc(n*sizeof(double));
    for(double *i=a,*j=b,*k=c;i!=&a[n];i++,j++,k++){
        *k=(max_a+max_b)-(*i+*j)/2;
    }
    return c;
}

#endif // LIB_H_INCLUDED
