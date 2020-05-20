#include<stdio.h>
#include<conio.h>

void main()
{
char input_char;
int  ASCII;
int Number;

clrscr();

//first task
printf("Hello World\n");

//second task
printf("Enter a Char\n");
scanf("%c",&input_char);
printf("%d\n",input_char);

//third task
printf("enter an ASCII\n");
scanf("%d",&ASCII);
printf("%c\n",ASCII);

//forth task
printf("Enter a decimal number\n");
scanf("%d",&Number);
printf("%x\n",Number);

getch();

}