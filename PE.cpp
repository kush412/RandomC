#include <stdio.h>
#include <string.h>
#define MAXN 100

int menu(){
	printf("\n\nEnter an option");
	printf("\n1/ Add shoes (at least 3 pairs)");
	printf("\n2/ Remove a pair of shoes base on code inputted");
	printf("\n3/ Print out the list of shoes with the largest price");
	printf("\n4/ Print out the list of Nike brand shoes with the smallest price");
	printf("\nOthers: Quit");
	printf("\nSelect: ");
	
	int choice;
	scanf("%d", &choice);
	
	return choice;	
}

void add(char codes[][9], char names[][50], char brands[][10], int quantity[], double price[], int *pn){
	int count = 0, index = 1, i;
	do	{
		printf("\nEnter the number of shoes (at least 3): ");
		scanf("%d", &count);
	}
	while (count < 3);
	
	for (i=0; i<count; i++){
		printf("\nEnter information about shoes number %d\n", index);
		
		fflush(stdin);
		printf("\nCode of product: ");
		scanf("%8s", &codes[*pn]);
				
		fflush(stdin);
		printf("\nName of shoes: ");
		scanf("%49[^\n]", &names[*pn]);
		
		fflush(stdin);
		printf("\nBrand of shoes: ");
		scanf("%9[^\n]", &brands[*pn]);
		
		fflush(stdin);
		printf("\nQuantity: ");
		scanf("%d", &quantity[*pn]);
		
		fflush(stdin);
		printf("Price: ");
		scanf("%lf", &price[*pn]);
		
		(*pn)++;
		index++;
	}
}

int removePos(char key[], char codes[][9], char names[][50], char brands[][10], int quantity[], double price[], int *pn){
	int i, index =-1;
	for (i=0; i<*pn; i++)
		if (strcmp(codes[i], key)==0){
			index = i;
			break;
		}
	if (index>=0){
		for (i=index; i<*pn-1; i++){
			
			strcpy(codes[i], codes[i+1]);
			strcpy(names[i], names[i+1]);
			strcpy(brands[i], brands[i+1]);
			quantity[i] = quantity[i+1];
			price[i] = price[i+1];
		}		
		(*pn)--;
	}	
	return index;
}

void swap_string(char a[], char b[]){
	char t[100];
		strcpy(t, a);
		strcpy(a, b);
		strcpy(b, t);
}

void swap_double(double &a, double &b){
	double 	t=a; 
			a=b; 
			b=t;
}

void swap_int(int &a, int &b){
	int t = a;
		a = b;
		b = t;
}

void sortDesc(char codes[][9], char names[][50], char brands[][10], int quantity[], double price[], int n){
	int i, j;
	for (i=0; i<n-1; i++){
		for (j=n-1; j>i; j--)
			if(price[j] > price[j-1]){
				swap_string(codes[j], codes[j-1]);
				swap_string(names[j], names[j-1]);
				swap_string(brands[j], brands[j-1]);
				swap_int(quantity[j], quantity[j-1]);
				swap_double(price[j], price[j-1]);
			}
	}
}

void sortAsc(char codes[][9], char names[][50], char brands[][10], int quantity[], double price[], int n){
	int i, j;
	for (i=0; i<n; i++)
		for(j=n-1; j>i; j--){
			if (price[j] < price[j-1]){
				swap_string(codes[j], codes[j-1]);
				swap_string(names[j], names[j-1]);
				swap_string(brands[j], brands[j-1]);
				swap_int(quantity[j], quantity[j-1]);				
				swap_double(price[j], price[j-1]);
			}
	}
}

void printLargest(char codes[][9], char names[][50], char brands[][10], int quantity[], double price[], int n){
	sortDesc(codes, names, brands, quantity, price, n);
	int i;
	for (i=0; i<n; i++){
		if (price[i] < price[i-1]) break;
			printf("\n%s - ", codes[i]);
			printf("%s - ", names[i]);
			printf("%s - ", brands[i]);
			printf("%d - ", quantity[i]);
			printf("%.2f", price[i]);
	}
}

void printNikeSmallest(char codes[][9], char names[][50], char brands[][10], int quantity[], double price[], int n){
	sortAsc(codes, names, brands, quantity, price, n);
	int i;
	printf("\nCheapest Nike shoes: ");
	for (i=0; i<n; i++){
		if (strcmp(brands[i], "Nike")==0){			
			printf("\n%s - ", codes[i]);
			printf("%s - ", names[i]);
			printf("%d - ", quantity[i]);
			printf("%.2f", price[i]);
		}
		if (price[i] > price[i-1]) break;
	}
}

int main(){
	char codes[MAXN][9], names[MAXN][50], brands[MAXN][10];;
	int quantity[MAXN];
	double price[MAXN];
	int userChoice;
	int n=0;
	int result_delete = -1;
	char code_delete[9];
	
	do {
		userChoice = menu();
		switch(userChoice){
			case 1:
				add(codes, names, brands, quantity, price, &n);
				break;
			case 2:
				fflush(stdin);
				printf("\nEnter the removing code: ");
				scanf("%8s", &code_delete);
				result_delete = removePos(code_delete, codes, names, brands, quantity, price, &n);
				if (result_delete >= 0)
					printf("\nREMOVED!");
				else
					printf("\nCOULD NOT REMOVE!");
				break;
			case 3:
				fflush(stdin);
				printLargest(codes, names, brands, quantity, price, n);
				break;
			case 4:
				fflush(stdin);
				printNikeSmallest(codes, names, brands, quantity, price, n);
				break;
			default: printf("\nGOODBYE!\n");
		}
	}
	while (userChoice>0 && userChoice<5);
	getchar();
	return 0;
}


