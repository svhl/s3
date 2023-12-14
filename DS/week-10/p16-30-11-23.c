// write a menu driven C program to implement the following sorting techniques:
// bubble sort
// insertion sort
// selection sort

#include<stdio.h>

void main()
{
	int a[50], n, ch, i, j, k, l;
	printf("Enter no. of elements:\n");
	scanf("%d", &n);
	
	for(i = 0; i < n; i++)
	{
		printf("Enter element %d:\n", (i+1));
		scanf("%d", &a[i]);
	}
	
	printf("\nMenu\n");
	printf("1. Bubble sort\n");
	printf("2. Insertion sort\n");
	printf("3. Selection sort\n");
	printf("Any other value to exit\n");
	printf("Enter choice:\n");
	scanf("%d", &ch);
	
	if(ch == 1)
	{
		for(i = 0; i < n-1; i++)
		{
			for(j = 0; j < n-1-i; j++)
			{
				if(a[j] > a[j+1])
				{
					k = a[j];
					a[j] = a[j+1];
					a[j+1] = k;
				}
			}
			
			for(j = 0; j < n; j++)
			{
				printf("%d\t", a[j]);
			}
			
			printf("\n");
		}
	}
	
	else if(ch == 2)
	{
		for(i = 1; i < n; i++)
		{
			k = a[i];
			j = i - 1;
			
			while(j >= 0 && k <= a[j])
			{
				a[j+1] = a[j];
				j--;
			}
			
			a[j+1] = k;
			
			for(j = 0; j < n; j++)
			{
				printf("%d\t", a[j]);
			}
			
			printf("\n");
		}
	}
	
	else if(ch == 3)
	{
		for(i = 0; i < n-1; i++)
		{
			l = i;
			
			for(j = i+1; j < n; j++)
			{
				if(a[j] < a[l])
				{
					l = j;
				}
			}
			
			k = a[l];
			a[l] = a[i];
			a[i] = k;
			
			for(j = 0; j < n; j++)
			{
				printf("%d\t", a[j]);
			}
			
			printf("\n");
		}
	}
	
	else
	{
		printf("\nWrong choice\n");
		return;
	}

	printf("\nSorted array:\n");
	
	for(i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}
	
	printf("\n");
}
