#include <stdio.h>
#include <string.h>

#define SIZE 3

typedef struct Emp{
int ID;
char Name[50];
int Salary;
}Emp;

int Seq_Search_ID(Emp *ptr , int Size , int Req);
int Seq_Search_Name(Emp *ptr , int Size , char* Req);

void main()
{
	Emp Employee[SIZE]={{1,"mohamed",500} , {2,"ahmed",600} , {3,"said",700}};
	Emp *ptr_Emp;
	int ID_Temp=0;
	char *Name_Temp;
	ptr_Emp = &Employee;


	clrscr();
	printf("Enter the ID you want to search: ");
	scanf("%d",&ID_Temp);
	printf("The index is : %d\n", Seq_Search_ID(ptr_Emp,SIZE,ID_Temp)+1);


	printf("Enter the Name you want to search: ");
	scanf("%s",&Name_Temp);
	printf("The index is : %d\n", Seq_Search_Name(ptr_Emp,SIZE,Name_Temp)+1 );
	getch();
}

int Seq_Search_ID(Emp *ptr , int Size , int Req)
{
	int i;
	for(i=0 ; i<Size ; i++)
	{
	   if( (ptr+i)->ID == Req )
	   {
		   return i;
	   }
	}
	return -1;
}

int Seq_Search_Name(Emp *ptr , int Size , char* Req)
{
	int i;
	for(i=0 ; i<Size ; i++)
	{
	   if( strcmp((ptr+i)->Name , Req) == 0)
	   {
		   return i;
	   }
	}
	return -1;
}