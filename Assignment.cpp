#include <stdio.h>
#include <stdlib.h>
#define MAXN 10

void input (int *a, int n){
	int i;
	for (i=0; i<n; i++)
		scanf("%d", &a[i]);	
}

void printDesc (int *a, int n){
	int *b = (int*)calloc(n, sizeof(int));
	int i, j;
	for (i=0; i<n; i++)
		b[i] = a[i];
	int temp;
	for (i=0; i<n-1; i++)
		for (j=n-1; j>i; j--)
			if(b[j] > b[j-1]){
				temp=b[j];
				b[j]=b[j-1];
				b[j-1]=temp;
			}
	for (i=0; i<n; i++) 
		printf("%d\t", b[i]);
		free(b);
}

int sumEven (int *a, int n){
	int i;
	int S = 0;
	for (i=0; i<n; i++)
		if (a[i]%2==0 && a[i]>0) S += a[i];
	return S;		
}

void primeNumbers(int *a, int n){
	int i;
	int x;
	for (i=0; i<n; i++){
		int result = 1;
		for (x=2; x<a[i]; x++){
			if (a[i]%x==0){ 
				result = 0;
			}
		}
	
			if (result == 1 && a[i] > 1) printf("%d ", a[i]);
	}	
}

void appearOnce (int *a, int n){
	int i;
	int j;
	for (i=0; i<n; i++){
		for (j=0; j<n; j++)
			if (a[i]==a[j] && i!=j) break;
			if (j==n)
			printf("%d ", a[i]);
		}
}

int main(){
	int a[MAXN];
	int n;
	int S;
	do {
		printf("Declare number of elements in array (from 1 to 10): ");
		scanf("%d", &n);
	}
	while (n<1 || n>MAXN);
	printf("\nEnter %d integer: ", n);
	input(a, n);
	printf("\nArray in descending order: ");
	printDesc(a, n);
	S = sumEven(a, n);
	printf("\nSum of all even numbers in array: %d", S);
	printf("\nAll prime numbers in array: ");
	primeNumbers(a, n);
	printf("\nElements that appear once: ");
	appearOnce(a, n);
	getchar();
	return 0;	
}

