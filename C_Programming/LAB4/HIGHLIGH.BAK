#include <stdio.h>
#include <string.h>

#define TRUE (1)
#define FALSE (0)

typedef struct Employe{
char Name[50];
char Address[50];
char Phone_Number[50];
}Employee;
void main()
{
	int Exit_Flag = TRUE;
	int counter = 0;
	int Name_Count=0;
	int Address_Count=0;
	int Phone_Count=0;
   //	char Name[4];
   //	char Address[4];
   //	char Phone_Number[4];
	int i;
	char Key;
	char Label[5][50]={"Name","Address","Phone Number","Display","Exit"};
	Employee Emp[4];
	char temp[50];

	while(Exit_Flag)
	{
		clrscr();

		for(i=0 ; i<5 ; i++)
		{
			gotoxy(5,i+1);
			if(counter == i)
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
		Key = getch();

		if(Key == NULL)
		{
			Key = getch();
			switch(Key)
			{
				case 72:
					counter--;
					if(counter < 0)
					{
						counter = 4;
					}
					break;
				case 80:
					counter++;
					if(counter > 4)
					{
						counter = 0;
					}
			}
		}
		else if(Key == 13)
		{
			switch(counter)
			{
				case 0:
					clrscr();
					for(i=0 ; i<Name_Count ; i++)
					{
						printf("The %d name is: %s\n",i+1,Emp[i].Name);
					}
					if(Name_Count > 3)
					{
						printf("you have exceeded the maximum numbers of employees\n");
						getch();
						break;
					}
					printf("Please enter your %d name:\n",Name_Count+1);
					scanf("%s",&temp);
					strcpy(Emp[Name_Count].Name,temp);
					Name_Count++;
					break;
				case 1:
					clrscr();
					for(i=0 ; i<Address_Count ; i++)
					{
						printf("The %d address is: %s\n",i+1,Emp[i].Address);
					}
					if(Address_Count > 3)
					{
						printf("you have exceeded the maximum numbers of employees\n");
						getch();
						break;
					}
					printf("Please enter your %d address:\n",Address_Count+1);
					scanf("%s",&Emp[Address_Count].Address);
					Address_Count++;

					break;
				case 2:
					clrscr();
					for(i=0 ; i<Phone_Count ; i++)
					{
						printf("The %d Phone is: %s\n",i+1,Emp[i].Phone_Number);
					}
					if(Phone_Count > 3)
					{
						printf("you have exceeded the maximum numbers of employees\n");
						getch();
						break;
					}
					printf("Please enter your %d phone:\n",Phone_Count+1);
					scanf("%s",&Emp[Phone_Count].Phone_Number);
					Phone_Count++;
					break;
				case 3:
					clrscr();
					printf("Employees' Names\n");
					for(i=0; i<Name_Count ; i++)
					{
						printf("The name of the %d Employee: %s\n",i+1,Emp[i].Name);
					}
					printf("Employees' Addresses\n");
					for(i=0; i<Address_Count ; i++)
					{
						printf("The address of the %d Employee: %s\n",i+1,Emp[i].Address);
					}
					printf("Employees' Phone Numbers\n");
					for(i=0; i<Phone_Count ; i++)
					{
						printf("The phone numbers of the %d Employee: %s\n",i+1,Emp[i].Phone_Number);
					}
					getch();
					break;
				case 4:
					Exit_Flag=0;
			}
		}
	}
	clrscr();
	printf("The program terminated");
	flushall();
	getch();
}