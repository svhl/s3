// write a menu-driven program to implement the following operations on a singly linked list
// insert at beginning
// insert at end
// insert after a specified node
// delete from beginning
// delete from end
// delete a specified node
// display

#include <stdlib.h>
#include <stdio.h>

struct node
{
	int data;
	struct node *next;
};

struct node *p, *head, *tail, *ptr, *prev;
int item;

void insertatbegin()
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
		p->next = head;
		head = p;
	}
}

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

void insertafter()
{
	p = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data:\n");
	scanf("%d", &p->data);
	p->next = NULL;
	ptr = head;
	printf("Enter node after which new node is to be inserted:\n");
	scanf("%d", &item);
	printf("\n");
	
	while(ptr->data != item)
	{
		ptr = ptr->next;
	}
	
	p->next = ptr->next;
	ptr->next = p;
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
		printf("\n");
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
		ptr = head;
		
		while(ptr->next != NULL)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		
		prev->next = NULL;
		tail = prev;
		printf("\n");
	}
}

void delafter()
{
	if(head == NULL)
	{
		printf("\nList is empty\n\n");
	}
	
	else
	{
		printf("Enter node to delete:\n");
		scanf("%d", &item);
		ptr = head;
		
		while(ptr->data != item)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		
		prev->next = ptr->next;
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
		printf("1. Insert at beginning\n");
		printf("2. Insert at end\n");
		printf("3. Insert after a specified node\n");
		printf("4. Delete from beginning\n");
		printf("5. Delete from end\n");
		printf("6. Delete a specified node\n");
		printf("7. Display\n");
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
			
			case 4: delfrombegin();
				break;
			
			case 5: delfromend();
				break;
			
			case 6: delafter();
				break;

			case 7: display();
				break;

			default: return;
		}
	}
}
