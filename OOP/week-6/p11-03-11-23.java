// write a java program that implements bubble sort algorithm

import java.util.*;

class BubbleSort
{
	public static void main(String[] args)
	{
		int n, i, j, tmp;
		int a[] = new int[50];
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter no. of elements:");
		n = sc.nextInt();
		
		for(i = 0; i < n; i++)
		{
			System.out.println("Enter element at position " + i + ":");
			a[i] = sc.nextInt();
		}

		System.out.println("Original array:");

		for(i = 0; i < n; i++)
		{
			System.out.print(a[i] + "\t");
		}

		System.out.println("\nSorted array:");
		
		for(i = 0; i < n - 1; i++)
		{
			for(j = 0; j < n - 1 - i; j++)
			{
				if(a[j] > a[j+1])
				{
					tmp = a[j];
					a[j] = a[j+1];
					a[j+1] = tmp;
				}
			}
		}

		for(i = 0; i < n; i++)
		{
			System.out.print(a[i] + "\t");
		}

		System.out.println();
	}
}
