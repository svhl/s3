// write a java program to perform linear search on a given array of numbers

import java.util.*;

class LinearSearch
{
	public static void main(String[] args)
	{
		int n, i, j, search;
		boolean flag = false;
		int a[] = new int[50];
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter no. of elements:");
		n = sc.nextInt();

		for(i = 0; i < n; i++)
		{
			System.out.println("Enter element at position " + i + ":");
			a[i] = sc.nextInt();
		}

		System.out.println("Enter element to search:");
		search = sc.nextInt();
		
		for(i = 0; i < n; i++)
		{
			if(a[i] == search)
			{
				System.out.println("Element found at position " + i);
				flag = true;
			}
		}

		if(flag == false)
		{
			System.out.println("Element not found");
		}
	}
}
