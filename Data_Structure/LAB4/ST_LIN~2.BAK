#include <stdio.h>
#include <string.h>

#define TRUE (1)
#define FALSE (0)
#define LABELS_SIZE (3)
#define ARROW_UP (72)
#define ARROW_DOWN (80)
#define ENTER (13)
#define SIZE_STACK (10)

char Labels[LABELS_SIZE][21]={"Push","Pop","Exit"};

/*struct decleration*/

typedef struct Node{

int ID;
char Name[20];
struct Node *Prev;
struct Node *Next;

}Node;

typedef struct Linked_List{

Node *Start;
Node *End;

}Linked_List;

typedef struct Stack{
	int Size;
	int Elements_Count;
	Node* p_Stack_Element;
}Stack;

/*Prototype*/

	/*Stack Functions*/
int Init_Stack(Stack* p_Stack , int Size);
int IsEmptyStack(Stack* p_Stack);
int IsFullStack(Stack* p_Stack);
int push(Stack* p_Stack , Linked_List* p_List , Node* Data);
int pop(Stack* p_Stack , Linked_List* p_List , Node* Data);
	/*Linked Functions*/
void Linked_List_Int(Linked_List* New);
void Free_List(Linked_List *List);

Node* Create_Node(void);
void Add_Node(Linked_List* List , Node* New_Node);
int Delete_Node(Linked_List* List);

	/*helpful nice Functions*/
void Draw_Menu(int Counter);


void main()
{
	int Exit_Flag = FALSE;
	int Counter = 0;
	char Key;
	int Temp_ID;
	char Temp_Name[20];
	char Temp_String[20];
	Node* Temp_Node;

	Stack New_Stack;
	Stack* p_New_Stack;

	Linked_List List;
	Linked_List* p_List;

	p_New_Stack = &New_Stack;
	p_List = &List;

	Linked_List_Int(p_List);
	Init_Stack(p_New_Stack,SIZE_STACK);



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
				case 0:									//push

						clrscr();
						if(IsFullStack(p_New_Stack) == 1)
						{
							printf("There is no stack avaialble to be added\n");
							getch();
							break;
						}
						else
						{
							printf("Please Enter the ID: ");
							scanf("%d",&Temp_ID);
							printf("please Enter the name: ");
							scanf("%s",Temp_Name);
							printf("Please Enter the Data wanted to be added to stack: ");
							Temp_Node->ID = Temp_ID;
							strcpy(Temp_Node->Name,Temp_Name);
							push(p_New_Stack , p_List , Temp_Node);
						}
					break;
				case 1:									//Pop
						clrscr();
						if(pop(p_New_Stack , p_List , Temp_Node) == 1)
						{
							printf("The ID: %d\n",Temp_Node->ID);
							strcpy(Temp_String,Temp_Node->Name);
							printf("The Name: %s\n",Temp_String);
							getch();
						 }
						else
						{
							printf("There is no data avaialble in the stack\n");
							getch();
							break;
						}
				 break;
				case 2:									//Delete
						Exit_Flag = TRUE;

			}
		}


	}
	clrscr();
	free(p_New_Stack);
	//Free_List(p_List);
	printf("The program terminated\n");
	getch();

}

int Init_Stack(Stack* p_Stack , int Size)
{
	p_Stack->p_Stack_Element = (Node*)malloc(sizeof(Node)*Size);
	if( p_Stack->p_Stack_Element != NULL)
	{
		p_Stack->Size = Size;
		p_Stack->Elements_Count = 0;
		return 1;
	}
	return 0;
}

int IsEmptyStack(Stack* p_Stack)
{
	if(p_Stack->Elements_Count == 0)
	{
		return 1;
	}
	return 0;
}

int IsFullStack(Stack* p_Stack)
{
	if(p_Stack->Elements_Count == p_Stack->Size)
	{
		return 1;
	}
	return 0;
}

int push(Stack* p_Stack , Linked_List* p_List , Node* Data)
{
	if(IsFullStack(p_Stack) == 1)
	{
		return 0;
	}
	else
	{
		p_Stack->p_Stack_Element = Create_Node();
		Add_Node(p_List , p_Stack->p_Stack_Element);
		p_Stack->p_Stack_Element->ID = Data->ID;
		strcpy(p_Stack->p_Stack_Element->Name,Data->Name);
		p_Stack->Elements_Count++;
		return 1;
	}
}

int pop(Stack* p_Stack , Linked_List* p_List , Node* Data)
{
	if(IsEmptyStack(p_Stack) == 1)
	{
		return 0;
	}
	else
	{
		p_Stack->p_Stack_Element = p_List->End;
		Data->ID = p_Stack->p_Stack_Element->ID;
		strcpy(Data->Name , p_Stack->p_Stack_Element->Name);
		Delete_Node(p_List);
		p_Stack->Elements_Count--;
		return 1;
	}
}

void Linked_List_Int(Linked_List* New)
{
	New->Start = NULL;
	New->End = NULL;
}

Node* Create_Node(void)
{
	return ( (Node*)malloc(sizeof(Node*)) );
}

void Add_Node(Linked_List* List , Node* New_Node)
{
	if(List->Start == NULL)
	{
		List->Start = New_Node;
		List->End = New_Node;
		New_Node->Prev = NULL;
		New_Node->Next = NULL;
	}
	else
	{
		New_Node->Next = NULL;
		New_Node->Prev = List->End;
		List->End->Next = New_Node;
		List->End = New_Node;
	}
}

int Delete_Node(Linked_List* List)
{
	Node* Temp = List->End;

	if(Temp == NULL)
	{
		return 0;
	}

	else if( (Temp == List->Start) && (Temp == List->End) )
	{
		List->Start = NULL;
		List->End = NULL;
	}
	else
	{
		Temp->Prev->Next= NULL;
		List->End = Temp->Prev;
	}
	
	free(Temp);

	return 1;
}

void Free_List(Linked_List *List)
{
	while(List->Start != NULL)
	{
		Delete_Node(List);
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