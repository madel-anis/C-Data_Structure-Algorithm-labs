#include <stdio.h>

#define Size 5

void main()
{
	int Arr[Size]={0};
	int i;
	int Max,Min;

	clrscr();
	printf("Please enter %d numbers\n",Size);
	for(i=0; i<Size ; i++)
	{
		printf("The %d element of the array: ",i+1);
		scanf("%d",&Arr[i]);
		printf("\n");
	}
	Max=0;
	Min=0;
	for(i=1 ; i<Size ;i++)
	{
		if(Arr[Max] < Arr[i])
		{
			Max = i;
		}
		if(Arr[Min] > Arr[i])
		{
			Min =i;
		}
	}
	printf("The maximum value Arr[%d]= %d\n",Max,Arr[Max]);
	printf("The minimum value Arr[%d]= %d\n",Min,Arr[Min]);
	getch();
}