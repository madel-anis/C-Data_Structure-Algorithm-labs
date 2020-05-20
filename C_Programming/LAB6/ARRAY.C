#include <stdio.h>

#define ARR_SIZE 10

void Scan(int *Arr, int Size);
void Print(int *Arr , int Size);

void main()
{
	int Arr[ARR_SIZE]={0};

	clrscr();
	Scan(Arr,ARR_SIZE);
	Print(Arr,ARR_SIZE);

	getch();

}
void Scan(int *Arr, int Size)
{
	int i;

	clrscr();

	printf("Please Enter the %d elements of the Array:",Size);
	for(i=0 ; i<Size ; i++)
	{
		printf("\nEnter the %d element:",i+1);
		scanf("%d",Arr+i);
	}
	printf("\n");
}

void Print(int *Arr, int Size)
{
	int i;

	clrscr();

	printf("The %d elements of the Array:",Size);
	for(i=0 ; i<Size ; i++)
	{
		printf("\nthe %d element:",i+1);
		printf("%d",*(Arr+i));
	}
}