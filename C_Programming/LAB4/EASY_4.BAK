#include <stdio.h>

#define STRING_LENGTH 100

#define ENTER 13
#define TRUE (1)
#define FALSE (0)

void main()
{
	char Name[(STRING_LENGTH+1)];
	int counter=0;
	int Exit_Flag = TRUE;

	clrscr();

	printf("Enter whatever you want:");

	while(Exit_Flag)
	{
		Name[counter] = getche();
		if((counter+1) > STRING_LENGTH)
		{
			clrscr();
			printf("you exceed the allowed numbers of characters, please try again\n");
			printf("Try again:");
			counter = 0;
		}
		else if(Name[counter] == ENTER)
		{
			Name[counter] = '\0';
			Exit_Flag = FALSE;
			clrscr();
		}
		counter++;
	}
	clrscr();
	printf("That is what you have write: %s\n",Name);
	getch();
}