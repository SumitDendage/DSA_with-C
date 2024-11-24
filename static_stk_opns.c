// Implementation of Static Stack of int values
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

// always declare structures globally, so that they are available to all the functions
struct stack
{
	int data[SIZE];
	int top;
};

// fn declarations
void push(struct stack *,int);
int pop(struct stack *);
int isfull(struct stack *);
int isempty(struct stack *);
void display(struct stack *);

int main()
{
	struct stack s;
	int choice, no;
	s.top = -1;   // stack is initialised
	while (1)
	{
		system("cls");
		printf("Operations on Static Stack\n");
		printf("1. PUSH\n");
		printf("2. POP\n");
		printf("3. DISPLAY\n");
		printf("4. EXIT\n");
		printf("Enter your choice:- ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				if (isfull(&s))
					printf("Stack is full");
				else
				{
					printf("Enter the no :- ");
					scanf("%d",&no);
					push(&s,no);
					printf("No %d inserted in stack successfully!",no);
				}
				break;
				
			case 2:
				if (isempty(&s))
					printf("Stack is empty");
				else
					printf("Element popped is %d",pop(&s));
					
				break;
				
			case 3:
				if (isempty(&s))
					printf("Stack is empty");
				else
					display(&s);
					
				break;
				
			case 4:
				exit(0);
				
			default:
				printf("Error in choice, try again....");
		}	
		printf("\n");
		system("pause");
	}
}

void push(struct stack *ps,int no)
{
	ps->top++;
	ps->data[ps->top] = no;
}

int isfull(struct stack *ps)
{
	if (ps->top == SIZE-1)
		return 1;
		
	return 0;
}

int pop(struct stack *ps)
{
	return ps->data[ps->top--];  // return the element @ top position & then decrement top
}

int isempty(struct stack *ps)
{
	if (ps->top == -1)
		return 1;
		
	return 0;
}

void display(struct stack *ps)
{
	int temp;
	for (temp=ps->top;temp!=-1;temp--)  // temp >= 0
		printf("%d\n",ps->data[temp]);
}

