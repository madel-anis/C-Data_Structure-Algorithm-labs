#include <stdio.h>
#include <conio.h>

#define TRUE (1)
#define FALSE (0)
#define MAX_LABELS (5)
#define MAX_EMPLOYEE (5)
#define ARROW_UP (72)
#define ARROW_DOWN (80)
#define ENTER (13)

typedef struct Employees{

int ID;
char Name[50];
char Address[50];
int Phone_Number;

}Employee;

void Draw_Menu(int counter);
int New_Employee(Employee *Emp_P,int Employee_Count);
void Display(Employee *Emp_P , int Employee_Count);
void Search_Employee(Employee *Emp_P,int Employee_Count);
void Edit_Employee(Employee *Emp ,int Employee_Count);

void main()
{
	int Exit_Flag = TRUE;
	int counter =0;
	int Employee_Count=0;
	int i;
	char Key;
	Employee Emp[5];
	Employee *Emp_P;

	Emp_P=&Emp[0];

	while(Exit_Flag)
	{
		clrscr();
		Draw_Menu(counter);

		Key = getch();

		if(Key == NULL)
		{
			Key = getch();
			switch(Key)
			{
				case ARROW_UP:
					counter--;
					if(counter < 0)
					{
						counter = MAX_LABELS;
					}
					break;
				case ARROW_DOWN:
					counter++;
					if(counter > MAX_LABELS)
					{
						counter = 0;
					}
			}
		}
		else if(Key == ENTER)
		{
			switch(counter)
			{
				case 0:
					Emp_P=&Emp[0];
					Search_Employee(Emp_P,Employee_Count);
					break;
				case 1:
					Emp_P=&Emp[0];
					Edit_Employee(Emp_P,Employee_Count);
					break;
				case 2:
					Emp_P=&Emp[0];
					if( New_Employee(Emp_P,Employee_Count) )
					{
						Employee_Count++;
					}
					break;
				case 3:
					Emp_P=&Emp[0];
					Display(Emp_P , Employee_Count);
					break;
				case 4:
					Exit_Flag= FALSE;
			}
		}
	}
	clrscr();
	printf("The program Terminated\n");
	getch();
}

void Draw_Menu(int counter)
{
	int i;
	char Label[MAX_LABELS][50]={"Search ID","Edit","Enter New Employee","Display","Exit"};

	for(i=0 ; i<MAX_LABELS ; i++)
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
}

void Search_Employee(Employee *Emp_P,int Employee_Count)
{
	int ID_req;
	int i;
	clrscr();

	printf("Enter the ID required to be displayed\n");
	scanf("%d",&ID_req);
	for(i=0 ; i<Employee_Count ; i++)
	{
		if(ID_req == Emp_P->ID)
		{
			printf("ID: %d\n",Emp_P->ID);
			printf("Name: %s\n",Emp_P->Name);
			printf("Address: %s\n",Emp_P->Address);
			printf("Phone Number: %d\n",Emp_P->Phone_Number);
			getch();
			return;
		}
		Emp_P++;
	}
	printf("Can't find your ID\n");
	getch();
}

void Edit_Employee(Employee *Emp_P,int Employee_Count)
{
	int ID_req;
	int i;
	int Flag=FALSE;

	clrscr();
	printf("Enter the ID required to be edited\n");
	scanf("%d",&ID_req);

	for(i=0 ; i<Employee_Count ; i++)
		{
			if(ID_req == Emp_P->ID)
			{
				printf("please Enter the Employee Name you want to edit: ");
				scanf("%s",&Emp_P->Name);
				printf("please Enter the Employee Address you want to edit: ");
				scanf("%s",&Emp_P->Address);
				printf("please Enter the Employee Phone Number you want to edit: ");
				scanf("%d",&Emp_P->Phone_Number);
				Flag=TRUE;
				break;
			}
		}
		if(Flag == FALSE)
		{
			printf("The ID you entered is not exist\n");
			getch();
		}
}

int New_Employee(Employee *Emp_P,int Employee_Count)
{
	 int Flag = FALSE;
	 int i;
	 int ID;

	 clrscr();

	 if((Employee_Count+1) < MAX_EMPLOYEE)
	 {
		printf("please Enter the Employee ID: ");
		scanf("%d",&ID);
		for(i=0 ; i<Employee_Count ; i++)
		{
			if(ID == Emp_P->ID)
			{
				printf("this ID is already exist");
				getch();
				return Flag;
			}
			Emp_P++;
		}
		Emp_P->ID=ID;

		printf("please Enter the Employee Name: ");
		scanf("%s",&Emp_P->Name);
		printf("please Enter the Employee Address: ");
		scanf("%s",&Emp_P->Address);
		printf("please Enter the Employee Phone Number: ");
		scanf("%d",&Emp_P->Phone_Number);
		Flag = TRUE;
	 }
	 else
	 {
		printf("you can't add more Employee, the excedded the maximum number\n");
		getch();
	 }
	 return Flag;
}

void Display(Employee *Emp_P , int Employee_Count)
{
	int i;
	clrscr();
	for(i=0 ; i<Employee_Count ; i++)
	{
		printf("The %d Employee:\n",i+1);
		printf("ID: %d\n",Emp_P->ID);
		printf("Name: %s\n",Emp_P->Name);
		printf("Address: %s\n",Emp_P->Address);
		printf("Phone Number: %d\n",Emp_P->Phone_Number);
		Emp_P++;
	}
	getch();
}