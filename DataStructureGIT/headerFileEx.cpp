#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <conio.h>
#pragma warning(disable:4996)


typedef struct s_item {
	int key;
	int val;
	struct s_item* next;
	struct s_item* prev;

} t_Item;

typedef struct {
	int version;
	int serialNum;
	int ItemsCount;
	char reserve[100];
} t_headerFile;

t_Item* Head = NULL;
t_Item* Tail= NULL;
t_headerFile headerFile;

t_Item* NewItem(int val, int key)
{
	t_Item* ret = (t_Item*)malloc(sizeof(t_Item));
	ret->key = key;
	ret->val = val;
	ret->next = NULL;
	ret->prev = NULL;

	if (Head == NULL)
	{
		Head = ret;
		Tail = ret;
	}
	else
	{
		ret->prev = Tail;
		Tail->next = ret;
		Tail = ret;
	}
	return ret;
}

t_Item* search(int key)
{
	 t_Item* ret = NULL;
	 t_Item* curr = Head;

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

void printList()
{
	t_Item* currentItem = Head;
	printf("Head");
	while (currentItem != NULL)
	{
		printf("->(key: %d, val: %d)", currentItem->key, currentItem->val);
		currentItem = currentItem->next;
	}
	printf("->Null\n");
}

void remove(int key)
{
	t_Item* curr;
	curr = search(key);

	if (curr)
	{
		if (curr == Tail && curr != Head)
		{
			Tail = curr->prev;
			Tail->next = NULL;
			free(curr);
		}
		else if (curr == Head && curr != Tail)
		{
			Head = curr->next;
			Head->prev = NULL;
			free(curr);
		}
		else if (curr != Head && curr != Tail && curr != NULL)
		{
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			free(curr);
		}
		else if (curr == Head && curr == Tail)
		{
			free(curr);
			Head = NULL;
			Tail = NULL;
		}
	}
	else
	{
		printf("Not found in the list!\n");
	}
}

void freeList()
{
	t_Item* currentItem = Head;
	t_Item* releaseItem = Head;
	while (currentItem != NULL)
	{
		releaseItem = currentItem;
		currentItem = currentItem->next;
		free(releaseItem);
	}
}


void buildListByFile(char filename[20]) {

	// read from file
	FILE* f = fopen(filename, "r");
	if (!f)
	{
		// error
		
	}

	int read = fread(&headerFile, sizeof(t_headerFile), 1, f);
	if (read == 0)
	{
		// error
	}
	// build the list
	Head = NULL;
	Tail = NULL;

	for (int i = 0; i < headerFile.ItemsCount; i++)
	{
		t_Item* curr = (t_Item*)malloc(sizeof(t_Item));

		read = fread(curr, sizeof(t_Item), 1, f);

		NewItem(curr->val, curr->key);
	}
	fclose(f);
}

void saveListInFile(char filename[20])
{
	int cnt = 0;
	FILE* f = fopen(filename, "w");
	if (!f)
	{
		// error

	}
	fwrite(&headerFile, sizeof(t_headerFile), 1, f);
	t_Item* curr = Head;
	//write all items into file
	while (curr != NULL)
	{
		fwrite(curr, sizeof(t_Item), 1, f);
		curr = curr->next;
		cnt++;
	}
	headerFile.ItemsCount = cnt;
	fclose(f);
}

void askTheUser()
{
	t_Item* toPrint;
	t_Item* toSearchANDUpdate;
	char userResponse = NULL;
	char fileName[20];
	int numvalue, numkey, searchKey;

	while (userResponse != 'E')
	{
		printf("Hi Dear User \n What would you like to do?\n A-to add new item  P-Print all list R-Pop next item E-to exit");
		scanf(" %c", &userResponse);
	
	switch (userResponse)
	{
	case 'A':
		printf("Hi Dear User \n Please enter 2 numberS, the first will be the key and the second will be the value");
		scanf("%d %d",&numkey, &numvalue);
		NewItem(numkey, numvalue);
		headerFile.ItemsCount++;
		printList();
		break;
	case 'F': printf("Which key do you want to serach and print:");
		scanf("%d", &searchKey);
		toPrint = search(searchKey);
		if(toPrint)
		{ 
		printf("the key you search is found and his value is: %d", toPrint->val);
		}
	else
		{
			printf("the key you search isn't found ***");
		}
		break;
	case 'U':
		printf("Hi Dear User \n Please enter 2 NEW numberS, and the program will update them. the first will be the key and the second will be the value ");
		scanf("%d",&numkey);
		scanf("%d",&numvalue);
		toSearchANDUpdate = search(numkey);
		if(toSearchANDUpdate)
		{
			printf("the key you search is found and it is:%d and now we will change it", toSearchANDUpdate->key);
			toSearchANDUpdate->val = numvalue;
			toSearchANDUpdate->key = numkey;
		}
		else
		{
			printf("the key you search isn't found ***");
		}
		
		break;
	case 'D': printf("Which key do you want to serach and delete:\n");
		scanf("%d",&searchKey);
		remove(searchKey);
		printList();
		break;
	case 'S': printf("glad you want to save the program (: what is the file name you want %s");
		scanf("%s", fileName);
		saveListInFile(fileName);
		break;
	case 'L': printf("Hi what is the file name you search:");
		scanf("%s",fileName);
		buildListByFile(fileName);
		break;
	case 'E': printf("Thank you for use our Great service. See you next time. Drink only water\n");
		break;
	case 'P': printList();
		break;

	default:
		printf("Wrong selection. Try be more sharp\n");
		break;
	}
	}
}




int main()
{
	headerFile.version = 1;
	headerFile.ItemsCount = 0;
	headerFile.serialNum = 12345;

	askTheUser();

    return 0;
}

