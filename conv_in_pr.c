// Program to convert infix expression to prefix expression
#include <stdio.h>
#include <string.h>  // strlen(), strrev()
#define SIZE 20

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
	char infix[SIZE], prefix[SIZE], ch;
	int i, j = 0;
	struct stack s;
	s.top = -1;
	printf("Enter the infix expression :- ");
	gets(infix);
	// read the infix expression R to L
	for (i=strlen(infix)-1;i>=0;i--)  // Base for length of string is 1 but for position it is 0
	{
		switch(infix[i])
		{
			case ')':
				push(&s,')');  // push(&s,infix[i]);
				break;
				
			case '+':
			case '-':
			case '/':
			case '*':
			case '%':
			case '$':
			case '^':
				while (!isempty(&s) && priority(s.data[s.top]) > priority(infix[i]))
				{
					prefix[j] = pop(&s);
					j++;		
				}				
				push(&s,infix[i]);
				break;
				
			case '(':
				ch = pop(&s);
				while (ch != ')')
				{
					prefix[j] = ch;
					j++;
					ch = pop(&s);
				}
				break;
				
			default:  // operands
				prefix[j] = infix[i];
				j++;
		} // end of switch
	} // end of for
	while (!isempty(&s))
	{
		prefix[j] = pop(&s);
		j++;
	}
	prefix[j] = '\0';
	printf("Prefix Expression is %s",strrev(prefix));
	return 0;
} // end of main()


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
	if (ch == '$' || ch == '^')
		return 3;
	else if (ch == '/' || ch == '*')
		return 2;
	else if (ch == '+' || ch == '-')
		return 1;
	else   // )
		return 0;
}



