// write a menu driven c program to implement circular queue using arrays & perform the following operations
// insert, delete, is empty, is full, display

#include <stdio.h>
void main()
{
	int n, ch, queue[50], front = 0, rear = 0, item, i;
	printf("Enter no. of elements in circular queue:\n");
	scanf("%d", &n);
	
	while(1)
	{
		printf("\nMenu\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Is empty?\n");
		printf("4. Is full?\n");
		printf("5. Display\n");
		printf("Any other value to exit\n");
		printf("Enter choice:\n");
		scanf("%d", &ch);

		if(ch == 1)
		{
			if((rear + 1) % n == front)
			{
				printf("\nQueue is full\n");
			}

			else
			{
				rear = (rear + 1) % n;
				printf("\nEnter element to enqueue:\n");
				scanf("%d", &item);
				queue[rear] = item;
			}
		}

		else if(ch == 2)
		{
			if(front == rear)
			{
				printf("\nQueue is empty\n");
			}

			else
			{
				front = (front + 1) % n;
				item = queue[front];
				printf("\nDequeued element %d\n", item);
			}
		}

		else if(ch == 3)
		{
			if(front == rear)
			{
				printf("\nQueue is empty\n");
			}

			else
			{
				printf("\nQueue isn't empty\n");
			}
		}

		else if(ch == 4)
		{
			if((rear + 1) % n == front)
			{
				printf("\nQueue is full\n");
			}

			else
			{
				printf("\nQueue isn't full\n");
			}
		}

		else if(ch == 5)
		{
			if(front == rear)
			{
				printf("\nQueue is empty\n");
			}

			else
			{
				printf("\n");

				for(i = (front + 1) % n; i != (rear + 1) % n; i = (i + 1) % n)
				{
					printf("%d\n", queue[i]);
				}
			}
		}

		else
		{
			return;
		}
	}
}

