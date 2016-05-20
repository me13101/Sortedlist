//
//  main.c
//  
//
//  Created by Michael Mathews on 9/25/15.
//
//

#include <stdio.h>
#include <string.h>
#include "sorted-list.h"
#include "sorted-list.c"

//basic compare ints function
int compareInts(void* a, void* b){

    int Aint = *(int*)a;
    int Bint = *(int*)b;
        
    if (Aint < Bint){
        return -1;
    }
    if (Aint == Bint){
        return 0;
    }
    else{
        return 1;
    }
}
//basic compare strings function
int compareStrings(void* a, void* b){
    char* first = *(char**)a;
    char* second = *(char**)b;
    int i = 0;
    
    i = strcmp(first, second);
    
    return i;
}


void printInts(SortedListPtr list){
    list->temp = list->head;
        while(list->temp->next!= NULL){
            printf("->%d", *(int*)list->temp->data);
            list->temp = list->temp->next;
        }
}
void printStrings(SortedListPtr list){
    list->temp = list->head;
    while(list->temp->next!= NULL){
        printf("->%s", *(char**)list->temp->data);
        list->temp = list->temp->next;
    }

}

//tests a list of ints, creates the ints and inserts them into the list. then calls print list
int test(){
    SortedListPtr sl = SLCreate(compareInts, destroyBasicTypeNoAlloc);
    //int *temp = malloc(sizeof(int));
    int *newItem1 = malloc(sizeof(int));
    *newItem1 = 1;
    
    int *newItem2 = malloc(sizeof(int));
    *newItem2 = 2;
    
    int *newItem3 = malloc(sizeof(int));
    *newItem3 = 3;
    
    int *newItem4 = malloc(sizeof(int));
    *newItem4 = 4;
    
    int *newItem5 = malloc(sizeof(int));
    *newItem5 = 5;
    int *newItem6 = malloc(sizeof(int));
    *newItem6 = -60;
    int *newItem10 = malloc(sizeof(int));
    *newItem10 = 10;

    
     SLInsert(sl, newItem5);
     SLInsert(sl, newItem4);
     SLInsert(sl, newItem5);
     SLInsert(sl, newItem3);
     SLInsert(sl, newItem4);
     SLInsert(sl, newItem3);
     SLInsert(sl, newItem2);
     SLInsert(sl, newItem6);
     SLInsert(sl, newItem3);
     SLInsert(sl, newItem2);
     SLInsert(sl, newItem1);
     SLInsert(sl, newItem10);
    
    
    printf("\n--------------------------------------\n");
    printInts(sl);
    printf("\n--------------------------------------\n");
        //int t = *(int*)sl->head;
//        printf("sl->head: %d\n", t);
    return 0;
}

//tests a list of strings, creates the strings and inserts them into the list. then calls print list
int test2(){
    SortedListPtr sl = SLCreate(compareStrings, destroyBasicTypeNoAlloc);
    
    
    char* *newItem1 = malloc(sizeof(char*));
    *newItem1 = "test";
    char* *newItem2 = malloc(sizeof(char*));
    *newItem2 = "this";
    char* *newItem3 = malloc(sizeof(char*));
    *newItem3 = "is";
    char* *newItem4 = malloc(sizeof(char*));
    *newItem4 = "a";
    char* *newItem5 = malloc(sizeof(char*));
    *newItem5 = "Hello";
    char* *newItem6 = malloc(sizeof(char*));
    *newItem6 = "world";
    
    
    SLInsert(sl, newItem1);
    SLInsert(sl, newItem2);
    SLInsert(sl, newItem3);
    SLInsert(sl, newItem4);
    SLInsert(sl, newItem5);
    SLInsert(sl, newItem6);
    SLInsert(sl, newItem1);
    SLInsert(sl, newItem2);
    SLInsert(sl, newItem3);
    SLInsert(sl, newItem4);
    SLInsert(sl, newItem5);
    SLInsert(sl, newItem6);
    printf("\n--------------------------------------\n");
    printStrings(sl);
    printf("\n--------------------------------------\n");
    return 0;
}

//main to run the program just calls test functions, no other functionality
int main(int argc, char **argv){
    test();
    test2();
    //printf("%d\n", sl->next);
    return 0;
    //SortedListPtr sl = malloc(sizeof(SortedListPtr)*100);
}