#include <stdio.h>

int sumDigits(int n);

int main(){
	int n;
	int S= 0;
	do{
		printf("Enter a nonnegative integer: ");
		scanf("%d", &n);
		if (n>=0){
			S= sumDigits(n);
			printf("Sum of its decimal digits: %d\n", S);
		}
	}
	while (n>=0);
	
	getchar();
	return 0;
}

int sumDigits(int n){
	int sum=0;
	do{
		int remainder= n%10;
		n= n/10;
		sum += remainder;
	}
	while (n>0);
	return sum;
}
