#include <stdio.h>

#define SIZE 15

int Seq_Search(int *Arr , int Size , int Req);
int Binary_Search(int *Arr , int Size , int Req);

void main()
{
	int i;
	int Size = SIZE;
	int Arr[SIZE]={0};
	int Req=0;
	int Result_Index;

	clrscr();

	for(i=0 ; i<Size ; i++)
	{
		printf("Please Enter the %d element of the array: ",i+1);
		scanf("%d",&Arr[i]);
	}

	printf("\nPlease enter the value you want to search for: ");
	scanf("%d",&Req);

  //	Result_Index = Seq_Search(Arr , Size , Req);
	Result_Index = Binary_Search(Arr , Size , Req);

	if(Result_Index == -1)
	{
		printf("\nThe element is not exist\n");
	}
	else
	{
		printf("\nThe Index of the Element is : %d\n",Result_Index+1);
	}

	getch();
}

int Seq_Search(int *Arr , int Size , int Req)
{
	int i;
	for(i=0 ; i<Size ; i++)
	{
	   if( Arr[i] == Req )
	   {
		   return i;
	   }
	}
	return -1;
}

int Binary_Search(int *Arr , int Size , int Req)
{
	int First = 0;
	int End = Size-1;
	int Mid = Size/2;

	while (First < End)
	{
		if(Arr[Mid] == Req)
		{
			return Mid;
		}
		else if(Arr[Mid] < Req)
		{
			First = Mid+1;
		}
		else if(Arr[Mid] > Req)
		{
			End = Mid-1;
		}
		Mid = (First+End)/2;
	}
	return -1;
}