#include <stdio.h>

#define TRUE (1)
#define FALSE (0)
#define LABELS_SIZE (3)
#define ARROW_UP (72)
#define ARROW_DOWN (80)
#define ENTER (13)
#define SIZE_QUEUE (5)

char Labels[LABELS_SIZE][21]={"Enqueue","Dequeue","Exit"};

/*struct decleration*/

typedef struct Queue{
	int Size;
	int In;
	int* p_Queue_Element;
}Queue;

/*Prototype*/
int Init_Queue(Queue* p_Queue , int Size);
int IsEmptyQueue(Queue* p_Queue);
int IsFullQueue(Queue* p_Queue);
int	Enqueue(Queue* p_Queue , int Data);
int Dequeue(Queue* p_Queue , int* Data);
void Draw_Menu(int Counter);


void main()
{
	int Exit_Flag = FALSE;
	int Counter = 0;
	char Key;
	int Temp_Data;

	Queue New_Queue;
	Queue* p_New_Queue;
	p_New_Queue = &New_Queue;

	Init_Queue(p_New_Queue,SIZE_QUEUE);

	while(!Exit_Flag)
	{
		clrscr();

		Draw_Menu(Counter);

		Key = getch();

		if(Key == NULL)
		{
			Key = getch();
			switch(Key)
			{
				case ARROW_UP:
					Counter--;
					if(Counter < 0)
					{
						Counter = LABELS_SIZE-1;
					}
					break;
				case ARROW_DOWN:
					Counter++;
					if(Counter > LABELS_SIZE-1)
					{
						Counter = 0;
					}
			}
		}
		else if(Key == ENTER)
		{
			switch(Counter)
			{
				case 0:									//Enqueue

						clrscr();
						if(IsFullQueue(p_New_Queue) == 1)
						{
							printf("There is no Queue avaialble to be added\n");
							getch();
							break;
						}
						else
						{
							printf("Please Enter the Data wanted to be added to Queue: ");
							scanf("%d",&Temp_Data);
							Enqueue(p_New_Queue , Temp_Data);
						}
					break;
				case 1:									//Dequeue
						clrscr();
						if(Dequeue(p_New_Queue , &Temp_Data) == 1)
						{
							printf("The Data: %d",Temp_Data);
							getch();
						 }
						else
						{
							printf("There is no data avaialble in the Queue\n");
							getch();
							break;
						}
				 break;
				case 2:									//Exit
						Exit_Flag = TRUE;
			}
		}


	}
	clrscr();
	free(p_New_Queue);
	printf("The program terminated\n");
	getch();

}

int Init_Queue(Queue* p_Queue , int Size)
{
	p_Queue->p_Queue_Element =(int*)malloc(sizeof(int)*Size);
	if( p_Queue->p_Queue_Element != NULL)
	{
		p_Queue->Size = Size;
		p_Queue->In = 0;
		return 1;
	}
	return 0;
}

int IsEmptyQueue(Queue* p_Queue)
{
	if(p_Queue->In == 0)
	{
		return 1;
	}
	return 0;
}

int IsFullQueue(Queue* p_Queue)
{
	if(p_Queue->In == p_Queue->Size)
	{
		return 1;
	}
	return 0;
}

int Enqueue(Queue* p_Queue , int Data)
{
	if(IsFullQueue(p_Queue) == 1)
	{
		return 0;
	}
	else
	{
		p_Queue->p_Queue_Element[p_Queue->In] = Data;
		p_Queue->In++;
		return 1;
	}
}

int Dequeue(Queue* p_Queue , int* Data)
{	
	int i;
	
	if(IsEmptyQueue(p_Queue) == 1)
	{
		return 0;
	}
	else
	{
		*Data = p_Queue->p_Queue_Element[0];
		
		for(i=0 ; i<(p_Queue->In-1) ; i++)
		{
			p_Queue->p_Queue_Element[i] = p_Queue->p_Queue_Element[i+1];
		}
		p_Queue->In--;
		return 1;
	}
}


void Draw_Menu(int Counter)
{
int i;

	for(i=0 ; i<LABELS_SIZE ; i++)
	{
		gotoxy(5,i+1);
		if(Counter == i)
		{
			textattr(0x70);
			cprintf("%s",Labels[i]);
			textattr(0x07);
		}
		else
		{
			printf("%s",Labels[i]);
		}
	}
}