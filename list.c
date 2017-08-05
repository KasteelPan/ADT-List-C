#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*return ture if L is empty*/  
int IsEmpty(List L)
{
	return L -> Next == NULL; 
}

/*return ture if P is the last position in list L*/
int IsLast(Position P, List L)
{
	return P -> Next == NULL;
}

/*return Postion of X in L; Null if not found*/
Position Find(ElementType X, List L)
{
	Position P;

	P = L -> Next;
	while( P!=NULL && P->Element != X)
		P = P -> Next;
	return P;
}

/*Delete first occurence of X form a list L*/
void Delete(ElementType X, List L)
{
	Position P, TmpCell;

	P = FindPrevious(X,L);

	if (!IsLast(P,L))
	{
		TmpCell = P -> Next;
		P -> Next = TmpCell -> Next;/*bypass deleted cell*/
		free(TmpCell);
	}
}

/*If X is not found, then Next field of returned */
Position FindPrevious(ElementType X,List L)
{
	Position P;

	P = L;
	while(P -> Next != NULL && P -> Next -> Element != X)
		P = P -> Next;
	return P;
}

/*Insert after legal position P*/
void Insert(ElementType X, List L, Position P)
{
	Position TmpCell;

	TmpCell = malloc(sizeof(struct Node));
	if (TmpCell == NULL)
		printf("Out of space!");
	TmpCell -> Element = X;
	TmpCell -> Next = P -> Next;
	P -> Next = TmpCell; 
}

void PrintList(List L)
{
	Position P;

	P = L;
	while(P -> Next != NULL){
		P = P -> Next;
		printf("%d\n", P -> Element);
		
	}
}

/*Delete the list*/
void DeleteList(List L)
{
	Position P, TmpCell;

	P = L -> Next;
	L -> Next = NULL;
	while(P != NULL){
		TmpCell = P -> Next;
		free(P);
		P = TmpCell;
	}
}

//create a list  
List CreateList(int *ptr, int len)  
{  
    List head;  
    Position p;  
    Position tmp;  
    head = malloc(sizeof(struct Node));  
    p = malloc(sizeof(struct Node));  
    int i = 0;  
    for(i = 0; i < len; i++) {  
    	if (i == 0){  
        	p -> Element = *(ptr + i);  
        	head -> Next = p;  
    	}else{  
        	tmp = malloc(sizeof(struct Node));  
        	tmp -> Element=*(ptr+i);  
        	p -> Next = tmp;  
        	p = p->Next;  
    	}  
    }  
    p -> Next = NULL;  
    return head;  
}  


