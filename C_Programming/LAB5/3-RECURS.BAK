#include <stdio.h>
#include <conio.h>

int Power_Rec(int Number , int Power);

void main(void)
{
	int Power;
	int Base_Number;
	int Result=0;

	clrscr();
	printf("Please Enter the Base Number: ");
	scanf("%d",&Base_Number);
	printf("please Enter the Power: ");
	scanf("%d",&Power);

	Result = Power_Rec(Base_Number,Power);
	printf("The Result = %d\n",Result);

	getch();

}

int Power_Rec(int Number ,int Power)
{
	if(Power == 1)
	{
		return Number;
	}
	else
	{
		return (Number * Power_Rec(Number , Power-1));
	}
}