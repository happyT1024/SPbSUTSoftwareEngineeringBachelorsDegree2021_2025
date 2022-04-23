#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f1(int k);
double f2(int k);

double getAnsWithFor(double x, int n);
double getAnsWithWhile(double x, int n);
double getAnsWithDoWhile(double x, int n);

void clear();
void write();
void printMenu();
void printAnswer(double ans);
void get(double * x,int * n);

// 25 0.35
int main(){
    write();
	double x;
	int n;
	while(1){
        int userAnswer;
        printMenu();
        scanf("%d",&userAnswer);
        switch (userAnswer) {
        case 0:
            return 0;
        case 1:
            get(&x,&n);
            write();
            printAnswer(getAnsWithFor(x,n));
            break;
        case 2:
            get(&x,&n);
            write();
            printAnswer(getAnsWithWhile(x,n));
            break;
        case 3:
            get(&x,&n);
            write();
            printAnswer(getAnsWithDoWhile(x,n));
            break;
        default:
            printf("Try again!\n");
        }
	}
	return 0;
}

void get(double * x,int * n){
    printf("Enter x and n: ");
    scanf("%d%lf",n,x);
}

void printAnswer(double ans){
    printf("Answer: %lf\n",ans);
    printf("\n");
}

void printMenu(){
    printf("1 - FOR\n");
    printf("2 - WHILE\n");
    printf("3 - DO_WHILE\n");
    printf("0 - EXIT\n");
    printf("> ");
}

void clear(){
    system("clear");
}

void write(){
    clear();
    system("figlet -cf slant Laba 4 | lolcat");
    printf("                       --------------------------------\n");
    printf("                       --      Sumenkov Matvey       --\n");
    printf("                       --         19.10.2021         --\n");
    printf("                       --------------------------------\n");
}

double getAnsWithFor(double x, int n){
    double ans=0,s=0;
    int k;
    ans+=3*x;
	for(k=1;k<=n;++k){
		ans+=f1(k);
	}
	for(k=1;k<=n;++k){
		s+=f2(k);
	}
	s*=s;
	ans+=s;
	return ans;
}
double getAnsWithWhile(double x, int n){
    double ans=0,s=0;
    int k;
    ans+=3*x;
    k=1;
	while(k<=n){
		ans+=f1(k);
		k++;
	}
	k=1;
	while(k<=n){
		s+=f2(k);
		k++;
	}
	s*=s;
	ans+=s;
	return ans;
}
double getAnsWithDoWhile(double x, int n){
    double ans=0,s=0;
    int k;
    ans+=3*x;
    k=1;
	do{
        if(k>n)break;
		ans+=f1(k);
		k++;
	}while(k<=n);
	k=1;
	do{
        if(k>n)break;
		s+=f2(k);
		k++;
	}while(k<=n);
	s*=s;
	ans+=s;
	return ans;
}

double f1(int k){
	return 1/((double)k*k);
}
double f2(int k){
	return (1/k)*(pow(-1,k+1));
}
