#include <stdio.h>

double factorial (int n);

int main(){
	int n;
	printf("Enter a positive integer: ");
	do{
		scanf("%d", &n);
	}
	while (n<1);
	printf("The factorial %d!= %lf", n, factorial(n));
	getchar();
	return 0;
	
}

double factorial (int n){
	double p=1;
	int i;
	for (i=2; i<=n; i++)
		p*=i;
	return p;
}

