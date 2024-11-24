// Accept a string from user & determine whether it is a palindrome or not.
// Use a stack for creating a reverse string
#include <stdio.h>
#include <string.h>  // for strcmp()
#define SIZE 20    // should be sufficient to accomodate any word

struct stack
{
	char data[SIZE];
	int top;
};

// fn declarations
void push(struct stack *,char);
char pop(struct stack *);
int isempty(struct stack *);  // no need to define isfull() or display()

int main()
{
	char word[SIZE], revword[SIZE];
	int i;
	struct stack s;
	s.top = -1;  // imp - initialse the stack
	printf("Enter a word :- ");
	gets(word);
	// push 1 by 1 character from given word in stack s
	for (i=0;word[i] != '\0';i++)    // condition can be  i < strlen(word)
		push(&s,word[i]);
		
	// pop every character from stack s & add it to revword[ ]
	i = 0;
	while (!isempty(&s))
	{
		revword[i] = pop(&s);
		i++;
	}
	revword[i] = '\0';  // imp - close the target string
	if (strcmp(word,revword) == 0)
		printf("Given word is a palindrome");
	else
		printf("Given word is not a palindrome");
		
	return 0;	
}

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

