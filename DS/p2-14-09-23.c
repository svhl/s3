// THIS PROGRAM ISN'T PART OF LAB CYCLE
// write a program using pointers to search an element in an array using linear search

#include <stdio.h>

void main()
{
	int array[20], n, search, *pointer, flag = 0, i;
	printf("Enter no. of elements:\n");
	scanf("%d", &n);

	for(i = 0; i < n; i++)
	{
		printf("Enter element %d:\n", i+1);
		scanf("%d", &array[i]);
	}

	printf("Enter the element to search:");
	scanf("%d", &search);
	pointer = array;

	for(i = 0; i < n; i++)
	{
		if ( *(pointer+i) == search)
		{
			printf("%d found at position %d\n", search, i);
			flag = 1;
		}
	}

	if(flag == 0)
		printf("%d not found\n", search);
}