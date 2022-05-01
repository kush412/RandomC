#include <stdio.h>

int validDate (int d, int m, int y);

int main(){
	int d, m, y;
	printf("Enter day: ");
	scanf("%d", &d);
	fflush(stdin);
	printf("\nEnter month: ");
	scanf("%d", &m);
	fflush(stdin);
	printf("\nEnter year: ");
	scanf("%d", &y);
	if(validDate(d, m, y)==1) {
		printf("Date %d/%d/%d is valid.", d, m, y);}
	else 
		printf("Date %d/%d/%d is not valid.", d, m, y);
	
	getchar();
	return 0;
}

int validDate (int d, int m, int y){
	int maxd = 31;
	if(d<1||d>31||m<1||m>12) return 0;
	if (m==4 || m==6 || m==9 || m== 11) maxd=30;
	else if (m==2) {
		if(y%400==0|| (y%4==0 && y%100!=0)) maxd=29;
		else maxd= 28;
	}
	return d<=maxd;
}
