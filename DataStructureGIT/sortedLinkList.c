#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)

struct item* HEAD = NULL;
struct item* TAIL = NULL;
struct item* currentItem;
struct item* kodem;


struct item {
    int val;
    struct item* next;
    struct item* prev;
};



void generateList() {
    
    int num = rand();
  
    currentItem = (struct item*)malloc(sizeof(struct item));
    
    if (HEAD == NULL)  {
        HEAD = currentItem;
        TAIL = currentItem;
        currentItem->next = NULL;
        currentItem->prev = NULL;
    }
    else
    {
       
        TAIL = currentItem;
        currentItem->next = NULL;
        kodem->next = currentItem;
        currentItem->prev = kodem;
    }
    currentItem->val = num;
    kodem=currentItem;
}

void printList() {
    struct item* runPtr = HEAD;
    //struct Item* prevPtr = HEAD;

    printf("HEAD->");
    while (runPtr != NULL) {
        printf("(%d)->\n", runPtr->val);
        runPtr = runPtr->next;
    }
    printf("NULL");
}

void freeList() {
    struct item* runPtr=HEAD;
    struct item* runPtrPrev = HEAD;

    while (runPtr)
    {
        runPtr = runPtr->next;
        free(runPtrPrev);
        runPtrPrev = runPtr;
    }
    free(runPtrPrev);
}

void generateXList(int x)
{
    for (int j = 0; j < x; j++)
    {
        generateList();
    }

}

void findNum(int num) {
    struct item* task13ptr = HEAD;
    int NumPos = 0;
    while (task13ptr != NULL) {
        if (task13ptr->val == num)
        {
            NumPos = task13ptr;
        }
        task13ptr = task13ptr->next;
    }
    printf("\n");
    printf("%p", NumPos);
}

void changeVal(int newVal, int oldVal)
{
    struct item* task15ptr = HEAD;
    int NumPos = 0;
    while (task15ptr != NULL) {
        if (task15ptr->val == oldVal)
        {
            NumPos = task15ptr;
            task15ptr->val = newVal;

            if (NumPos)
                printf("\nvalue was found at %p location ", NumPos);

        }
        task15ptr = task15ptr->next;
    }
}

void resetList()
{
    if (HEAD != NULL)
    {
        freeList();
        HEAD = TAIL = NULL;
    }
}

void insertNewItem(int val) {
  
    currentItem = (struct item*)malloc(sizeof(struct item));

    if (HEAD == NULL) {
        HEAD = currentItem;
        TAIL = currentItem;
        currentItem->next = NULL;
        currentItem->prev = NULL;
    }
    else if(val>kodem->val)
            {
            TAIL = currentItem;
            currentItem->next = NULL;
            kodem->next = currentItem;
            currentItem->prev = kodem;
            }
    else
    {
        currentItem->next = HEAD;
        HEAD = currentItem;
        currentItem->prev = NULL;
        currentItem->next = kodem;
                                
    }
    currentItem->val = val;
    kodem = currentItem;

}

int main()
{
    time_t i = time();
    srand(i);

   /* for (int j = 0; j < 10; j++)
    {
        generateList();
    }

    printList();*/

    printf("\n\n\n");
   
    generateXList(5);

    printList();

    findNum(15034);

    changeVal(20, 25253);

    generateXList(100);

    printList();

    resetList();
    
    insertNewItem(6);
    insertNewItem(4);
    insertNewItem(1);
    //insertNewItem(2);
    /* insertNewItem(5);
    insertNewItem(7);*/
    printList();
    return 0;
}

