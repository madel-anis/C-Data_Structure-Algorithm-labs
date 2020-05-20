#include <stdio.h>

#define ESC (27)

void main()
{
	char Key;
	int Exit_Flag = 1;

	clrscr();

	while(Exit_Flag)
	{
		printf("Enter an extended key\n");
		Key = getch();

		if(Key == NULL)
		{
			Key = getch();
			printf("The ASCII Code of Entered character is: %d\n",Key);
		}
		else if(Key == ESC)
		{
			printf("Escape button pressed\n");
			Exit_Flag=0;
		}
		else
		{
			printf("the key pressed is not an extended key, try again\n");
		}
	}
	getch();
}