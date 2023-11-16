// write a menu driven program to implement a doubly linked list & perform the following operations
// insertion at beginning, at end, after a specified node, before a specified node
// deletion at beginning, at end, a specified node
// display forward & backward

// too many fixes not in algorithm to add comments

#include <stdlib.h>
#include <stdio.h>

struct node
{
	int data;
	struct node *next, *prev;
};

struct node *p, *head, *tail, *ptr;
int item;

void insertatbegin()
{
	p = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data:\n");
	scanf("%d", &p->data);
	printf("\n");

	if(head == NULL)
	{
		p->next = NULL;
		p->prev = NULL;
		head = p;
		tail = p;
	}

	else
	{
		p->next = head;
		p->prev = NULL;
		head->prev = p;
		head = p;
	}
}

void insertatend()
{
	p = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data:\n");
	scanf("%d", &p->data);
	printf("\n");

	if(head == NULL)
	{
		p->next = NULL;
		p->prev = NULL;
		head = p;
		tail = p;
	}

	else
	{
		p->next = NULL;
		p->prev = tail;
		tail->next = p;
		tail = p;
	}
}

void insertafter()
{
	if(head == NULL)
	{
		printf("\nList is empty\n\n");
		return;
	}

	p = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data:\n");
	scanf("%d", &p->data);
	p->next = NULL;
	p->prev = NULL;
	ptr = head;
	printf("Enter node after which new node is to be inserted:\n");
	scanf("%d", &item);
	printf("\n");

	while(ptr->data != item)
	{
		if(ptr->next == NULL)
		{
			printf("Node doesn't exist\n\n");
			return;
		}

		ptr = ptr->next;
	}

	if(head == tail)
	{
		ptr->next = p;
		p->prev = ptr;
		tail = p;
	}

	else if(ptr == tail)
	{
		ptr->next = p;
		p->prev = ptr;
		tail = p;
	}

	else
	{
		p->next = ptr->next;
		ptr->next->prev = p;
		ptr->next = p;
		p->prev = ptr;
	}
}

void insertbefore()
{
	if(head == NULL)
	{
		printf("\nList is empty\n\n");
	}

	p = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data:\n");
	scanf("%d", &p->data);
	p->next = NULL;
	p->prev = NULL;
	ptr = head;
	printf("Enter node before which new node is to be inserted:\n");
	scanf("%d", &item);
	printf("\n");

	while(ptr->data != item)
	{
		if(ptr->next == NULL)
		{
			printf("Node doesn't exist\n\n");
			return;
		}

		ptr = ptr->next;
	}

	if(head == tail)
	{
		p->next = ptr;
		ptr->prev = p;
		head = p;
	}

	else if(ptr == head)
	{
		ptr->prev = p;
		p->next = ptr;
		head = p;
	}

	else
	{
		p->prev = ptr->prev;
		ptr->prev->next = p;
		ptr->prev = p;
		p->next = ptr;
	}
}

void delfrombegin()
{
	if(head == NULL)
	{
		printf("\nList is empty\n\n");
	}

	else
	{
		ptr = head;
		head = ptr->next;
		head->prev = NULL;
		printf("\n");
		free(ptr);
	}
}

void delfromend()
{
	if(head == NULL)
	{
		printf("\nList is empty\n\n");
	}

	else
	{
		ptr = tail;
		tail = ptr->prev;
		tail->next = NULL;
		printf("\n");
		free(ptr);
	}
}

void delnode()
{
	if(head == NULL)
	{
		printf("\nList is empty\n\n");
	}

	else
	{
		printf("\nEnter node to delete:\n");
		scanf("%d", &item);
		ptr = head;
		printf("\n");

		while(ptr->data != item)
		{
			if(ptr->next == NULL)
			{
				printf("Node doesn't exist\n\n");
				return;
			}

			ptr = ptr->next;
		}

		if(head == tail)
		{
			head = NULL;
			tail = NULL;
		}

		else if(ptr == head)
		{
			head = ptr->next;
			head->prev = NULL;
		}

		else if(ptr == tail)
		{
			tail = ptr->prev;
			tail->next = NULL;
		}

		else
		{
			ptr->prev->next = ptr->next;
			ptr->next->prev = ptr->prev;
		}

		free(ptr);
	}
}

void display()
{
	ptr = head;
	printf("\nLinked list:\n");

	while(ptr != NULL)
	{
		printf("%d\t", ptr->data);
		ptr = ptr->next;
	}

	printf("\n\n");
}

void displayrev()
{
	ptr = tail;
	printf("\nLinked list:\n");

	while(ptr != NULL)
	{
		printf("%d\t", ptr->data);
		ptr = ptr->prev;
	}

	printf("\n\n");
}

void main()
{
	int ch;
	head = NULL;
	tail = NULL;

	while(1)
	{
		printf("Menu\n");
		printf("1. Insert at beginning\n");
		printf("2. Insert at end\n");
		printf("3. Insert after a specified node\n");
		printf("4. Insert before a specified node\n");
		printf("5. Delete from beginning\n");
		printf("6. Delete from end\n");
		printf("7. Delete a specified node\n");
		printf("8. Display forwards\n");
		printf("9. Display backwards\n");
		printf("Any other value to exit\n");
		printf("Enter choice:\n");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1: insertatbegin();
				break;

			case 2: insertatend();
				break;

			case 3: insertafter();
				break;

			case 4: insertbefore();
				break;

			case 5: delfrombegin();
				break;

			case 6: delfromend();
				break;

			case 7: delnode();
				break;

			case 8: display();
				break;

			case 9: displayrev();
				break;

			default: return;
		}
	}
}
