// write a menu driven c program to implement stack operations using array

#include <stdio.h>
void main()
{
	int n, ch, stack[50], top = -1, item, i;
	printf("Enter no. of elements in stack:\n");
	scanf("%d", &n);

	while(1)
	{
		printf("\nMenu\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Peek\n");
		printf("4. Display\n");
		printf("Any other value to exit\n");
		printf("Enter choice:\n");
		scanf("%d", &ch);

		if(ch == 1)
		{
			if(top == n-1)
			{
				printf("\nStack full\n");
			}

			else
			{
				top++;
				printf("\nEnter element to push:\n");
				scanf("%d", &item);
				stack[top] = item;
			}
		}

		else if(ch == 2)
		{
			if(top == -1)
			{
				printf("\nStack empty\n");
			}

			else
			{
				top--;
			}
		}

		else if(ch == 3)
		{
			if(top != -1)
			{	
				printf("\n%d\n", stack[top]);
			}
		}

		else if(ch == 4)
		{
			if(top == -1)
			{
				printf("\nStack empty\n");
			}

			else
			{
				printf("\n");

				for(i = top; i >= 0; i--)
				{
					printf("%d\n", stack[i]);
				}
			}
		}

		else
		{
			return;
		}
	}
}
