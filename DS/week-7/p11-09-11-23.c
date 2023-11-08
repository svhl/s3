// write a menu driven c program to implement stack & queue using singly linked list

#include <stdlib.h>
#include <stdio.h>

struct node
{
	int data;
	struct node *next;
};

struct node *p, *top, *front, *rear, *ptr;
int item;

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
		top = top->next;
		printf("\n");
	}
}

void displaystack()
{
	if(top == NULL)
	{
		printf("\nStack is empty\n\n");
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

		printf("\n\n");
	}
}

void enqueuelinear()
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

void dequeuelinear()
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
	}

	printf("\n");
}

void displaylinear()
{
	if(front == NULL)
	{
		printf("\nLinear queue is empty\n");
	}

	else
	{
		ptr = front;
		printf("\nLinear queue:\n");
		
		while(ptr != NULL)
		{
			printf("%d\t", ptr->data);
			ptr = ptr->next;
		}
	}

	printf("\n\n");
}

void enqueuecircular()
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
		rear->next = p;
	}

	else
	{
		rear->next = p;
		p->next = front;
		rear = p;
	}
}

void dequeuecircular()
{
	if(front == NULL)
	{
		printf("\nCircular queue is empty\n");
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
		rear->next = front;
	}

	printf("\n");
}

void displaycircular()
{
	if(front == NULL)
	{
		printf("\nCircular queue is empty\n");
	}

	else
	{
		ptr = front;
		printf("\nCircular queue:\n");
		
		while(ptr != NULL)
		{
			printf("%d\t", ptr->data);

			if(ptr->next == front)
			{
				break;
			}

			ptr = ptr->next;
		}
	}

	printf("\n\n");
}

void main()
{
	int op, ch;
	printf("Menu\n");
	printf("1. Stack\n");
	printf("2. Linear queue\n");
	printf("3. Circular queue\n");
	printf("Enter choice:\n");
	scanf("%d", &op);
	printf("\n");

	if(op == 1)
	{
		top = NULL;

		while(1)
		{
			printf("Menu\n");
			printf("1. Push\n");
			printf("2. Pop\n");
			printf("3. Display\n");
			printf("Any other value to exit\n");
			printf("Enter choice:\n");
			scanf("%d", &ch);

			switch(ch)
			{
				case 1: push();
					break;

				case 2: pop();
					break;

				case 3: displaystack();
					break;

				default: return;
			}
		}
	}

	else if(op == 2 || op == 3)
	{
		front = NULL;
		rear = NULL;
		
		while(1)
		{
			printf("Menu\n");
			printf("1. Enqueue\n");
			printf("2. Dequeue\n");
			printf("3. Display\n");
			printf("Any other value to exit\n");
			printf("Enter choice:\n");
			scanf("%d", &ch);

			switch(ch)
			{
				case 1: if(op == 2)
						enqueuelinear();
					else
						enqueuecircular();
					break;

				case 2: if(op == 2)
						dequeuelinear();
					else
						dequeuecircular();
					break;

				case 3: if(op == 2)
						displaylinear();
					else
						displaycircular();
					break;

				default: return;
			}
		}
	}
}
