// write a menu driven c program to implement stack & queue using singly linked list

#include <stdlib.h>
#include <stdio.h>

struct node
{
	int data;
	struct node *next;
};

struct node *p, *top, *front, *rear, *ptr;

void push()
{
	p = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data:\n");
	scanf("%d", &p->data);
	printf("\n");

	if(top == NULL)
	{
		p->next = NULL;
		top = p;
	}

	else
	{
		p->next = top;
		top = p;
	}
}

void pop()
{
	if(top == NULL)
	{
		printf("\nStack is empty\n\n");
	}

	else
	{
		ptr = top;
		top = top->next;
		free(ptr);
		printf("\n");
	}
}

void display()
{
	if(top == NULL)
	{
		printf("\nStack is empty");
	}

	else
	{
		ptr = top;
		printf("\nStack:\n");

		while(ptr != NULL)
		{
			printf("%d\t", ptr->data);
			ptr = ptr->next;
		}
	}
	
	if(front == NULL)
	{
		printf("\n\nQueue is empty\n\n");
	}

	else
	{
		ptr = front;
		printf("\n\nQueue:\n");

		while(ptr != NULL)
		{
			printf("%d\t", ptr->data);
			ptr = ptr->next;
		}

		printf("\n\n");
	}
}

void enqueue()
{
	p = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data:\n");
	scanf("%d", &p->data);
	printf("\n");
	p->next = NULL;

	if(front == NULL)
	{
		front = p;
		rear = p;
	}

	else
	{
		rear->next = p;
		rear = p;
	}
}

void dequeue()
{
	if(front == NULL)
	{
		printf("\nLinear queue is empty\n");
	}

	else if(front == rear)
	{
		front = NULL;
		rear = NULL;
	}

	else
	{
		ptr = front;
		front = ptr->next;
		free(ptr);
	}

	printf("\n");
}

void main()
{
	top = NULL;
	front = NULL;
	rear = NULL;
	int ch;
	
	while(1)
	{
		printf("Menu\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Enqueue\n");
		printf("4. Dequeue\n");
		printf("5. Display\n");
		printf("Any other value to exit\n");
		printf("Enter choice:\n");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1: push();
				break;
				
			case 2: pop();
				break;
				
			case 3: enqueue();
				break;
				
			case 4: dequeue();
				break;
				
			case 5: display();
				break;
				
			default: return;
		}
	}
}
