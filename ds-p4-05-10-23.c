// write a menu driven c program to implement linear queue operations using array

#include <stdio.h>
void main()
{
	int n, ch, queue[50], front = -1, rear = -1, item, i;
	printf("Enter no. of elements in queue:\n");
	scanf("%d", &n);

	while(1)
	{
		printf("\nMenu\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Display\n");
		printf("Any other value to exit\n");
		printf("Enter choice:\n");
		scanf("%d", &ch);

		if(ch == 1)
		{
			if(rear == n-1)
			{
				printf("\nQueue is full\n");
			}

			else
			{
				rear++;
				printf("Enter element to enqueue:\n");
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
				front++;
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
				printf("\n");

				for(i = front+1; i <= rear; i++)
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
