// write a java program that implements bubble sort algorithm

import java.util.Scanner;

class BubbleSort
{
	BubbleSort(int a[], int n)
	{
		for(int i = 0; i < n - 1; i++)
		{
			for(int j = 0; j < n - 1 - i; j++)
			{
				if(a[j] > a[j+1])
				{
					int tmp = a[j];
					a[j] = a[j+1];
					a[j+1] = tmp;
					
					for(int k = 0; k < n; k++)
					{
						System.out.print(a[k] + "\t");
					}
					
					System.out.println();
				}
			}
		}
	}
}

class BubbleSortDemo
{
	public static void main(String[] args)
	{
		int n, i, j;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter no. of elements:");
		n = sc.nextInt();
		int a[] = new int[n];
		
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
		
		BubbleSort b1 = new BubbleSort(a, n);
	}
}
