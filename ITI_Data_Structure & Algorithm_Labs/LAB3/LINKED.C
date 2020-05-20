#include <stdio.h>

#define TRUE (1)
#define FALSE (0)
#define LABELS_SIZE (5)
#define ARROW_UP (72)
#define ARROW_DOWN (80)
#define ENTER (13)

char Labels[LABELS_SIZE][21]={"Add","Search","Delete","Display","Exit"};

//user type definition
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

/* protoype */
void Linked_List_Int(Linked_List* New);
Node* Create_Node(void);
void Add_Node(Linked_List* List , Node* New_Node);
//void Insert_Node(Linked_List* List , Node* New_Node);
Node* Search(Linked_List* List , int ID_Req);
int Delete_Node(Linked_List* List , int ID_Req);
void Draw_Menu(int Counter);
void Free_List(Linked_List *List);

void main()
{
	int Exit_Flag = FALSE;
	int Counter = 0;
	char Key;
	int ID_Temp;
	int i;
	char Name_Temp[20];
	Node* Temp_Node;

	Linked_List List;
	Linked_List* Ptr_List;
	Ptr_List = &List;
	Linked_List_Int(Ptr_List);

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
				case 0:									//Add

						clrscr();
						Temp_Node = NULL;
						printf("Please Enter the ID: ");
						scanf("%d",&ID_Temp);
						printf("please Enter the name: ");
						scanf("%s",Name_Temp);
						Temp_Node = Create_Node();
						Add_Node(Ptr_List , Temp_Node);
						Temp_Node->ID = ID_Temp;
						strcpy(Temp_Node->Name,Name_Temp);
					break;
				case 1:									//Search
						clrscr();
						printf("Please Enter the ID required to be found: ");
						scanf("%d",&ID_Temp);
						Temp_Node = Search(Ptr_List,ID_Temp);
						if(Temp_Node == 0)
						{
							printf("The ID you inserted is not exist\n");
						}
						else
						{
							printf("The ID: %d\n",Temp_Node->ID);
							printf("The Name: %s\n",Temp_Node->Name);
						}
						getch();
					break;
				case 2:									//Delete
						clrscr();
						printf("Please Enter the ID required to be deleted");
						scanf("%d",&ID_Temp);
						Temp_Node = Delete_Node(Ptr_List,ID_Temp);
						if(Temp_Node == 0)
						{
							printf("The ID you inserted is not exist\n");
						}
						else
						{
							printf("This ID has been deleted successfully\n");
						}
						getch();
					break;
				case 3:									//Display
						i=1;
						clrscr();
						Temp_Node = Ptr_List->Start;
						if(Temp_Node == NULL)
						{
							printf("There is no any Nodes in the List");
						}
						while(Temp_Node != NULL)
						{
									printf("The %d Node ID: %d\n",i,Temp_Node->ID);
									printf("The %d Node Name: %s\n",i,Temp_Node->Name);
									printf("\n");
									Temp_Node=Temp_Node->Next;
						}
						getch();
					break;
				case 4:
						Exit_Flag = TRUE;
						Free_List(Ptr_List);
			}
		}


	}
	clrscr();
	printf("The program terminated\n");
	getch();

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
		Node* Temp = List->Start;

		while( (Temp != NULL) && (Temp->ID < New_Node->ID))
		{
			Temp = Temp->Next;
		}

		if( (Temp == List->Start) )
		{
			 if(New_Node->ID < Temp->ID)
			 {
				New_Node->Next = Temp;
				New_Node->Prev = NULL;
				Temp->Prev = New_Node;
				List->Start = New_Node;
			 }
		}
		else if( (Temp == NULL) )
		{
			New_Node->Next = NULL;
			New_Node->Prev = List->End;
			List->End->Next = New_Node;
			List->End = New_Node;
		}
		else
		{
			Temp = Temp->Prev;
			New_Node->Prev = Temp;
			New_Node->Next = Temp->Next;
			Temp->Next->Prev = New_Node;
			Temp->Next = New_Node;
		}
	}
}

/*void Insert_Node(Linked_List* List , Node* New_Node)
{
	Node* Temp = List->Start;

	while( (Temp != NULL) && (Temp->ID < New_Node->ID) )
	{
		Temp = Temp->Next;
	}

	if(Temp == NULL)          	//Empty List or last one
	{
		Add(List , New_Node);
	}
	else
	{
		New_Node->Prev = Temp;
		New_Node->Next = Temp->Next;
		Temp->Next->Prev = New_Node;
		Temp->Next = New_Node;
	}
} */

Node* Search(Linked_List* List , int ID_Req)
{
	Node* Temp = List->Start;
	while( (Temp !=NULL) && (Temp->ID != ID_Req) )
	{
		Temp = Temp->Next;
	}

	return Temp;
}

int Delete_Node(Linked_List* List , int ID_Req)
{
	Node* Temp = List->Start;
	Temp = Search(List,ID_Req);

	if(Temp == NULL)
	{
		return 0;
	}

	if( (Temp == List->Start) && (Temp == List->End) )
	{
		List->Start = NULL;
		List->End = NULL;
	}
	else if(Temp == List->Start)
	{
		Temp->Next->Prev = NULL;
		List->Start = Temp->Next;
	}
	else if(Temp == List->End)
	{
		Temp->Prev->Next= NULL;
		List->End = Temp->Prev;
	}
	else
	{
		Temp->Prev->Next = Temp->Next;
		Temp->Next->Prev = Temp->Prev;
	}
	free(Temp);

	return 1;
}
void Free_List(Linked_List *List)
{
	while(List->Start != NULL)
	{
		Delete_Node(List,List->Start->ID);
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