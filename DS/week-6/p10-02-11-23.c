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
	int cont = 1, ch, i, n, m;
	
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
			
			for(i = 0; i < m; i++)
			{
				p = (struct node*)malloc(sizeof(struct node));
				printf("\nEnter exponent of element:\n");
				scanf("%d", &p->exp);
				printf("Enter coefficient of element x^%d:\n", p->exp);
				scanf("%d", &p->coeff);

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
		}
		
		else if(ch == 2)
		{
			ptrp = hp;
			ptrq = hq;
			
			while (ptrp != NULL && ptrq != NULL)
			{
				r = (struct node*)malloc(sizeof(struct node));
				
				if(ptrp->exp > ptrq->exp)
				{
					r->exp = ptrp->exp;
					r->coeff = ptrp->coeff;
					
					if(ptrp->next == NULL)
					{
						tr->next = r;
						tr = r;
						break;
					}
					
					ptrp = ptrp->next;
				}
				
				else if(ptrp->exp < ptrq->exp)
				{
					r->exp = ptrq->exp;
					r->coeff = ptrq->coeff;
					
					if(ptrq->next == NULL)
					{
						tr->next = r;
						tr = r;
						break;
					}
					
					ptrq = ptrq->next;
				}
				
				else if((ptrp->coeff + ptrq->coeff) != 0)
				{
						r->exp = ptrp->exp;
						r->coeff = ptrp->coeff + ptrq->coeff;
						
						if(ptrp->next == NULL && ptrq->next == NULL)
						{
							tr->next = r;
							tr = r;
							break;
						}
						
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
				
				if(ptrp->next == NULL)
					break;
				
				ptrp = ptrp->next;
			}
			
			while(ptrq != NULL)
			{
				r = (struct node*)malloc(sizeof(struct node));
				r->exp = ptrq->exp;
				r->coeff = ptrq->coeff;
				
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
				
				if(ptrq->next == NULL)
					break;
					
				ptrq = ptrq->next;
			}
			
			printf("\nAdded\n");
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
			printf("\nSum:\n");

			while(ptrr != NULL)
			{
				printf("%d\t%d\t", ptrr->exp, ptrr->coeff);
				ptrr = ptrr->next;
			}

		}
		
		else
			break;
		
		printf("\n");
	}
}