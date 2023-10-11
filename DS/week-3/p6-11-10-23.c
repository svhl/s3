// write a menu driven c program to implement deque using arrays & perform the following operations
// insert at front, insert at rear, delete from front, delete from rear, display

#include <stdio.h>

void main()
{
	int n, ch, queue[50], front = 0, rear = 0, item, i;
	printf("Enter no. of elements in deque:\n");
	scanf("%d", &n);

	while(1)
	{
		printf("\nMenu\n");
		printf("1. Insert at front\n");
		printf("2. Insert at rear\n");
		printf("3. Delete from front\n");
		printf("4. Delete from rear\n");
		printf("5. Display\n");
		printf("Any other value to exit\n");
		printf("Enter choice:\n");
		scanf("%d", &ch);

		if(ch == 1)
		{
			if((rear + 1) % n == front)
			{
				printf("\nDeque is full\n");
			}

			else
			{
				printf("\nEnter element to insert:\n");
				scanf("%d", &item);
				queue[front] = item;

				if(front == 0)
				{
					front = n - 1;
				}

				else
				{
					front = (front - 1) % n;
				}
			}
		}

		else if(ch == 2)
		{
			if((rear + 1) % n == front)
			{
				printf("\nDeque is full\n");
			}

			else
			{
				rear = (rear + 1) % n;
				printf("\nEnter element to insert:\n");
				scanf("%d", &item);
				queue[rear] = item;
			}
		}

		else if(ch == 3)
		{
			if(front == rear)
			{
				printf("\nDeque is empty\n");
			}

			else
			{
				front = (front + 1) % n;
				item = queue[front];
				printf("\nRemoved element %d\n", item);
			}
		}

		else if(ch == 4)
		{
			if(front == rear)
			{
				printf("\nDeque is empty\n");
			}

			else
			{
				item = queue[rear];
				printf("\nRemoved element %d\n", item);

				if(rear == 0)
				{
					rear = n - 1;
				}

				else
				{
					rear = (rear - 1) % n;
				}
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
