// write a menu driven c program to implement polynomials using arrays & perform polynomial addition

#include <stdio.h>

void main()
{
	int a[50], b[50], c[50], cont = 1, ch, i, p, q, r, n, m;
	while(cont == 1)
	{
		printf("Menu:\n");
		printf("1. Input polynomials\n");
		printf("2. Add polynomials\n");
		printf("3. Display sum\n");
		printf("Enter choice:\n");
		scanf("%d", &ch);
		
		if(ch == 1)
		{
			printf("\nEnter no. of elements in polynomial 1:\n");
			scanf("%d", &m);
			a[0] = m;
			
			for(i = 1; i <= m*2; i++)
			{
				if(i%2 != 0)
					printf("Enter exponent of element:\n");
					
				else
					printf("Enter coefficient of element x^%d:\n", a[i-1]);
					
				scanf("%d", &a[i]);
			}
			
			printf("Enter no. of elements in polynomial 2:\n");
			scanf("%d", &n);
			b[0] = n;
			
			for(i = 1; i <= n*2; i++)
			{
				if(i%2 != 0)
					printf("Enter exponent of element:\n");
					
				else
					printf("Enter coefficient of element x^%d:\n", b[i-1]);
					
				scanf("%d", &b[i]);
			}
		}
		
		else if(ch == 2)
		{
			p = q = r =1;
			
			while (p <= 2*m && q <= 2*n)
			{
				if(a[p] == b[q])
				{
					c[r+1] = a[p+1] + b[q+1];
					
					if(c[r+1] != 0)
					{
						c[r] = a[p];
						r += 2;
					}
					
					p += 2;
					q += 2;
				}
				
				else if(a[p] < b[q])
				{
					c[r+1] = b[q+1];
					c[r] = b[q];
					r += 2;
					q += 2;
				}
				
				else
				{
					c[r+1] = a[p+1];
					c[r] = a[p];
					r += 2;
					p += 2;
				}
			}
			
			while(p <= 2*m)
			{
				c[r] = a[p];
				c[r+1] = a[p+1];
				r += 2;
				p += 2;
			}
			
			while(q <= 2*n)
			{
				c[r] = b[q];
				c[r+1] = b[q+1];
				r += 2;
				q += 2;
			}
			
			c[0] = r/2;
			printf("\nAdded\n");
		}
		
		else if(ch == 3)
		{
			printf("\nPolynomial 1:\n");

			for(i = 0; i <= m*2; i++)
				printf("%d\t", a[i]);

			printf("\n\nPolynomial 2:\n");

			for(i = 0; i <= n*2; i++)
				printf("%d\t", b[i]);

			printf("\n\nSum:\n");
			
			for(i = 0; i < r; i++)
				printf("%d\t", c[i]);
			
			printf("\n");
		}
		
		else
			break;
		
		printf("\n");
	}
}
