#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#pragma warning(disable : 4996)

struct Item {
	int key;
	int val;
	struct Item* next;
	struct Item* prev;
};

struct Item* head = NULL;
struct Item* tail = NULL;

void push(int key, int val);


void printList()
{
	struct Item* currentItem = head;
	printf("Head");
	while (currentItem != NULL)
	{
		printf("->(key: %d, val: %d)", currentItem->key, currentItem->val);
		currentItem = currentItem->next;
	}
	printf("->Null\n");
}

void freeList()
{
	struct Item* currentItem = head;
	struct Item* releaseItem = head;
	while (currentItem != NULL)
	{
		releaseItem = currentItem;
		currentItem = currentItem->next;
		free(releaseItem);
	}
}

void resetList()
{
	if (head != NULL)
	{
		freeList();
		head = NULL;
		tail = NULL;
	}
}

void push(int key, int val)
{
	struct Item* curr;
	curr = (struct Item*)malloc(sizeof(struct Item));
	curr->key = key;
	curr->val = val;

	if (head == NULL)
	{
		head = curr;
		tail = curr;
		curr->next = NULL;
		curr->prev = NULL;
	}
	else
	{
		tail->next = curr;
		curr->prev = tail;
		curr->next = NULL;
		tail = curr;
	}
}

struct Item* search(int key)
{
	struct Item* ret = NULL;
	struct Item* curr = head;

	while (curr != NULL)
	{
		if (curr->key == key)
		{
			ret = curr;
			return ret;
		}
		curr = curr->next;
	}
	return ret;
}

void pop(int key)
{
	struct Item* curr;
	curr = search(key);

	if (curr)
	{
		if (curr == tail && curr != head)
		{
			tail = curr->prev;
			tail->next = NULL;
			free(curr);
		}
		else if (curr == head && curr != tail)
		{
			head = curr->next;
			head->prev = NULL;
			free(curr);
		}
		else if (curr != head && curr != tail && curr != NULL)
		{
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			free(curr);
		}
		else if (curr == head && curr == tail)
		{
			free(curr);
			head = NULL;
			tail = NULL;
		}
	}
	else
	{
		printf("Not found in dictionary!\n");
	}
}

void switchANDcase(char c) {
	int  key, val, id;
	struct Item* show;

	while (c != 'E')
	{
		switch (c)
		{
		case 'A':
			printf("Please enter key and value\n");
			scanf("%d %d", &key, &val);
			push(key, val);
			break;

		case 'P':
			if (head != NULL && tail != NULL)
			{
				printList();
			}
			else
			{
				printf("NULL\n");
			}
			printf("***********\n");
			break;

		case 'R':
			printf("Please enter key for removing\n");
			scanf("%d", &id);
			pop(id);
			break;

		case 'S':
			printf("Please enter key to show value\n");
			scanf("%d", &id);
			show = search(id);

			(show) ? printf("The value is: %d\n", show->val) : printf("this key does not exist in dictionary\n");
			break;

		default:
			printf("Wrong selection. Try be more sharp\n");
			break;
		}

		printf("Please choose what to do. A- for adding, P- for printing dictionary,S- for show value, R-for removing, E- for exit.\n");
		scanf(" %c", &c);
	}
	printf("Thank you for use our Great service. See you next time. Drink only water\n");

}

int main()
{
	
	char userResponse;
	printf("Please choose what to do. A- for adding, P- for printing dictionary,S- for show value, R-for removing, E- for exit.\n");
	scanf(" %c", &userResponse);
	switchANDcase(userResponse);

	
	return 0;
}