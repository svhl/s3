// write a menu driven program to represent polynomials using a linked list & perform
// polynomial addition
// polynomial multiplication

#include <stdlib.h>
#include <stdio.h>

struct node
{
	int exp, coeff;
	struct node *next;
};

struct node *p, *q, *r, *hp, *hq, *hr, *tp, *tq, *tr;
int item;

void main()
{
	hp = hq = hr = NULL;
	int cont = 1, ch, i, j, n;

	printf("Enter no. of elements in polynomial 1:\n");
	scanf("%d", &n);

	for(i = 0; i < n; i++)
	{
		p = (struct node*)malloc(sizeof(struct node));
		printf("\nEnter exponent of element:\n");
		scanf("%d", &p->exp);
		printf("Enter coefficient of element x^%d:\n", p->exp);
		scanf("%d", &p->coeff);
		p->next = NULL;

		if(hp == NULL)
		{
			hp = p;
			tp = p;
		}

		else
		{
			tp->next = p;
			tp = p;
		}
	}

	printf("\nEnter no. of elements in polynomial 2:\n");
	scanf("%d", &n);

	for(i = 0; i < n; i++)
	{
		q = (struct node*)malloc(sizeof(struct node));
		printf("\nEnter exponent of element:\n");
		scanf("%d", &q->exp);
		printf("Enter coefficient of element x^%d:\n", q->exp);
		scanf("%d", &q->coeff);
		q->next = NULL;

		if(hq == NULL)
		{
			hq = q;
			tq = q;
		}

		else
		{
			tq->next = q;
			tq = q;
		}
	}
	
	while(cont == 1)
	{
		printf("\nMenu:\n");
		printf("1. Add polynomials\n");
		printf("2. Multiply polynomials\n");
		printf("3. Display result\n");
		printf("Any other value to exit\n");
		printf("Enter choice:\n");
		scanf("%d", &ch);
		
		if(ch == 1)
		{
			hr = NULL;
			p = hp;
			q = hq;

			// DON'T use pointer->next != NULL
			// use pointer != NULL
			while (p != NULL && q != NULL)
			{
				r = (struct node*)malloc(sizeof(struct node));
				
				if(p->exp > q->exp)
				{
					r->exp = p->exp;
					r->coeff = p->coeff;
					r->next = NULL;
					p = p->next;
				}
				
				else if(p->exp < q->exp)
				{
					r->exp = q->exp;
					r->coeff = q->coeff;
					r->next = NULL;
					q = q->next;
				}
				
				else if((p->coeff + q->coeff) != 0)
				{
					r->exp = p->exp;
					r->coeff = p->coeff + q->coeff;
					r->next = NULL;						
					p = p->next;
					q = q->next;
				}

				if(hr == NULL)
				{
					hr = r;
					tr = r;
				}
				
				else
				{
					tr->next = r;
					tr = r;
				}
			}
			
			while(p != NULL)
			{
				r = (struct node*)malloc(sizeof(struct node));
				r->exp = p->exp;
				r->coeff = p->coeff;
				r->next = NULL;
				tr->next = r;
				tr = r;

				if(p->next == NULL)
					break;
				
				p = p->next;
			}
			
			while(q != NULL)
			{
				r = (struct node*)malloc(sizeof(struct node));
				r->exp = q->exp;
				r->coeff = q->coeff;
				r->next = NULL;
				tr->next = r;
				tr = r;
				
				if(q->next == NULL)
					break;
					
				q = q->next;
			}
			
			printf("\nAdded\n");
		}

		else if(ch == 2)
		{
			hr = NULL;
			p = hp;

			while(p != NULL)
			{
				q = hq;

				while(q != NULL)
				{
					 r = (struct node*)malloc(sizeof(struct node));
					 r->exp = p->exp + q->exp;
					 r->coeff = p->coeff * q->coeff;
					 q = q->next;

					 if(hr == NULL)
					{
						hr = r;
						tr = r;
					}

					else
					{
						tr->next = r;
						tr = r;
					}
				}

				p = p->next;
			}
		}
		
		else if(ch == 3)
		{
			p = hp;
			printf("\nPolynomial 1:\n");

			while(p != NULL)
			{
				printf("%d\t%d\t", p->exp, p->coeff);
				p = p->next;
			}
			
			q = hq;
			printf("\nPolynomial 2:\n");

			while(q != NULL)
			{
				printf("%d\t%d\t", q->exp, q->coeff);
				q = q->next;
			}
			
			r = hr;
			printf("\nResult:\n");

			while(r != NULL)
			{
				printf("%d\t%d\t", r->exp, r->coeff);
				r = r->next;
			}

			printf("\n");
		}
		
		else
		{
			break;
		}
	}
}
