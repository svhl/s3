#include <stdlib.h>
#include <stdio.h>

struct node
{
	int data;
	struct node *next;
};

struct node *p, *head, *tail, *ptr;

void insertatend()
{
	p = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data:\n");
	scanf("%d", &p->data);
	printf("\n");
	p->next = NULL;

	if(head == NULL)
	{
		head = p;
		tail = p;
	}

	else
	{
		tail->next = p;
		tail = p;
	}
}

void display()
{
	ptr = head;
	printf("\nLinked list:\n");

	while(ptr != NULL)
	{
		printf("%d\t", ptr->data);
		ptr = ptr-> next;
	}

	printf("\n\n");
}

void main()
{
	int ch;
	head = NULL;

	while(1)
	{
		printf("Menu\n");
		printf("1. Insert at end\n");
		printf("2. Dsiplay\n");
		printf("Any other value to exit\n");
		printf("Enter choice:\n");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1: insertatend();
				break;

			case 2: display();
				break;

			default: return;
		}
	}
}
