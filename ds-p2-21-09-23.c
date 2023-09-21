// write a menu driven c program to implement sparse matrix using arrays & perform the following operations
// a. sparse matrix addition
// b. sparse matrix transpose

#include <stdio.h>

void main()
{
	int ch, a[50][3], b[50][3], c[3][3], p, q, r, m, n, t, i, j, col;
	printf("Menu:\n");
	printf("1. Sparse matrix addition\n");
	printf("2. Sparse matrix transpose\n");
	printf("Enter choice:\n");
	scanf("%d", &ch);

	if(ch == 1)
	{
		printf("Enter no. of non-zero elements in matrix 1:\n");
		scanf("%d", &a[0][2]);
		printf("Enter no. of rows of matrix 1:\n");
		scanf("%d", &a[0][0]);
		printf("Enter no. of columns of matrix 1:\n");
		scanf("%d", &a[0][1]);
		printf("(Format for sparse matrix row: [row] [col] [val])\n");
	
		for(i = 1; i <= a[0][2]; i++)
		{
			printf("Enter row %d of sparse matrix 1:\n", i);
			scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
		}
		
		printf("\nMatrix 1:\n\n");

		for(i = 0; i <= a[0][2]; i++)
		{
			for(j = 0; j < 3; j++)
				printf("%d\t", a[i][j]);
			printf("\n");
		}

		printf("\nEnter no. of non-zero elements in matrix 2:\n");
		scanf("%d", &b[0][2]);
		printf("Enter no. of rows of matrix 2:\n");
		scanf("%d", &b[0][0]);
		printf("Enter no. of columns of matrix 2:\n");
		scanf("%d", &b[0][1]);
		printf("(Format for sparse matrix row: [row] [col] [val])\n");
	
		for(i = 1; i <= b[0][2]; i++)
		{
			printf("Enter row %d of sparse matrix 2:\n", i);
			scanf("%d%d%d", &b[i][0], &b[i][1], &b[i][2]);
		}

		if(a[0][0] != b[0][0] || a[0][1] != b[0][1])
		{
			printf("\n Can't add because unequal no. of rows & columns\n");
			return;
		}

		printf("\nMatrix 2:\n\n");

		for(i = 0; i <= b[0][2]; i++)
		{
			for(j = 0; j < 3; j++)
				printf("%d\t", b[i][j]);
			printf("\n");
		}

		p = q = r = 1;
		c[0][0] = a[0][0];
		c[0][1] = b[0][1];

		while(p <= a[0][2] && q <= b[0][2])
		{
			if(a[p][0] < b[q][0])
			{
				c[r][0] = a[p][0];
				c[r][1] = a[p][1];
				c[r][2] = a[p][2];
				p++;
				r++;
			}

			else if(a[p][0] > b[q][0])
			{
				c[r][0] = b[q][0];
				c[r][1] = b[q][1];
				c[r][2] = b[q][2];
				q++;
				r++;
			}

			else if(a[p][1] < b[q][1])
			{
				c[r][0] = a[p][0];
				c[r][1] = a[p][1];
				c[r][2] = a[p][2];
				p++;
				r++;
			}

			else if(a[p][1] > b[q][1])
			{
				c[r][0] = b[q][0];
				c[r][1] = b[q][1];
				c[r][2] = b[q][2];
				q++;
				r++;
			}

			else
			{
				c[r][0] = a[p][0];
				c[r][1] = a[p][1];
				c[r][2] = a[p][2] + b[q][2];
				p++;
				q++;
				r++;
			}
		}

		while(p <= a[0][2])
		{
			c[r][0] = a[p][0];
			c[r][1] = a[p][1];
			c[r][2] = a[p][2];
			p++;
			r++;
		}

		while(q <= b[0][2])
		{
			c[r][0] = b[q][0];
			c[r][1] = b[q][1];
			c[r][2] = b[q][2];
			q++;
			r++;
		}
		
		// r is no. of rows in sparse matrix sum
		c[0][2] = r - 1;

		printf("\nSum:\n\n");

		for(i = 0; i < r; i++)
		{
			for(j = 0; j < 3; j++)
				printf("%d\t", c[i][j]);
			printf("\n");
		}
	}

	else if(ch == 2)
	{
		printf("Enter no. of non-zero elements in matrix:\n");
		scanf("%d", &a[0][2]);
		printf("Enter no. of rows of matrix:\n");
		scanf("%d", &a[0][0]);
		printf("Enter no. of columns of matrix:\n");
		scanf("%d", &a[0][1]);
		printf("(Format for sparse matrix row: [row] [col] [val])\n");

		for(i = 1; i <= a[0][2]; i++)
		{
			printf("Enter row %d of sparse matrix:\n", i);
			scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
		}

		printf("\nOriginal sparse matrix:\n\n");

		for(i = 0; i <= a[0][2]; i++)
		{
			for(j = 0; j < 3; j++)
				printf("%d\t", a[i][j]);
			printf("\n");
		}

		m = a[0][0];
		n = a[0][1];
		t = a[0][2];
		b[0][0] = n;
		b[0][1] = m;
		b[0][2] = t;
		q = 1;

		if(t <= 0)
			return;

		for(col = 0; col <= n-1; col++)
		{
			for(p = 1; p <= t; p++)
			{
				if(a[p][1] == col)
				{
					b[q][0] = a[p][1];
					b[q][1] = a[p][0];
					b[q][2] = a[p][2];
					q++;
				}
			}
		}

		printf("\nTransposed sparse matrix:\n\n");

		for(i = 0; i <= b[0][2]; i++)
		{
			for(int j = 0; j < 3; j++)
				printf("%d\t", b[i][j]);
			printf("\n");
		}
	}

	else
		printf("\nWrong choice\n");
}
