#include <stdio.h>

#define ROW 3
#define COL 3

void main()
{
	int Arr[ROW][COL];
	int i,j,k;
	int Sum=0,AVG=0;

	clrscr();
	printf("Please enter numbers for %dx%d array \n",ROW,COL);
	for(i=0; i<ROW ; i++)
	{
		for(j=0 ; j<COL ; j++)
		{
			printf("The %dx%d element of the array: ",i+1,j+1);
			scanf("%*[^0-9]%d",&Arr[i][j]);
			printf("\n");
		}
	}

	printf("The Whole Array\n");
	for(i=0; i<ROW ; i++)
	{
		Sum=0;
		for(j=0 ; j<COL ; j++)
		{
			printf("%d\t",Arr[i][j]);
			Sum+=Arr[i][j];
		}
		printf("%d",Sum);
		printf("\n");
	}

	for(i=0; i<COL ; i++)
	{
		AVG=0;
		for(j=0 ; j<ROW ; j++)
		{
			AVG+=Arr[j][i];
		}
		printf("%.1f",((float)AVG/ROW));
		printf("\t");
	}


	getch();
}