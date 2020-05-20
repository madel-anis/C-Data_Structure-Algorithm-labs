#include <stdio.h>

#define Size 5

void main()
{
	int Arr[Size]={0};
	int i;

	clrscr();
	printf("Please enter %d numbers\n",Size);
	for(i=0; i<Size ; i++)
	{
		printf("The %d element of the array: ",i+1);
		scanf("%d",&Arr[i]);
		printf("\n");

	}
	printf("the elements of the array are:\t ");
	for(i=0; i<Size ;i++)
	{
		printf("%d\t",Arr[i]);
	}
getch();
}