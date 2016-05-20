//
//  sorted-list.c
//  
//
//  Created by Michael Mathews on 9/25/15.
//
//

#include <stdio.h>
#include "sorted-list.h"

//creates sorted list with nodes for the head, temp(current node looked at), previous
SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df) {
    SortedListPtr sl = malloc(sizeof(struct SortedList)*100);
    sl->compFunct = cf;
    sl->destFunct = df;
    sl->head = malloc(sizeof(CurrentNode*)*100);
    sl->head = NULL;
    sl->temp = malloc(sizeof(CurrentNode*)*100);
    sl->temp = sl->head;
    sl->prev = malloc(sizeof(CurrentNode*)*100);
    sl->prev = sl->head;
    //sl->item = malloc(sizeof(int)*100);
    return sl;
}

//creates a node to store the data, and a pointer to the next node in the list
CurrentNode createNode(void* d, void* n){
    CurrentNode newNode = malloc(sizeof(struct node));
    newNode->data = malloc(sizeof(void*)*100);
    newNode->next = malloc(sizeof(CurrentNode)*100);
    newNode->data = d;
    newNode->next->data = n;
    return newNode;
}





void SLDestroy(SortedListPtr list){
    free(list);
}





//inserts a void* item into the list and returns the result of the compare function
int SLInsert(SortedListPtr list, void *newObj){
    
    int i = 0;
    int j = 0;
    SortedListIteratorPtr listTrav = SLCreateIterator(list);
   
    //Nothing in the list yet
    if (list->head == NULL){
        CurrentNode headNode = createNode(newObj, NULL);
        //printf("\nhead2: %d\n", *(int*)headNode->data);
        list->head = headNode;
        list->temp = list->head;
        list->prev = list->head;
      
    }

    else{
        CurrentNode headNode = createNode(newObj, NULL);
        i = list->compFunct(newObj, (list->head->data));
        //printf("\n%d\n", i);
        if (i < 0){
            
            if (list->temp->next == NULL){
                headNode->next = list->temp;
                list->prev->next = headNode;
            }
            
            else{
            
            j = -1;
            list->temp = list->temp->next;
                //printf("data: %d\n", *(int*)listTrav->current->data);
            while(list->temp->data != NULL && j < 0){
                j = list->compFunct(newObj, (list->temp->data));
                if (j >= 0){
                    break;
                }
                list->prev = list->temp;
                list->temp = list->temp->next;
            }
            headNode->next = list->temp;
            list->prev->next = headNode;
            }
        }
        else if (i >= 0){
            headNode->next = list->head;
            list->head = headNode;
        }
    }
    list->temp = list->head;
    list->prev = list->head;
    
    return i;
}





//not implemented
int SLRemove(SortedListPtr list, void *newObj){
    return 0;
}





//creates an iterator so the user in the main method can walk through the list element by element(not implemented)
SortedListIteratorPtr SLCreateIterator(SortedListPtr list){
    SortedListIteratorPtr listIterator = malloc(sizeof(SortedListIteratorPtr));
    listIterator->slPtr = malloc(sizeof(listIterator));
    listIterator->current = list->head;
    listIterator->prevNode = list->head;
    listIterator->slPtr = list;

    return listIterator;
}




//not implemented
void SLDestroyIterator(SortedListIteratorPtr iter){
    free(iter);
}

//not implemented
void * SLGetItem( SortedListIteratorPtr iter ){
    
}




//not implemented
void * SLNextItem(SortedListIteratorPtr iter){
    iter->current = iter->current->next;

}



















