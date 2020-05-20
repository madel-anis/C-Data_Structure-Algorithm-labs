#include <stdio.h>

#define ENTER (13)
#define ESC (27)
#define RIGHT_ARROW (77)
#define LEFT_ARROW (75)
#define HOME (71)
#define END (79)
#define BACKSPACE (8)
#define DELETE (127)

#define TRUE (1)
#define FALSE (0)

void Draw_Text(char *Key, int counter, int Counter_Now);
void Print_Screen(char *Key, int Counter);
void Swap(int *First,int *Second);
void main()
{
	int Counter=0;
	int Counter_Now=0;
	int Exit_Flag=FALSE;
	char Key[50];
	char Temp_Char;
	int i;

	while( !Exit_Flag )
	{
		Draw_Text(Key,Counter,Counter_Now);
		Temp_Char = getch();
		if(Temp_Char == NULL)
		{
			Temp_Char = getch();
			switch(Temp_Char)
			{
				case HOME:
					Counter_Now = 0;
					break;
				case END:
					Counter_Now = Counter;
					break;
				case RIGHT_ARROW:
					if(Counter_Now == Counter)
					{
						Counter_Now = 0;
					}
					else
					{
						Counter_Now++;
					}
					break;
				case LEFT_ARROW:
					if(Counter_Now == 0)
					{
						Counter_Now = Counter;
					}
					else
					{
						Counter_Now--;
					}
			   /*	case BACKSPACE:
					for(i=Counter_Now-1 ; i<=(Counter) ; i++)
					{
						Swap(&Key[i],&Key[i+1]);
					}
					Counter--;
					Counter_Now--;
					break;
				case DELETE:
					if(Counter_Now != Counter)
					Key[Counter_Now]=' ';
					break;      */
			}
		}
		else if (Temp_Char == ENTER)
		{
			Print_Screen(Key,Counter);
		}
		else if (Temp_Char == ESC)
		{
			Exit_Flag=TRUE;
		}
		else
		{
			if(Counter_Now == Counter)
			{
				Key[Counter]=Temp_Char;
				Counter++;
				Counter_Now++;
			}
			else
			{
				Key[Counter_Now]=Temp_Char;
			}
		}
	}
	clrscr();
	printf("The program is terminated");
	getch();

}

void Draw_Text(char *Key, int Counter ,int Counter_Now)
{
	int i;

	clrscr();
	gotoxy(5,5);
	for(i=0 ; i<Counter ; i++)
	{
		gotoxy(5+i,5);
		printf("%c",*(Key+i));
	}
		gotoxy(5+Counter_Now,5);

}

void Print_Screen(char *Key, int Counter)
{
	int i;
	gotoxy(1,1);
	for(i=0 ; i<Counter ; i++)
	{
		printf("%c",*(Key+i));
	}

	getch();
}

void Swap(int *First,int *Second)
{
	*First = *First + *Second;
	*Second = *First - *Second;
	*First = *First - *Second;
}