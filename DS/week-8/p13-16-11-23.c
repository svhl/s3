// write a menu driven c program to implement searching algorithms for
// linear search
// binary search

#include <stdio.h>

int a[50], n, i, j, item, flag;

void linear()
{
	printf("\nEnter element to search:\n");
	scanf("%d", &item);
	flag = 0;
	printf("\n");
	
	for(i = 0; i < n; i++)
	{
		if(a[i] == item)
		{
			printf("Element found at position %d\n", (i+1));
			flag = 1;
		}
	}
	
	if(flag == 0)
	{
		printf("Element not found\n");
	}
}

void binary()
{
	printf("\nEnter element to search:\n");
	scanf("%d", &item);
	int temp;
	
	for(i = 0; i < n-1; i++)
	{
		for(j = 0; j < n-1-i; j++)
		{
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	
	printf("\nSorted array:\n");
	
	for(i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}
	
	printf("\n");	
	flag = 0;
	int l = 0, u = n-1, m;
	
	while(l <= u)
	{
		m = (l + u) / 2;
		
		if(item > a[m])
		{
			l = m + 1;
		}
		
		else if(item < a[m])
		{
			u = m - 1;
		}
		
		else
		{
			printf("\nElement found at position %d\n", (m+1));
			flag = 1;
			break;
		}
	}
	
	if(flag == 0)
	{
		printf("\nElement not found\n");
	}
}

void main()
{
	int ch;
	printf("Enter no. of elements:\n");
	scanf("%d", &n);
	
	for(i = 0; i < n; i++)
	{
		printf("Enter element at index %d:\n", i);
		scanf("%d", &a[i]);
	}
	
	while(1)
	{
		printf("\nMenu\n");
		printf("1. Linear search\n");
		printf("2. Binary search\n");
		printf("Any other value to exit\n");
		printf("Enter choice:\n");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1: linear();
				break;
				
			case 2: binary();
				break;
				
			default: return;
		}
	}
}
