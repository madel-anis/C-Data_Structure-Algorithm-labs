#include <stdio.h>
#include <alloc.h>


void main()
{
	int **P_Array;
	int Arrays_Size[2];
	int i,j;

	clrscr();
	P_Array = (int **)malloc(sizeof(int*) * 2);
	printf("Enter the size of the first array: ");
	scanf("%d",&Arrays_Size[0]);

	printf("Enter the size of the second array: ");
	scanf("%d",&Arrays_Size[1]);

	for(i=0 ; i<2 ;i++)
	{
		(P_Array[i]) = (int *)malloc(sizeof(int) * Arrays_Size[i]);
	}
	printf("\n");
	for(i=0 ; i<2 ; i++)
	{
		for(j=0 ; j<Arrays_Size[i] ; j++)
		{
			printf("please enter the value of the %d element of %d array:",j+1,i+1);
			scanf("%d",(*(P_Array+i)+j));
		}
			printf("\n");
	}
		printf("\n");
	clrscr();
	for(i=0 ; i<2 ; i++)
	{
		printf("The %d array:\n",i+1);
		for(j=0 ; j<Arrays_Size[i] ; j++)
		{
			printf("%d ",*(*(P_Array+i)+j));
		}
		printf("\n");
	}
	free(P_Array+0);
	free(P_Array+1);
	free(P_Array);
	getch();
}