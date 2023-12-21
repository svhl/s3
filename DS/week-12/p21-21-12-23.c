// write a menu-driven program to implement a hash table & the following collision resolution techniques
// linear probing 
// quadratic probing

#include <stdio.h>
#include <stdlib.h>

int size;
int *hashtable;

void initialize()
{
	hashtable = (int *)malloc(size * sizeof(int));

	for(int i = 0; i < size; i++)
	{
		hashtable[i] = -1;
	}
}

int hashfn(int key)
{
	return (key % size); 
}

void linear(int key)
{
	int index = hashfn(key);

	while(hashtable[index] != -1)
	{
		index = (index + 1) % size; 
	}

	hashtable[index] = key;
}

void quadratic(int key)
{
	int index = hashfn(key), i = 1;

	while(hashtable[index] != -1)
	{
		index = (index + i * i) % size; 
		i++;
	}

	hashtable[index] = key;
}

void display()
{
	printf("\nIndex\tKey\n");

	for(int i = 0; i < size; i++)
	{
		printf("%d\t%d\n", i, hashtable[i]);
	}
}

void main()
{
	printf("Enter size of hash table: ");
	scanf("%d", &size);
	initialize();
	int ch, key;

	while(1)
	{
		printf("\nMenu:\n");
		printf("1. Linear probing\n");
		printf("2. Quadratic probing\n");
		printf("3. Display\n");
		printf("Any other value to exit\n");
		printf("Enter choice:\n");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1:
				printf("\nEnter key:\n");
				scanf("%d", &key);
				linear(key);
				break;
				
			case 2:
				printf("\nEnter key:\n");
				scanf("%d", &key);
				quadratic(key);
				break;
				
			case 3:
				display();
				break;
				
			default:
					return;
		}
	}
}
