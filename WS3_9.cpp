#include <stdio.h>

int gcd (int a, int b);
int lcm (int a, int b);

int main(){
	int a, b;
	int d;
	int m;
	do{
		printf("Enter two positive integers: ");
		scanf("%d %d", &a, &b);
	}
	while (a<=0 || b<=0);
	d= gcd(a, b);
	m= lcm(a, b);
	printf("\nGreatest common divisor of %d and %d is: %d", a, b, d);
	printf("\nLeast common multiple of %d and %d is: %d", a, b, m);
	getchar();
	return 0;
}

int gcd (int a, int b){
	while (a != b)
	if (a>b)  a-=b;
	else b-=a;
	return a;
}

int lcm (int a, int b){
	return a*b/ gcd(a, b);
}

