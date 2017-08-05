#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()  
{  
    int a[10] = {12,4354,657,876,2433,23,18,943,54,8};  
    List L = malloc(sizeof(struct Node));  
    L = CreateList(a,10);
    Position P = L;  
    if(IsEmpty(L))  
    {  
        printf("The list is empty!\n");  
        exit(1);  
    }else{
    	printf("The list is not empty!\n");
    	
    } 
     
    PrintList(L);
    printf("------------------------------------------\n");  
    Delete(a[1],L);  
    PrintList(L);
    printf("------------------------------------------\n");  
    Insert(55,L,P -> Next -> Next);  
    PrintList(L);  
    printf("------------------------------------------\n");  
    DeleteList(L);
    if(IsEmpty(L))  
    {  
        printf("The list is empty!\n");  
        exit(1);  
    }else{
        printf("The list is not empty!\n");
        
    } 
    return 0;  
}  
