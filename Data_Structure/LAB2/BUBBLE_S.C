#include <stdio.h>

#define SIZE 5

void Swap(int * First , int *Second);
void Bubble_Sort(int* Arr , int Size);
void main()
{

	int i;
	int Arr[SIZE]={0};

	clrscr();

	for(i=0 ; i<SIZE ; i++)
	{
		printf("please Enter %d element of Array: ",i+1);
		scanf("%d",&Arr[i]);
	}

	Bubble_Sort(Arr , SIZE);

	printf("\nThe Sorted Array is \n");
	for(i=0 ; i<SIZE ; i++)
	{
		printf("%d\n",Arr[i]);
	}

	getch();
}

void Bubble_Sort(int* Arr , int Size)
{
	int i,j;
	int Sorted = 0;

	for(i=0 ; (i<Size-1) ; i++)
	{
		for(j=i ; (j<Size-1)  ; j++)
		{
			if(Arr[j] > Arr[j+1])
			{
			   Swap(&Arr[j] , &Arr[j+1]);
			   Sorted = 0;
			}
		}
	}
}

void Swap(int *First , int *Second)
{
	*First = *First ^ *Second;
	*Second = *Second ^ *First;
	*First = *First ^ *Second;
}