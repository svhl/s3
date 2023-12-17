// write a c program to do quick sort

#include<stdio.h>

int a[50], n;

void quicksort(int *a, int left, int right, int n)
{
	int i, j, pivot, temp;

	if(left < right)
	{
		pivot = left;
		i = left;
		j = right;

		while(i < j)
		{
			while(a[i] <= a[pivot] && i <= right)
			{
				i++;
			}

			while(a[j] > a[pivot] && j >= left)
			{
				j--;
			}

			if(i < j)
			{
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}

		temp = a[j];
		a[j] = a[pivot];
		a[pivot] = temp;

		for(int k = 0; k < n; k++)
		{
			printf("%d\t", a[k]);
		}

		printf("\n");		
		quicksort(a, left, j-1, n);
		quicksort(a, j+1, right, n);	
	}
}

void main()
{
	int k;
	printf("Enter size of array:\n");
	scanf("%d", &n);

	for(k = 0; k < n; k++)
	{
		printf("Enter element %d:\n", k);
		scanf("%d", &a[k]);
	}

	quicksort(a, 0, n-1, n);
}
