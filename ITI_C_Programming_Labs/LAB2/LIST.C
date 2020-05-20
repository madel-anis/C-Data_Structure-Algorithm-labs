#include<stdio.h>
#include<conio.h>

void Sub_Menu(int i);
void main()
{
	char ch1,ch2;
	int Flag = 1;
	int i=1;

	while(Flag==1)
	{
		clrscr();

		gotoxy(3,1);
		puts("Name");;
		gotoxy(3,2);
		puts("Phone Number");
		gotoxy(3,3);
		puts("Address");
		gotoxy(3,4);
		puts("Exit");

		gotoxy(2,i);
		printf("%c",26);

		flushall();
		ch1=getch();
		ch2=0;
		if(ch1 == NULL)
		{
			ch2=getch();
			switch(ch2)
			{
				case 72:
					if(i!=1)
					i--;
					break;
				case 80:
					if(i!=4)
					i++;
					break;
				default:
					break;
			}
		}
		else if(ch1 == 13)
		{
			if(i == 4)
			{
				Flag = 0;
			}
			else
			{
				Sub_Menu(i);
			}
		}
	}
	gotoxy(2,5);
	puts("The program terminated\n");
	getch();
}

// the sub screen function
void Sub_Menu(int i)
{
	char c[21];
	clrscr();
	if(i == 1)
	{
		puts("Enter your name\n ");
		gets(c);
		puts("Press any key to continue\n");
	}
	else if(i == 2)
	{
		puts("Enter your Phone Number\n");
		gets(c);
		puts("Press any key to continue\n");
	}
	else if(i == 3)
	{
		puts("Enter your Address\n ");
		gets(c);
		puts("Press any key to continue\n");
	}
}