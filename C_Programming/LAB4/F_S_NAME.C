#include <stdio.h>

#define STRING_LENGTH (15)
#define TRUE (1)
#define FALSE (0)
#define ENTER (13)

void main()
{
	char F_Name[(STRING_LENGTH+1)];
	char L_Name[(STRING_LENGTH+1)];
	int counter=0;
	int Exit_Flag_1 = TRUE;
	int Exit_Flag_2 = TRUE;

	clrscr();

	printf("Enter your first name:");

	while(Exit_Flag_1)
	{
		F_Name[counter] = getche();
		if((counter+1) > STRING_LENGTH)
		{
			clrscr();
			printf("you exceed the allowed numbers of characters, please try again\n");
			printf("Enter your first name:");
			counter = 0;
		}
		else if(F_Name[counter] == ENTER)
		{
			F_Name[counter] = '\0';
			Exit_Flag_1 = FALSE;
			clrscr();
		}
		counter++;
	}
	counter = 0;
	clrscr();
	printf("Enter your Last name:");

	while(Exit_Flag_2)
	{
		L_Name[counter] = getche();
		if((counter+1) > STRING_LENGTH)
		{
			clrscr();
			printf("you exceed the allowed numbers of characters, please try again\n");
			printf("Enter your last name:");
			counter = 0;
		}
		else if(L_Name[counter] == ENTER)
		{
			L_Name[counter] = '\0';
			Exit_Flag_2 = FALSE;
			clrscr();
		}
		counter++;
	}
	clrscr();
	printf("The first name: %s\t||\t",F_Name);
	printf("The second name: %s\n",L_Name);
	getch();
}