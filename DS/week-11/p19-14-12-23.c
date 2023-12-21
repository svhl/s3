// write a c program to do heap sort

#include <stdio.h>

void swap(int* a, int* b)
{

	int temp = *a;
	*a = *b;
	*b = temp;
}

void display(int arr[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	
	printf("\n");
}

void heapify(int arr[], int n, int i)
{
	int l = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if(left < n && arr[left] > arr[l])
	{
		l = left;
	}

	if(right < n && arr[right] > arr[l])
	{
		l = right;
	}

	if(l != i)
	{
		swap(&arr[i], &arr[l]);
		heapify(arr, n, l);
	}
}

void heapsort(int arr[], int n)
{

	for(int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(arr, n, i);
	}

	for(int i = n - 1; i >= 0; i--)
	{
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
		display(arr, n);
	}
}

int main()
{
	int n, arr[50];
	printf("Enter size of array:\n");
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++)
	{
		printf("Enter element %d:\n", i);
		scanf("%d", &arr[i]);
	}

	heapsort(arr, n);
}
