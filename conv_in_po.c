// Program for conversion of Infix Expression to Postfix Expression
#include <stdio.h>
#define SIZE 30

struct stack
{
	char data[SIZE];
	int top;
};

// fn declarations
void push(struct stack *,char);
char pop(struct stack *);
int isempty(struct stack *);
int priority(char);

int main()
{
	struct stack s;
	char infix[SIZE], postfix[SIZE], ch;
	int i, j = 0;  // var i to move in infix string whereas j to move in postfix string
	s.top = -1;  // stack is initialised
	printf("Enter the infix expression :- ");
	gets(infix);
	// analyse 1 by 1 character from infix string
	for (i=0;infix[i] != '\0';i++)
	{
		switch (infix[i])
		{
			case '(':
				push(&s,infix[i]);  // push(&s,'(');
				break;
				
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case '$':  // $ or ^ for power value
			case '^':
				while (!isempty(&s) && priority(s.data[s.top]) >= priority(infix[i]))
				{
					postfix[j] = pop(&s);
					j++;
				}
				push(&s,infix[i]);
				break;
				
			case ')':
				ch = pop(&s);
				while (ch != '(')
				{
					postfix[j] = ch;
					j++;
					ch = pop(&s);
				}
				break;
				
			default:   // operand
				postfix[j] = infix[i];
				j++;
		}
	}  // end of for loop
	while (!isempty(&s))
	{
		postfix[j] = pop(&s);
		j++;
	}
	postfix[j] = '\0';  // imp close the target string with null character
	printf("Postfix string is %s",postfix);
	return 0;
}

// fn definitions
void push(struct stack *ps,char ch)
{
	ps->top++;
	ps->data[ps->top] = ch;
}

char pop(struct stack *ps)
{
	return ps->data[ps->top--];
}

int isempty(struct stack *ps)
{
	if (ps->top == -1)
		return 1;
		
	return 0;
}

int priority(char ch)
{
	if (ch == '^' || ch == '$')
		return 3;
	else if (ch == '*' || ch == '/' || ch == '%')
		return 2;
	else if (ch == '+' || ch == '-')
		return 1;
	else   // (
		return 0;	
}
