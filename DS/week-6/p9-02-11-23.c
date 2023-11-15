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

struct node *p, *q, *r, *hp, *hq, *hr, *tp, *tq, *tr, *ptrp, *ptrq, *ptrr;
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
			// use another pointer & assign to head
			ptrp = hp;
			ptrq = hq;

			// DON'T use pointer->next != NULL
			// use pointer != NULL
			while (ptrp != NULL && ptrq != NULL)
			{
				r = (struct node*)malloc(sizeof(struct node));
				
				if(ptrp->exp > ptrq->exp)
				{
					r->exp = ptrp->exp;
					r->coeff = ptrp->coeff;
					r->next = NULL;
					ptrp = ptrp->next;
				}
				
				else if(ptrp->exp < ptrq->exp)
				{
					r->exp = ptrq->exp;
					r->coeff = ptrq->coeff;
					r->next = NULL;
					ptrq = ptrq->next;
				}
				
				else if((ptrp->coeff + ptrq->coeff) != 0)
				{
					r->exp = ptrp->exp;
					r->coeff = ptrp->coeff + ptrq->coeff;
					r->next = NULL;						
					ptrp = ptrp->next;
					ptrq = ptrq->next;
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
			
			while(ptrp != NULL)
			{
				r = (struct node*)malloc(sizeof(struct node));
				r->exp = ptrp->exp;
				r->coeff = ptrp->coeff;
				r->next = NULL;
				tr->next = r;
				tr = r;

				if(ptrp->next == NULL)
					break;
				
				ptrp = ptrp->next;
			}
			
			while(ptrq != NULL)
			{
				r = (struct node*)malloc(sizeof(struct node));
				r->exp = ptrq->exp;
				r->coeff = ptrq->coeff;
				r->next = NULL;
				tr->next = r;
				tr = r;
				
				if(ptrq->next == NULL)
					break;
					
				ptrq = ptrq->next;
			}
			
			printf("\nAdded\n");
		}

		else if(ch == 2)
		{
			hr = NULL;
			ptrp = hp;

			while(ptrp != NULL)
			{
				ptrq = hq;

				while(ptrq != NULL)
				{
					 r = (struct node*)malloc(sizeof(struct node));
					 r->exp = ptrp->exp + ptrq->exp;
					 r->coeff = ptrp->coeff * ptrq->coeff;
					 ptrq = ptrq->next;

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

				ptrp = ptrp->next;
			}
		}
		
		else if(ch == 3)
		{
			ptrp = hp;
			printf("\nPolynomial 1:\n");

			while(ptrp != NULL)
			{
				printf("%d\t%d\t", ptrp->exp, ptrp->coeff);
				ptrp = ptrp->next;
			}
			
			ptrq = hq;
			printf("\nPolynomial 2:\n");

			while(ptrq != NULL)
			{
				printf("%d\t%d\t", ptrq->exp, ptrq->coeff);
				ptrq = ptrq->next;
			}
			
			ptrr = hr;
			printf("\nResult:\n");

			while(ptrr != NULL)
			{
				printf("%d\t%d\t", ptrr->exp, ptrr->coeff);
				ptrr = ptrr->next;
			}

			printf("\n");
		}
		
		else
		{
			break;
		}
	}
}
