//write a program using pointers to search an element in an array using linear search

#include <stdio.h>

void main()
{
	int a[20], n, s, *p, f = 0;
	printf("Enter no. of elements:\n");
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
	{
		printf("Enter element %d:\n", i+1);
		scanf("%d", &a[i]);
	}

	printf("Enter the element to search:");
	scanf("%d", &s);
	p = a;

	for(int i = 0; i < n; i++)
	{
		if ( *(p+i) == s)
		{
			printf("%d found at position %d\n", s, i);
			f = 1;
		}
	}

	if(f == 0)
		printf("%d not found\n", s);
}
