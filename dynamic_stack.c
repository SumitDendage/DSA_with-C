// Implementation of dynamic stack
#include <stdio.h>
#include <stdlib.h>   // malloc(), free()

struct node
{
	int data;
	struct node *next;
};

// imp - declare top globally, so that it is available to all fns
struct node *top;

// fn declarations
void push(int);
int pop();
int isempty();
void display();

int main()
{
	top = NULL;    // stack is initialised
	int choice, no;
	while (1)
	{
		system("cls");
		printf("1. PUSH\n");
		printf("2.POP\n");
		printf("3. DISPLAY\n");
		printf("4. EXIT\n");
		printf("Enter your choice :- ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				printf("Enter the no to push :- ");
				scanf("%d",&no);
				push(no);
				break;
				
			case 2:
				if (isempty())
					printf("Cannot pop as stack is empty");
				else
					printf("Element popped is %d",pop());
					
				break;
				
			case 3:
				if (isempty())
					printf("Cannot display as stack is empty");
				else
					display();
					
				break;
				
			case 4:
				exit(0);
				
			default:
				printf("Error in choice, try again");
		}
		printf("\n");
		system("pause");
	}
	return 0;	
}

void push(int no)
{
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = no;
	if (top == NULL)
	{
		newnode->next = NULL;
		top = newnode;
	}
	else
	{
		newnode->next = top;
		top = newnode;    // top ascends
	}
}

int pop()
{
	struct node *temp;
	int no;
	no = top->data;
	temp = top;
	top = top->next;   // top descends
	free(temp);
	return no;	
}

void display()
{
	struct node *temp;
	for (temp=top;temp!=NULL;temp=temp->next)
		printf("%d\n",temp->data);
}

int isempty()
{
	if (top == NULL)
		return 1;
		
	return 0;
}

