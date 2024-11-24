// WAP for evaluation of Prefix Expression
#include <stdio.h>
#include <math.h>  // for pow()
#include <string.h> // strlen()
#define SIZE 20

struct stack
{
	int data[SIZE];
	int top;
};

// fn declarations
void push(struct stack *,int);
int pop(struct stack *);
int isalph(char);  // to check for operands

int main()
{
	char prefix[SIZE];
	int i, op1, op2, val_opds[SIZE], j = 0;   // to move in val_opds string/array
	struct stack s;
	s.top = -1;
	printf("Enter the prefix expression :- ");
	gets(prefix);
	// read the expression from L to R & accept values for operands
	for (i=0;prefix[i] != '\0';i++)
	{
		if (isalph(prefix[i]))
		{
			printf("Enter the value for operand %c :- ",prefix[i]);
			scanf("%d",&val_opds[j]);
			j++;  // move to next position to accept next value of operand
		}	
	}
	j--;  // imp to position j on last operand
	// read the expression from R to L
	for (i=strlen(prefix)-1;i>=0;i--)
	{
		if (isalph(prefix[i]))  // if operand
		{
			push(&s,val_opds[j]);
			j--;  // move to previous operand
		}
		else
		{
			op1 = pop(&s);
			op2 = pop(&s);
			if (prefix[i] == '+')
				push(&s,op1+op2);
			else if (prefix[i] == '-')
				push(&s,op1-op2);
			else if (prefix[i] == '*')
				push(&s,op1*op2);
			else if (prefix[i] == '/')
				push(&s,op1/op2);
			else if (prefix[i] == '%')
				push(&s,op1%op2);
			else // ^ or $
				push(&s,(int)pow(op1,op2));
		}
	}
	printf("Result is %d",pop(&s));
	return 0;
}

void push(struct stack *ps,int no)
{
	ps->top++;
	ps->data[ps->top] = no;
}

int pop(struct stack *ps)
{
	return ps->data[ps->top--];
}

int isalph(char ch)
{
	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
		return 1;
		
	return 0;
}
