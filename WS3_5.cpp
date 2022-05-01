#include <stdio.h>

double fibo (int n);

int main(){
	int n;
	printf("Enter n: ");
	do{
		printf("Enter n: ");
		scanf("%d", &n);
	}
	while (n<1);
	printf("The value at the %d position in Fibonacci sequence: %lf", n, fibo(n));
	getchar();
	return 0;
}

double fibo (int n){
	int t1=1, t2=1, f=1, i;
	for (i=3; i<=n; i++){
		f= t1+t2;
		t1=t2;
		t2=f;
	}
	return f;
}
