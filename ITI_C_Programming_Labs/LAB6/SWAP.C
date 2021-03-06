#include <stdio.h>

void Swap(int * First, int *Second);

void main()
{
	int x=5;
	int y=6;

	clrscr();

	printf("Before Swapping\n");
	printf("The value of x = %d\n",x);
	printf("The value of y = %d\n",y);
	Swap(&x,&y);
	printf("After Swapping\n");
	printf("The value of x = %d\n",x);
	printf("The value of y = %d\n",y);
	getch();
}

void Swap(int *First,int * Second)
{
   *First = *First + *Second;
   *Second = *First - *Second;
   *First = *First - *Second;
}