// write a program to implement a priority queue using singly linked list
// add an element
// delete an element
// display

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data, priority;
	struct node *next;
};

struct node *p, *front, *rear, *ptr, *prev;
int item;

void insert()
{
	p = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data:\n");
	scanf("%d", &p->data);
	printf("Enter priority:\n");
	scanf("%d", &p->priority);
	printf("\n");

	if(front == NULL)
	{
		p->next = NULL;
		front = p;
		rear = p;
	}
	
	else
	{
		ptr = front;
		
		// first element
		if(ptr->priority >= p->priority)
		{
			p->next = ptr;
			front = p;
			return;
		}
		
		while(ptr->priority < p->priority)
		{
			//last element
			if(ptr->next == NULL)
			{
				ptr->next = p;
				p->next = NULL;
				rear = p;
				return;
			}
			
			prev = ptr;
			ptr = ptr->next;
		}
		
		prev->next = p;
		p->next = ptr;
	}
}

void delfromfront()
{
	if(front == NULL)
	{
		printf("\nQueue is empty\n\n");
	}
	
	else
	{
		ptr = front;
		front = ptr->next;
		printf("\n");
		free(ptr);
	}
}

void delnode()
{
	if(front == NULL)
	{
		printf("\nQueue is empty\n\n");
	}
	
	else
	{
		printf("\nEnter node to delete:\n");
		scanf("%d", &item);
		ptr = front;
		printf("\n");
		
		if(ptr->data == item && front == rear)
		{
			front = NULL;
		}
		
		else
		{
			while(ptr->data != item)
			{
				if(ptr->next == NULL)
				{
					printf("Node doesn't exist\n\n");
					return;
				}
				
				prev = ptr;
				ptr = ptr->next;
			}

			if(ptr == front)
			{
				front = ptr->next;
				return;
			}

			prev->next = ptr->next;

			if(prev->next == NULL)
			{
				rear = prev;
			}
		}

		free(ptr);
	}
}

void display()
{
	ptr = front;
	printf("\nPriority queue:\n");

	while(ptr != NULL)
	{
		printf("%d\t%d\n", ptr->data, ptr->priority);
		ptr = ptr->next;
	}

	printf("\n");
}

void main()
{
	int ch;
	front = NULL;
	rear = NULL;

	while(1)
	{
		printf("Menu\n");
		printf("1. Insert based on priority\n");
		printf("2. Delete from front\n");
		printf("3. Delete a specified node\n");
		printf("4. Display\n");
		printf("Any other value to exit\n");
		printf("Enter choice:\n");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1: insert();
				break;

			case 2: delfromfront();
				break;
			
			case 3: delnode();
				break;

			case 4: display();
				break;

			default: return;
		}
	}
}
