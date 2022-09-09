
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)

struct Item* HEAD;
struct Item* TAIL;
int ID_COUNTER=1;

struct Item {
    int val1;
    int val2;
    int id;
    struct Item* next;
    struct Item* prev;
};

void  Push (int val1, int val2)
{
    struct Item* currentItem = (struct Item*)malloc(sizeof(struct Item));

    if (HEAD == NULL) {
        HEAD = currentItem;
        TAIL = currentItem;
        currentItem->next = NULL;
        currentItem->prev = NULL;
        currentItem->val1 = val1;
        currentItem->val2 = val2;
        currentItem->id = ID_COUNTER;
        ID_COUNTER++;
    }
    else{
    currentItem->val1 = val1;
    currentItem->val2 = val2;
    currentItem->id = ID_COUNTER;
    currentItem->next = HEAD;
    currentItem->prev = NULL;
    HEAD->prev = currentItem;
    HEAD = currentItem;
    ID_COUNTER++;
    }
}

void printList() {
    struct Item* runPtr = HEAD;
    //struct Item* prevPtr = HEAD;


    if (runPtr == NULL)
    {
        printf("\nThe link list is empty\n");
        
    }
    while (runPtr != NULL) {
        printf("HEAD->");
        printf("(VAL1:%d VAL2:%d ID:%d  )-> ", runPtr->val1, runPtr->val2, runPtr->id);
        runPtr = runPtr->next;
    }
    printf("\n");
    
    
}

 struct Item* Pop() {

     struct Item* runMover = TAIL;
     if(TAIL->prev!=NULL){
      TAIL= runMover->prev ;
     TAIL->next = NULL;
     free(runMover);
     }
     else
     {
         HEAD = TAIL = NULL;
         free(runMover);
     }
     
}

int main()
{
    Push(1, 2);
    printList();
    Push(3, 4);
    printList();
    Push(5, 6);
    printList();
    Push(7, 8);
    printList();
    Pop();
    printList();
    Pop();
    printList();
    Pop();
    printList();
    Pop();
    printList();
   

    
    for (int i = 0; i < 4;i++)//אקראי בחרתי כמה פעמים אני רוצה שירוץ
    {
    printf("please enter a number:1,2,3 or 4 for exit");

    int x = 0;
    scanf("%d", &x);
    if (x == 1)
    {
        time_t t = time(NULL);
        srand(t);
        int num1 = rand();
        int num2 = rand();
        Push(num1, num2);
    }
    else if (x == 2)
    {
        printList();
    }
    else if (x==3)
    {
        Pop();
        printList();
    }
    else if (x == 3)
    {
        return;
    }
    }
    return 0;
}
