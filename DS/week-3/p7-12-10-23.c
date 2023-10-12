#include <stdio.h>

char stack[50];
int top = -1;

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
	if(x == '(' || x == ')')
	{
		return 0;
	}
	
	else if(x == '+' || x == '-')
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
}

void main()
{
	char x[50];
	printf("Enter an infix expression:\n");
	gets(x);
	char out[50];
	int i, j = 0;
	for(i = 0; x[i] != '\0'; i++)
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
	
	while(stack[top] == '+' || stack[top] == '-' || stack[top] == '*' || stack[top] == '/' || stack[top] == '^')
	{
		out[j] = pop();
		j++;
	}
	
	printf("\nPostfixed expression:\n");

	for(i = 0; i < j; i++)
	{
		printf("%c", out[i]);
	}
	
	printf("\n");
}	
