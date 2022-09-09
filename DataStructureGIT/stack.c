#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)
void  Push(int val1, int val2);

struct Item* HEAD;
struct Item* TAIL;
int ID_COUNTER = 1;

struct Item {
    int val1;
    int val2;
    int id;
    struct Item* next;
    struct Item* prev;
};

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

    struct Item* runMover = HEAD;

    if(HEAD)
    { 
    if (HEAD->next != NULL) {
        HEAD = runMover->next;
        HEAD->prev = NULL;
        free(runMover);
    }
    else
    {
        HEAD = TAIL = NULL;
        free(runMover);
    }
    }
    else
    {
        printf("\nThe link list is empty\n");
    }

}

void  Push(int val1, int val2)
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
    else {
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

int main()
{
   
    srand(time(NULL));

    char userResponse = NULL;
    while (userResponse != 'E')
    {
        printf("please choose E - for exit,\n I - for Insert,\n P - for pop,\n L - for print,\n B - for bulk insert,\n Z - many 10 Pop's\n");
        userResponse = getch();

        switch (userResponse)
        {
        case 'I':

            Push(rand(), rand());
            printList();
            break;

        case 'P':  Pop();
            printList();
                    
            break;

        case 'L': printList();
            break;

        case 'B': for (int i = 0; i < 100; i++) {
            Push(rand(), rand());
        }
            break;

        case 'E': printf("Thank you for use our Great service. See you next time. Drink only water\n");
            break;

        case 'Z': for (int i = 0; i < 100; i++) {
            pop();
        }
            break;

        default:
            printf("Wrong selection. Try be more sharp\n");
            break;
        }
    }

    return 0;
}
