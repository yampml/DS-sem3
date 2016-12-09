#include<stdio.h>
#include<stdlib.h>
struct node
{
	int item;
	struct node *next;
};

void init(struct node **head, int *count);//
void insert(struct node **head, int item, int index, int *count);//
void del(struct node **head, int index, int *count);//
bool isEmpty(struct node *head);//
void printList(struct node *head);//
void destroyList(struct node **head, int *count);//
void removeDuplicate(struct node **head, int *count);
void copyList(struct node *head1, int count1, struct node **head2, int *count2);

int main()
{
	struct node *head1;
	int count1;
	init(&head1, &count1);
//	printf("%d\n", isEmpty(head1));
	
//	for(int i=0; i<10; i++) insert(&head1, i, i, &count1);
	insert(&head1, 4, 0, &count1);
	insert(&head1, 4, 0, &count1);
	insert(&head1, 3, 0, &count1);
	insert(&head1, 3, 0, &count1);
	insert(&head1, 3, 0, &count1);
	insert(&head1, 2, 0, &count1);
	insert(&head1, 2, 0, &count1);
	insert(&head1, 1, 0, &count1);
	insert(&head1, 1, 0, &count1);
	insert(&head1, 1, 0, &count1);
	insert(&head1, 1, 0, &count1);
	
	removeDuplicate(&head1, &count1);
	
	printList(head1);
	printf("\n");
	
	printf("Danh sach trong(0/1) :%d", isEmpty(head1));
//	printList(head1);

}

void init(struct node **head, int *count)
{
	*head = NULL;
	*count = 0;
}

void insert(struct node **head, int item, int index, int *count)
{
	if(index >= 0 && index<=(*count)){
		struct node *newNode = (struct node *) malloc(sizeof(struct node));	
		newNode->item = item;
		newNode->next = NULL;
		if(index == 0)
		{
			newNode->next = *head;
			*head = newNode;	
		}
		else
		{
			struct node *cur = *head;
			for(int i=0; i<index-1; i++) cur = cur->next;
			newNode->next = cur->next;
			cur->next = newNode;
		}
		(*count)++;
	}
}

void del(struct node **head, int index, int *count)
{
	if(index>=0 && index<(*count))
	{
		struct node *temp = *head;
		if(index == 0)
		{
			*head = temp->next;
		}
		else
		{
			struct node *cur = *head;
			for(int i=0; i<index-1; i++) cur = cur->next;
			temp = cur->next;
			cur->next = temp->next;
		}
		free(temp);
		(*count)--;
	}
}

bool isEmpty(struct node *head)
{
	return head == NULL;
}

void printList(struct node *head)
{
	struct node *cur = head;
	while(cur!=NULL)
	{
		printf("%d ", cur->item);
		cur = cur->next;
	}
}

void destroyList(struct node **head, int *count)
{
	struct node *cur = *head;
	while((*head) != NULL)
	{
		*head = (*head)->next;
		free(cur);
		cur = *head;
	}
	(*count) = 0;
	
//	while(*head != NULL) del(head, 0, count);
}

/*
void removeDuplicate(struct node **head, int *count)
{
	int index;;
	struct node *cur, *curNext;
	
	index = 0;
	cur = *head;
	curNext = cur->next;
	
	while(curNext != NULL)
	{
		if(cur->item == curNext->item)
		{
			curNext = curNext->next;
			del(head, index+1, count);
		}
		else
		{
			cur = cur->next;
			curNext = cur->next;
			index++;	
		}
	}
	
}
*/

void removeDuplicate(struct node **head, int *count)
{
	struct node *cur, *curNext;
	
	cur = *head;
	curNext = cur->next;
	
	while(curNext != NULL)
	{
		if(cur->item == curNext->item)
		{
			cur->next = curNext->next;		
			free(curNext);
			curNext = cur->next;
			(*count)--;
		}
		else
		{
			cur = cur->next;
			curNext = cur->next;
		}
	}
	
}



