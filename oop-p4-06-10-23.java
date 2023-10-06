// develop a java program to count the no. of odd & even no.s in a 1D array

import java.util.Scanner;
class oddeven
{
	public static void main(String[] args)
	{
		int n, odd = 0, even = 0, zero = 0;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter no. of elements in array:");
		n = sc.nextInt();
		int a[] = new int[n];

		for(int i = 0; i < n; i++)
		{
			System.out.println("Enter element " + (i+1));
			a[i] = sc.nextInt();

			if(a[i] == 0)
				zero++;

			else if(a[i] % 2 == 0)
				even++;

			else
				odd++;
		}

		System.out.println("\nNo. of zeroes: " + zero);
		System.out.println("No. of odd no.s: " + odd);
		System.out.println("No. of even no.s: " + even);
	}
}
