// write a menu driven c program to convert infix to postifix expression & evaluate using stack

#include <stdio.h>
#include <string.h>
#include <math.h>

char stack[50];
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

char pop()
{
	char item = stack[top];
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
			push(out[i]);
		}

		else
		{	
			z2 = (int)(pop()) - 48;
			z1 = (int)(pop()) - 48;
			
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
			
			push((char)(z + 48));
		}
	}

	printf("\nResult:\n%c\n", stack[0]);
}
