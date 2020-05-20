#include<stdio.h>
#include<conio.h>

void main()
{
	int Number=0;
	int Sum=0;

	clrscr();

	do
	{

	printf("Enter a number\n");
	scanf("%d",&Number);
	Sum+=Number;
	printf("Sum=\t%d\n",Sum);

	}while(Sum<100);
	printf("The End");f
getch();
}