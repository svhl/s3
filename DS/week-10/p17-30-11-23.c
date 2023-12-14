// write a menu driven c program to implement merge sort

#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int l, int m, int r)
{
	int i, j, k, n1 = m - l + 1, n2 = r - m, L[n1], R[n2];
	
	for(i = 0; i < n1; i++)
	{
		L[i] = a[l+i];
	}
	
	for(j = 0; j < n2; j++)
	{
		R[j] = a[m+1+j];
	}
	
	i = 0;
	j = 0;
	k = l;
	
	while(i < n1 && j < n2)
	{
		if(L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		
		else
		{
			a[k] = R[j];
			j++;
		}
		
		k++;
	}
	
	while(i < n1)
	{
		a[k] = L[i];
		i++;
		k++;
	}
	
	while(j < n2)
	{
		a[k] = R[j];
		j++;
		k++;
	}
}

void sort(int a[], int l, int r)
{
	if(l < r)
	{
		int m = (l + r) / 2;
		sort(a, l, m);
		sort(a, m+1, r);
		merge(a, l, m, r);
		
		for(int n = 0; n < r + 1; n++)
		{
			printf("%d\t", a[n]);
		}
		
		printf("\n");
	}
}

void main()
{
	int a[50], n, i;
	printf("Enter no. of elements:\n");
	scanf("%d", &n);
	
	for(i = 0; i < n; i++)
	{
		printf("Enter element %d:\n", i);
		scanf("%d", &a[i]);
	}
	
	sort(a, 0, n-1);
}
