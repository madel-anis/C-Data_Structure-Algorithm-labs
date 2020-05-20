#include <stdio.h>
#include <conio.h>
#include <alloc.h>

#define TRUE (1)
#define FALSE (0)

#define UP_ARROW (72)
#define DOWN_ARROW (80)
#define MAX_LABELS (6)
#define ENTER (13)

char Label[MAX_LABELS][50]={"Name","Address","Phone Number","Display","Back","Exit"};

typedef struct Emp{
int ID;
char Name[50];
char Address[50];
int Phone_Number;
}Emp;

void Draw_Table(int Position);
void Display(Emp *P_Emp , int Emp_Number);

void main()
{
	int Emp_Number=0;
	int Emp_Count=0;
	Emp *P_Emp;
	int Exit_Flag=FALSE;
	int Inter_Flag=FALSE;
	int Enter_Flag=TRUE;
	int Index=0;
	int i;
	int Position=0;
	char Key;

	clrscr();

	printf("Please enter the number of the employees: ");
	scanf("%d",&Emp_Number);

	P_Emp = (Emp*)malloc(Emp_Number * sizeof(Emp));

	for(i=0 ; i<Emp_Number ; i++)
	{
		(P_Emp+i)->ID=0;
	}

	while(!Exit_Flag)
	{
		clrscr();
		while((!Inter_Flag) && Enter_Flag)
		{
			printf("Please enter the ID required to be add(Note: zero is not allowed as an id)\nID:");
			scanf("%d",&Index);
			if((Index > Emp_Number) || (Index < 0))
			{
				printf("This index exceed the limit, choose smaller one\n");
				getch();
				continue;
			}
			else if(Index == 0)
			{
				printf("The ID of value zero is not allowed\n");
				getch();
				continue;
			}
			else	if((Index < Emp_Number) && (Index > 0))
			{
				for(i=0 ; i<Emp_Number ; i++)
				{
					if((P_Emp+i)->ID == Index)
					{
						printf("This ID is already exit, choose another\n");
						getch();
						continue;
					}
				}
			}

			(P_Emp+Index-1)->ID = Index;
			Emp_Count++;
			Inter_Flag = TRUE;
		}
		Inter_Flag = FALSE;
		Enter_Flag = FALSE;

		Draw_Table(Position);

		Key = getch();

		if(Key == NULL)
		{
			Key = getch();
			switch(Key)
			{
				case UP_ARROW:
					Position--;
					if(Position < 0)
					{
						Position = (MAX_LABELS-1);
					}
					break;
				case 80:
					Position++;
					if(Position > (MAX_LABELS-1))
					{
						Position = 0;
					}
			}
		}
		else if(Key == ENTER)
		{
			switch(Position)
			{
			int Temp;
				case 0:
					clrscr();
					printf("please enter the name of the %d Employee: ",Index);
					scanf("%s",(P_Emp+Index-1)->Name);
					break;

				case 1:
					clrscr();
					printf("please enter the address of the %d Employee: ",Index);
					scanf("%s",(P_Emp+Index-1)->Address);
					break;

				case 2:
					clrscr();
					printf("please enter the phone number of the %d Employee: ",Index);
					scanf("%d",&((P_Emp+Index-1)->Phone_Number));
					//(P_Emp+Index-1)->Phone_Number=Temp;
					//	printf("%d",(P_Emp+Index-1)->Phone_Number);
					//getch();
					break;

				case 3:
					Display(P_Emp ,Emp_Number);
					break;

				case 4:
					if(Emp_Count == Emp_Number)
					{
						printf("you can't add further employees, you reached the maximum number");
					}
					else
					{
					Enter_Flag = TRUE;
					}
					break;

					case 5:
					Exit_Flag = TRUE;
			}

		}
	}
	clrscr();
	printf("The Program is terminated\n");
	getch();
	free(P_Emp);
}

void Draw_Table(int Position)
{
	int i;
	clrscr();

	for(i=0 ; i<6 ; i++)
		{
			gotoxy(5,i+1);
			if(Position == i)
			{
				textattr(0x70);
				cprintf("%s",Label[i]);
				textattr(0x07);
			}
			else
			{
				printf("%s",Label[i]);
			}
		}
}
void Display(Emp *P_Emp , int Emp_Number)
{
	int i;
	clrscr();
	for(i=0 ; i<Emp_Number ; i++)
	{
		if((P_Emp+i)->ID != 0)
		{
			printf("The Employee ID: %d\n",(P_Emp+i)->ID);
			printf("Name: %s\n",(P_Emp+i)->Name);
			printf("Address: %s\n",(P_Emp+i)->Address);
			printf("Phone Number: %d\n",(P_Emp+i)->Phone_Number);
		}
	}
	getch();
}