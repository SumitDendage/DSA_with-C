// Evaluation of Postfix Expression
#include <stdio.h>
#include <math.h>  // to calculate power value
#define SIZE 20

struct stack
{
	int data[SIZE];  // int bcoz we would like to store values of operands & not operands
	int top;
};

// fn declarations
void push(struct stack *,int);
int pop(struct stack *);
int isalph(char);

int main()
{
	struct stack s;
	char postfix[SIZE];
	int i, val_opd, op1, op2;
	s.top = -1;
	printf("Enter the postfix expression :- ");
	gets(postfix);
	// analyse each character from postfix expression
	for (i=0;postfix[i] != '\0';i++)
	{
		if (isalph(postfix[i]))   // 1-true for operand
		{
			printf("Enter the value for operand %c :- ",postfix[i]);
			scanf("%d",&val_opd);
			push(&s,val_opd);
		}
		else // operator
		{
			op2 = pop(&s);
			op1 = pop(&s);
			if (postfix[i] == '+')
				push(&s,op1+op2);
			else if (postfix[i] == '-')
				push(&s,op1-op2);
			else if (postfix[i] == '*')
				push(&s,op1*op2);
			else if (postfix[i] == '/')
				push(&s,op1/op2);
			else if (postfix[i] == '%')
				push(&s,op1%op2);
			else  // ^ $ for power value
				push(&s,(int)pow(op1,op2));  //pow() returns the result in type double. So
												// typecast to int & then push
		}		
	}
	printf("Result is %d",pop(&s));
	return 0;	
}

int isalph(char ch)
{
	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
		return 1;
		
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
