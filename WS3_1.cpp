#include <stdio.h>
#include <math.h>

int prime(int n);

int main(){
	int n;
	int i;
	printf("Enter an integer: ");
	do{
		scanf("%d", &n);
	}
	while (n<2);
	printf("Primes between 2 and %d: ", n);
	for (i=2; i<=n; i++)
		if(prime(i)==1)
			printf("\t%d ",i);
	getchar();
	return 0;
}

int prime(int n){
	int m= sqrt(n);
	int i;
	if (n<2) return 0;
	for (i=2; i<=m; i++)
		if(n%i==0) return 0;
	return 1;
}
