#include <stdio.h>
#include <alloc.h>

void main()
{
	int Arrays_Size=0;
	int *Single_Array_Size;
	int *Array_Type_Index=0;
	void **P_P_Arrays;

	int i,j;

	clrscr();

	printf("Enter the size of arrays you want to create: ");
	scanf("%d",&Arrays_Size);

	Array_Type_Index = (int *)malloc(Arrays_Size * sizeof(int));
	Single_Array_Size = (int *)malloc(Arrays_Size * sizeof(int));
	P_P_Arrays = (void **)malloc(Arrays_Size * sizeof(void **));

	for(i=0 ; i<Arrays_Size ; i++)
	{
		clrscr();
		printf("What is the kind of the first array ?\n 1-array of char\n 2-array of int\n 3-array of float \n press the index of required type");
		scanf("%d",&Array_Type_Index[i]);

		switch(Array_Type_Index[i])
		{
			case 1:
				clrscr();
				printf("The size of this char array is: ");
				scanf("%d",&Single_Array_Size[i]);
				P_P_Arrays[i] = (char *)malloc(sizeof(char *) * Single_Array_Size[i]);

				printf("please enter the values of the this array\n");
				for(j=0 ; j<Single_Array_Size[i] ; j++)
				{
					printf("please Enter the %d element: ");
					scanf("%c",&P_P_Arrays[i][j]);
				}
			break;

			case 2:
			break;

			case 3:
			break;
		}
	}
	for(i=0 ; i<Arrays_Size ; i++)
	{
		clrscr();
		for(j=0 ; j>Single_Array_Size ; j++)
		{
			printf("The %d element of %d array: %d",j,i,P_P_Arrays[i][j]);
		}
	}
	free(Array_Type_Index);
	free(Single_Array_Size);
	for(i=0 ; i<Arrays_Size ; i++)
	{
		free(P_P_Arrays[i]);
	}
	free(P_P_Arrays);
	getch();
}