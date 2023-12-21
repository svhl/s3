// write a menu-driven program to implement a hash table & the following collision resolution techniques
// linear probing 
// quadratic probing

#include <stdio.h>

int size;

int hash(int key)
{
	int i = key % size ;
	return i;
}

int linear(int key)
{
	int h = (key + 1) % size ;
	return h ;
}

int quadratic(int key, int i)
{
	int h = (key + (i * i)) % size ;
	return h ;
}

void main()
{
	int key, a[50], table[50], i, n, ch, j, k;
	printf ("Enter size of hash table:\n");
	scanf("%d", &size);
	printf ("Enter no. of elements:\n");
	scanf("%d", &n);
	
	for(i = 0; i < size; i++)
	{
		table[i] = -1;
	}
	
	for(i = 0; i < n; i++)
	{
		printf("Enter element %d:\n", i);
		scanf("%d", &a[i]);
	}
	
	while(1)
	{
		printf("\nMenu\n");
		printf("1. Linear probing\n");
		printf("2. Quadratic probing\n");
		printf("Any other value to exit\n");
		printf("Enter choice:\n");
		scanf("%d", &ch);
		
		if(ch==1)
		{
			for(i = 0; i < size; i++)
			{
				table[i] = -1;
			}
			
			for(k = 0; k < n; k++)
			{
				key = a[k];
				i = hash(key);
				
				while(table[i] != -1)
				{
					i = linear(i);
				}
				
				table[i] = key;
			}
			
			for(i = 0; i < size; i++)
			{
				printf("\nElement at %d: %d", i, table[i]);
			}
			
			printf("\n");
		}
		
		else if(ch == 2)
		{
			for(i = 0; i < size; i++)
			{
				table[i] = -1;
			}
			
			for(k = 0; k < n; k++)
			{
				j = 1;
				key = a[k];
				i = hash(key);
				
				while(table[i]!=-1)
				{
					i = quadratic(i, j);
					j++;
				}
				
				table[i]=key ;
			}
			
			for(i = 0; i < size; i++)
			{
				printf("\nElement at %d: %d", i, table[i]);
			}
			
			printf("\n");
		}
		
		else
		{
			return;
		}
	}
}
