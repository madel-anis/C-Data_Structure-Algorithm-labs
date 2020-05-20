#include <stdio.h>

#define SIZE 5

void Swap(int *First , int *Second);
void Selection_Sort(int* Arr , int Size);
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

	Selection_Sort(Arr , SIZE);

	printf("\nThe Sorted Array is \n");
	for(i=0 ; i<SIZE ; i++)
	{
		printf("%d\n",Arr[i]);
	}

	getch();
}

void Selection_Sort(int* Arr , int Size)
{
	int Min;
	int i,j;

	for(i=0 ; i<Size-1 ; i++)
	{
		Min = i;
		for(j=i+1 ; j<Size ; j++)
		{
			if(Arr[j] < Arr[Min])
			{
				Min = j;
			}
		}
		if( Min != i)
		{
			Swap(&Arr[Min] , &Arr[i]);
		}
	}
}
void Swap(int *First , int *Second)
{
	*First = *First ^ *Second;
	*Second = *Second ^ *First;
	*First = *First ^ *Second;
}