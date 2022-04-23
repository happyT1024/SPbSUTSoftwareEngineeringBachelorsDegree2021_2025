#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define print(a) {printf("%0.5lf\n",a);return 0;}

int main(){
	double x;
	scanf("%lf",&x);
	if(x>10)print(x*x*x)	
	if(x>3)print(2*x)
	if(x>-5)print(0.5*x)
	print(cbrt(abs(x+2)))
}

