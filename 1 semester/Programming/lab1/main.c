#include<stdio.h>
#include<math.h>

int main(){
	float x, a, b, y, z, buf;
	//printf("Введите x, a, b:\n> ");
	scanf("%f %f %f", &x, &a, &b);
	y = (x - 7) / (log(x - 2.0) + 2);
	printf("Y == %0.3f\n", y);
	buf=sqrt(sqrt(a * y * y + 3));
	z = (buf + 2) / (buf + b);
	printf("Z == %0.3f\n", z);
	return 0;
}






