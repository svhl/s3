// develop a java program to read 2 matrices, display sum, & find transpose of resultant matrix

import java.util.Scanner;
class matrix
{
	public static void main(String[] args)
	{
		int r1, c1, r2, c2;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter no. of rows of matrix 1:");
		r1 = sc.nextInt();
		System.out.println("Enter no. of columns of matrix 1:");
		c1 = sc.nextInt();
		int a[][] = new int[r1][c1];

		for(int i = 0; i < r1; i++)
		{
			for(int j = 0; j < c1; j++)
			{
				System.out.println("Enter element at row " + i + " column " + j);
				a[i][j] = sc.nextInt();
			}
		}

		System.out.println("\nEnter no. of rows of matrix 2:");
		r2 = sc.nextInt();
		System.out.println("Enter no. of columns of matrix 2:");
		c2 = sc.nextInt();
		int b[][] = new int[r2][c2];

		for(int i = 0; i < r2; i++)
		{
			for(int j = 0; j < c2; j++)
			{
				System.out.println("Enter element at row " + i + " column " + j);
				b[i][j] = sc.nextInt();
			}
		}

		if(r1 != r2 || c1 != c2)
		{
			System.out.println("\nCan't add or transpose sum because rows & columns aren't same");
		}
		
		else
		{
			System.out.println("\nMatrix 1:\n");

			for(int i = 0; i < r1; i++)
			{
				for(int j = 0; j < c1; j++)
				{
					System.out.print(a[i][j] + "\t");
				}

				System.out.println();
			}

			System.out.println("\nMatrix 2:\n");

			for(int i = 0; i < r2; i++)
			{
				for(int j = 0; j < c2; j++)
				{
					System.out.print(b[i][j] + "\t");
				}

				System.out.println();
			}

			int s[][] = new int[r1][c1];
			int t[][] = new int[c1][r1];
			
			System.out.println("\nSum:\n");

			for(int i = 0; i < r1; i++)
			{
				for(int j = 0; j < c1; j++)
				{
					s[i][j] = a[i][j] + b[i][j];
					t[j][i] = s[i][j];
					System.out.print(s[i][j] + "\t");
				}

				System.out.println();
			}

			System.out.println("\nTranspose:\n");

			for(int i = 0; i < r1; i++)
			{
				for(int j = 0; j < c1; j++)
				{
					t[i][j] = s[j][i];
					System.out.print(t[i][j] + "\t");
				}

				System.out.println();
			}

		}
	}
}
