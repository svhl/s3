// write a menu driven c program to convert infix to postifix expression & evaluate using stack

#include <stdio.h>
#include <string.h>
#include <math.h>

char stack[50];
int stackeval[50];
int top = -1, z1, z2, z;

void push(char x)
{
	if(top == 49)
	{
		printf("Stack full\n");
	}
	
	else
	{
		top++;
		stack[top] = x;
	}
}

void pusheval(int x)
{
		top++;
		stackeval[top] = x;
}

char pop()
{
	char item = stack[top];
	top--;
	return item;
}

int popeval()
{
	char item = stackeval[top];
	top--;
	return item;
}

int precedence(char x)
{
	if(x == '+' || x == '-')
	{
		return 1;
	}
	
	else if(x == '*' || x == '/')
	{
		return 2;
	}
	
	else if(x == '^')
	{
		return 3;
	}

	else
	{
		return 0;
	}
}

void main()
{
	char x[50];
	printf("Enter an infix expression:\n");
	gets(x);
	char out[50];
	int i, j = 0;
	for(i = 0; i < strlen(x); i++)
	{
		if(x[i] >= '0' && x[i] <= '9')
		{
			out[j] = x[i];
			j++;
		}
		
		else if(x[i] == '(')
		{
			push(x[i]);
		}
		
		else if(x[i] == ')')
		{
			while(stack[top] != '(')
			{
				out[j] = pop();
				j++;
			}
			
			pop();
		}
		
		else
		{
			if(x[i] == '^' && stack[top] == '^')
			{
				push(x[i]);
				continue;
			}

			while(precedence(x[i]) <= precedence(stack[top]))
			{
				out[j] = pop();
				j++;
			}
			
			push(x[i]);
		}
	}
	
	while(top >= 0)
	{
		out[j] = pop();
		j++;
	}
	
	printf("\nPostfixed expression:\n%s\n", out);

	top = -1;

	for(i = 0; i < strlen(out); i++)
	{
		if(out[i] >= '0' && out[i] <= '9')
		{
			pusheval((int)(out[i] - 48));
		}

		else
		{	
			z2 = popeval();
			z1 = popeval();
			
			if(out[i] == '+')
			{
				z = z1 + z2;
			}

			else if(out[i] == '-')
			{
				z = z1 - z2;
			}

			else if(out[i] == '*')
			{
				z = z1 * z2;
			}

			else if(out[i] == '/')
			{
				z = z1 / z2;
			}

			else
			{
				z = pow(z1, z2);
			}
			
			pusheval(z);
		}
	}

	printf("\nResult:\n%d\n", stackeval[top]);
}
