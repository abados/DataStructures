#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)
void task3();
void PrintList();
void Print44();
void findId(int id);

int main_01() {
    task3();
 //   PrintList();
 //   Print44();
    findId(123);
//    int num_of_struct = 1;
//
//
//    struct cityD
//    {
//        int id;
//        int pop;
//        int numOfMalls;
//        int numOfSchools;
//        int numOfTrees;
//    };
//
//    struct cityD* list;
//    struct cityD* moving_list;
//
//    printf("Please chose how many struct you want to enter:\n");
//
//    scanf("%d", &num_of_struct);
//
//    list = (struct cityD*)malloc(sizeof(struct cityD) * num_of_struct);
//
//    moving_list = list;
//
//
//    for (int i = 0; i < num_of_struct; i++) {
//
//        printf("Please write the city ID, population amount, number of malls, number of schools and the number of trees in the city:");
//        scanf("%d%d%d%d%d", &moving_list->id, &moving_list->pop, &moving_list->numOfMalls, &moving_list->numOfSchools, &moving_list->numOfTrees);
//        moving_list++;
//    }
//
//    FILE* f = fopen("linkedlistStart.dat", "w");
//    if (f == NULL)
//    {
//        //ERROR
//    }
//    else
//    {
//        //arr=&arr[0]
//        int written = fwrite(list, sizeof(struct cityD), num_of_struct, f);
//        fclose(f);
//    }
//    return 0;
//}
//
//void task2()
//{
//    FILE* f = fopen("week3class1.bin", "r");
//
//    if (f == NULL)
//    {
//        //ERROR
//    }
//    else
//    {
//        int sum = 0;
//        int* point = (int*)malloc(sizeof(int) * 3);
//        while (fread(point, sizeof(int) * 3, 1, f))
//        {
//            sum += *point;
//        }
//
//        fclose(f);
//        printf("%d", sum);
//    }
//    
}

struct Box
{
    int val;
    struct Box* next;
};

struct Box* thebox;          //current
struct Box* lastbox = NULL;
struct Box* printbox = NULL; //head

void task3() {

   
    int userChoice;
    
    printf("please enter a number if you want to exit enter 100 \n");
    scanf("%d", &userChoice);
    while (userChoice != 100)
    {
        thebox = malloc(sizeof(struct Box));
        if (printbox == NULL)
        {
            printbox = thebox;
        }
        else
        {
            lastbox->next = thebox; //קישור הנקסט לתא הבא בתור
        }

        printf("please enter a number :");
        scanf("%d", &thebox->val);

        printf("please enter a number if you want to exit enter 100 \n");
        scanf("%d", &userChoice);

        thebox->next = NULL;
        lastbox = thebox;

    }

}
void PrintList() {
    struct Box* task4ptr = printbox;
    while (task4ptr!=NULL) {
        printf("%d ", task4ptr->val);
        task4ptr = task4ptr->next;
    }
}

void Print44() {
    struct Box* task5ptr = printbox;
    int counter44 = 0;
    while (task5ptr != NULL) {
        if (task5ptr->val==44)
        {
            counter44++;
        }
        task5ptr = task5ptr->next;
    }
    printf("\n");
    printf("%d", counter44);
}

void findId(int id) {
    struct Box* task6ptr = printbox;
    int counterPos = 0;
    int idPos = 0;
    while (task6ptr != NULL) {
        counterPos++;
        if (task6ptr->val == id)
        {
            idPos = counterPos;
        }
        task6ptr = task6ptr->next;
    }
    printf("\n");
    printf("%d", idPos);
}

