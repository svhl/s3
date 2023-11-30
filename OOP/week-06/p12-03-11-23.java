// write a java program to perform linear search on a given array of numbers

import java.util.Scanner;

class LinearSearch
{
	LinearSearch(int a[], int n, int search)
	{
		boolean flag = false;
		
		for(int i = 0; i < n; i++)
		{
			if(a[i] == search)
			{
				System.out.println("Element found at position " + (i+1));
				flag = true;
			}
		}

		if(flag == false)
		{
			System.out.println("Element not found");
		}
	}
}

class LinearSearchDemo
{
	public static void main(String[] args)
	{
		int n, i, search;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter no. of elements:");
		n = sc.nextInt();
		int a[] = new int[n];

		for(i = 0; i < n; i++)
		{
			System.out.println("Enter element at index " + i + ":");
			a[i] = sc.nextInt();
		}

		System.out.println("Enter element to search:");
		search = sc.nextInt();
		
		LinearSearch l1 = new LinearSearch(a, n, search);
	}
}
