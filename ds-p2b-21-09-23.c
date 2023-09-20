#include <stdio.h>

void main()
{
	int a[5][3] = {{5,5,2},{0,0,1},{1,3,2},{1,2,3},{4,1,3}};
	printf("Original sparse matrix:\n\n");

	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 3; j++)
			printf("%d\t", a[i][j]);
		printf("\n");
	}

	int b[5][3];
	int m, n, t;
	m = a[0][0];
	n = a[0][1];
	t = a[0][2];
	b[0][0] = n;
	b[0][1] = m;
	b[0][2] = t;
	int q = 1;

	if(t <= 0)
		return;

	for(int col = 0; col < n; col++)
	{
		for(int p = 1; p <= t+1; p++)
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

	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 3; j++)
			printf("%d\t", b[i][j]);
		printf("\n");
	}
}
