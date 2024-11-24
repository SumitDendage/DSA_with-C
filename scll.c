// Operations on Singly Circular Linked List of integers
#include <stdio.h>
#include <stdlib.h>  // malloc(), free(), exit(0)

// imp - declare the structure globally, so that it is available to all functions
struct node
{
	int data;
	struct node *next;
};

// fn declaration
struct node *createll(struct node *);
void displayll(struct node *);
struct node *insertatbeg(struct node *); 
void insertatend(struct node *);
struct node *deleteatbeg(struct node *);
struct node *deleteatend(struct node *);

int main()
{
	struct node *head;  
	int choice;
	head = NULL;
	while (1)
	{
		system("cls");   // to clear the screen
		printf("Operations on SCLL\n\n");
		printf("1. To Create LL\n");
		printf("2. To Display LL\n");
		printf("3. To Add a Node at the begining of LL\n");
		printf("4. To Add a Node at the end of LL\n");
		printf("5. To Delete a Node at the begining of LL\n");
		printf("6. To Delete a Node at the end of LL\n");
		printf("7. Exit\n");
		printf("Enter your choice :- ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
					head = createll(head);  
					break;
					
			case 2:
					displayll(head);
					break;
					
			case 3:
					head = insertatbeg(head);
					break;
					
			case 4:
					insertatend(head);
					break;
					
			case 5:
					head = deleteatbeg(head);
					break;
					
			case 6:
					head = deleteatend(head);
					break;
					
			case 7:
				exit(0);
					
			default:
				printf("Error in choice. Try again....");			
		}
		printf("\n");
		system("pause");  // wait to display the result/ans		
	}
	return 0;
}

struct node *createll(struct node *head)
{
	struct node *newnode, *temp;
	char ask = 'y';
	while (ask == 'y' || ask == 'Y')
	{
	
		newnode = (struct node *) malloc(sizeof(struct node));
		printf("Enter the data for newnode :- ");
		scanf("%d",&newnode->data);
		if (head == NULL)
		{
			newnode->next = newnode;
			head = temp = newnode;
		}
		else   // subsequent node
		{
			newnode->next = head;
			temp->next = newnode;
			temp = newnode;
		}
		fflush(stdin);
		printf("Add more nodes (y/n) :- ");
		scanf("%c",&ask);		
	}	
	return head; 
}

void displayll(struct node *head)
{
	struct node *temp;
	// validation
	if (head == NULL)
	{
		printf("1st create LL");
		return;
	}
	temp = head;
	while (1) 
	{
		printf("%d ",temp->data);
		temp = temp->next;
		if (temp == head)
			break;
	}
}

struct node *insertatbeg(struct node *head)
{
	struct node *newnode, *temp;
	// validation
	if (head == NULL)
	{
		printf("1st create LL");
		return 0;
	}	
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter data for newnode :- ");
	scanf("%d",&newnode->data);
	// establish the links
	newnode->next = head;
	// bring temp to last node & change it's link to newnode
	temp = head;
	while (temp->next != head)
		temp = temp->next;
		
	temp->next = newnode;
	printf("Node added at the begining of LL successfully!");
	return newnode;	
}

void insertatend(struct node *head)
{
	struct node *newnode, *temp;
	// validation
	if (head == NULL)
	{
		printf("1st create LL");
		return;
	}	
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter data for last node :- ");
	scanf("%d",&newnode->data);
	newnode->next = head;
	// get temp to last node & change it's link
	temp = head;
	while (temp->next != head)
		temp = temp->next;
		
	temp->next = newnode;
	printf("Node added at the end of LL successfully!");
}

struct node *deleteatbeg(struct node *head)
{
	struct node *temp = head;
	// validation
	if (head == NULL)
	{
		printf("1st create LL");
		return 0;
	}	
	// Case - 1, Only 1 node in LL
	if (head->next == head)
	{
		free(head);
		printf("Node @ position 1 deleted successfully!");
		return NULL;
	}
	// Case - 2, Multiple nodes in LL
	// traverse to last node & set it's link to new head
	while (temp->next != head)
		temp = temp->next;
		
	temp->next = head->next;
	temp = head;
	head = head->next;
	free(temp);
	printf("Node at position 1 deleted successfully!");
	return head;	
}

struct node *deleteatend(struct node *head)
{
	struct node *temp = head;
	// validation
	if (head == NULL)
	{
		printf("1st create LL");
		return 0;
	}	
	// Case - 1, Only 1 node in LL
	if (head->next == head)
	{
		free(head);
		printf("Node @ end position deleted successfully!");
		return NULL;
	}
	// Case - 2, Multiple nodes in LL
	// traverse to 2nd last node, delete last node & set it's link to new head
	while (temp->next->next != head)
		temp = temp->next;
		
	free(temp->next);   // deleting last node
	temp->next = head;
	printf("Node @ end position deleted successfully!");
	return head;  // unchanged	
}
