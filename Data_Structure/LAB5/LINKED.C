#include <stdio.h>
#include <conio.h>

#define TRUE (1)
#define FALSE (0)

/* Structs */

typedef struct Node{

	int ID;
	char name[40];
	Node* next;
	Node* prev;

}Node;

typedef struct Linked_List{

	Node* Start;
	Node* End;

};


/* function prototypes */

Node* Create_Node();

void main()
{
	clrscr();




	getch();
}

Node* Create_Node()
{
	Return ( (Node *)malloc(sizeof(Node)) );
}

int Add_Node(Linked_List* List , Node* New_Node)
{
	
	New_Node = Create_Node();
	
	if(New_Node == NULL)			// malloc couldn't reserve a place for me 
	{
		return FALSE;
	}
	
	if((List->Start == NULL) && (List->End == NULL))	//Empty List
	{
		List->Start = New_Node;
		List->End = New_Node;
		New_Node->next = NULL;
		New_Node->prev = NULL;
	}
	else 
	{
		List->End->next = New_Node;
		New_Node->prev = List->End;
		New_Node->next = NULL;
		List->End = New_Node;
	}
	return TRUE;
}

Node* Search(Linked_List* List , int key)
{
	Node* Temp = List->Start ;
	
	while(Temp != NULL && Temp.ID != key)
	{
		Temp = Temp->next;
	}
	
	return Temp;
}

void Insert_Node(Linked_List* List , Node* New_Node)
{
	
}