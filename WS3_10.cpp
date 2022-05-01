#include <stdio.h>

void printMinMaxDigits (int n);

int main(){
	int n;
	do{
		printf("Enter a nonnegative integer: ");
		scanf("%d", &n);
		printMinMaxDigits(n);
	}
	while (n<0);
	getchar();
	return 0;
}

void printMinMaxDigits (int n){
	int digit;
	int min, max;
	
	digit= n%10;
	n= n/10;
	min=max=digit;
	while (n>0){
		digit= n%10;
		n= n/10;
		if (min > digit) min = digit;
		if (max < digit) max = digit;
	}
	printf("The maximum digit is: %d", max);
	printf("\nThe minimum digit is: %d", min);
}
