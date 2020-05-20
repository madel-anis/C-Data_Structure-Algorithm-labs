#include<stdio.h>
#include<conio.h>

#define L_Screen (80)
#define R_Screen (25)

void main(void)
{
unsigned int N=0;
int col=0;
int row=0;
int i;
unsigned int dx,dy;

clrscr();
printf("please enter the size of the box\t");
scanf("%d",&N);

dx=(L_Screen-N)/(N+1);
dy=(R_Screen-N)/(N+1);
col=N/2;

gotoxy((col+1)*dx,(row+2)*dy);
printf("%d",1);

for(i=1 ; i<(N*N) ; i++)
{
	if(i%N!=0)
	{
		row--;
		if(row < 0)
		{
			row=N-1;
		}
		col--;
		if(col < 0)
		{
			col=N-1;
		}
	}
	else
	{
		row++;
		if(row > N-1)
		{
			row=0;
		}
	}
	gotoxy((col+1)*dx , (row+2)*dy);
	printf("%d",i+1);
}
getch();
}