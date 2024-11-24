// Operations on Singly Linked List of integers
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
struct node *insertatbeg(struct node *);  // This is not a void fn bcoz the fn will change
								// the address of 1st node of LL i.e. head node
void insertatend(struct node *);  // As the address of head node will remain unchanged, this
								// fn doesn't return any value to main(). Hence void
struct node *deleteatbeg(struct node *);// This is not a void fn bcoz it is changing the
											// address of 1st node of LL
struct node *deleteatend(struct node *);  // This is not a void fn since if only single node 
											// remains, it will change the address of head
											// node to NULL
struct node *deleteatpos(struct node *);  // This fn is not void bcoz if the user selects pos 1,
											// then this will change the address of head node
											// of LL
void bub_sort(struct node *);  // This fn is a void fn bcoz we are not going to swap the nodes
							// but the values from nodes. So head node will remain the same
void display_revll(struct node *);
 
int main()
{
	struct node *head;  // head is nothing but a pointer var which stores the address of 1st
						// node of LL. Using this address, we can traverse the entire LL.
						// Traverse means visiting every node of LL
	int choice;  // menu driven program
	head = NULL;  // LL is not existing
	// to display the menu continuously on the screen, use a loop
	while (1)
	{
		system("cls");   // to clear the screen
		printf("Operations on SLL\n\n");
		printf("1. To Create LL\n");
		printf("2. To Display LL\n");
		printf("3. To Insert a Node at the begining of LL\n");
		printf("4. To Insert a Node at the end of LL\n");
		printf("5. To Delete a Node at the begining of LL\n");
		printf("6. To Delete a Node at the end of LL\n");
		printf("7. To Delete a Node at given position in LL\n");
		printf("8. To Sort the data of LL\n");
		printf("9. To Display the data of LL in reverse order\n");
		printf("10. Exit\n");
		printf("Enter your choice :- ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
					head = createll(head);  // createll() will understand that the LL is not
											// existing. So it will create a new LL & return
											// the address of 1st node to head
					break;
					
			case 2:
					displayll(head);
					break;
					
			case 3:
					// function call
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
					head = deleteatpos(head);
					break;
					
			case 8:		
					bub_sort(head);
					break;
			
			case 9:	
					display_revll(head);
					break;
			
			case 10:
				exit(0);
					
			default:
				printf("Error in choice. Try again....");			
		}
		printf("\n");
		system("pause");  // wait to display the result/ans		
	}
	return 0;
}

// createll() is not a void function. As it is returning the address of 1st node of LL,
// it is struct node *
struct node *createll(struct node *head)
{
	// to create a LL, we require 2 additional nodes
	struct node *newnode, *temp;
	char ask = 'y';
	while (ask == 'y' || ask == 'Y')
	{
		// allocate memory for newnode
		newnode = (struct node *) malloc(sizeof(struct node));
		// malloc() requires 2 know 1. how much memory is to be allocated
		//						    2. What is the memory going to store. Achieved using typecast
		printf("Enter the data for newnode :- ");
		scanf("%d",&newnode->data);
		newnode->next = NULL;
		// check whether it is the 1st node of LL
		if (head == NULL)
		{
			head = temp = newnode;
		}
		else   // subsequent node
		{
			temp->next = newnode;
			temp = newnode;  // temp moves along newnode
		}
		fflush(stdin); // to clear the ENTER key stored in buffer
		printf("Add more nodes (y/n) :- ");
		scanf("%c",&ask);		
	}	
	return head;  // imp
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
	while (temp != NULL)  // if temp becomes NULL (0), it means it is not pointing to any node
							// or rather any memory location
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
}

// fn definition
struct node *insertatbeg(struct node *head)  // we are passing old head & want new head
{
	struct node *newnode;
	// validation
	if (head == NULL)
	{
		printf("1st create LL");
		return 0;
	}
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter data for 1st node of LL :- ");
	scanf("%d",&newnode->data);
	newnode->next = head;
	//head = newnode;
	printf("Node inserted successfully @ pos 1 in LL");
	//return head;   // head = newnode (optional) & directly say return newnode;
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
	newnode->next = NULL;
	// now we need to attach newnode to the current last node of LL
	// To go to last node from head node, we need to traverse the LL
	for (temp=head;temp->next != NULL;temp = temp->next);  // ; is compulsory bcoz there is
												// no separate code in loop
	temp->next = newnode;
	printf("Node inserted successfully at end of LL");	
}

struct node *deleteatbeg(struct node *head)
{
	struct node *temp;  // temp is a pointer to the node to delete i.e. the head node
	// validation
	if (head == NULL)
	{
		printf("1st create LL");
		return 0;
	}
	temp = head;
	head = head->next;
	free(temp);
	printf("Node at position 1 deleted successfully!");
	return head;  // new head
}

struct node *deleteatend(struct node *head)
{
	struct node *temp;  
	// validation
	if (head == NULL)
	{
		printf("1st create LL");
		return 0;
	}
	// case-1, only 1 node in LL
	if (head->next == NULL)
	{
		free(head);
		printf("Node at end position deleted successfully!");
		return NULL;   // imp No LL present now
	}
	// case-2, multiple nodes in LL
	// traverse temp to 2nd last node
	temp = head;
	while (temp->next->next != NULL)
		temp = temp->next;
		
	free(temp->next);  // delete last node
	temp->next = NULL;
	printf("Node at end position deleted successfully!");
	return head;  // unchanged head
}

struct node *deleteatpos(struct node *head)
{
	struct node *temp1, *temp2;  
	int pos, count;  // count to know the no of nodes in LL
	// validation
	if (head == NULL)
	{
		printf("1st create LL");
		return 0;
	}
	printf("Enter the position of node to delete :- ");
	scanf("%d",&pos);
	// case - 1, node to delete is at pos 1
	if (pos == 1)
	{
		temp1 = head;
		head = head->next;
		free(temp1);
		printf("Node at position 1 deleted successfully!");
		return head;  // new head
	}
	// case - 2, pos > 1. Here we need to validate the position
	count = 0;
	temp1 = head;
	while (temp1 != NULL)  // temp1 is pointing to some valid node
	{
		count++;
		temp1 = temp1->next;
	}
	// validation - 2
	if (pos > count || pos < 1)
	{
		printf("Invalid position");
		return head;
	}
	// pos > 1 for sure
	count = 2;  // count is used to know the current position
	temp1 = head;
	temp2 = head->next;
	while (temp2 != NULL)
	{
		if (pos == count)
			break;
			
		temp1 = temp2;
		temp2 = temp2->next;
		count++;
	}
	temp1->next = temp2->next;
	free(temp2);
	printf("Node at position %d deleted successfully",pos);
	return head;  // unchanged
}

void bub_sort(struct node *head)
{
	struct node *temp1, *temp2;   // temp1 & temp2 are used to store the addresses of 2 
									// adjacent nodes
	int i, j, temp, count = 0;  // temp to swap values, count to store the no of nodes in LL
	// validation
	if (head == NULL)
	{
		printf("1st create LL");
		return;
	}
	temp1 = head;
	while (temp1 != NULL)
	{
		count++;
		temp1 = temp1->next;
	}
	// outer loop - In every iteration of outer loop, only 1 element gets set
	for (i=1;i<count;i++)
	{
		// before we start the comparision, position temp1 on head node
		temp1 = head;
		temp2 = head->next;
		// inner loop - for comparison
		for (j=0;j<count-i;j++)
		{
			if (temp1->data > temp2->data)  // ASC order
			{
				temp = temp1->data;
				temp1->data = temp2->data;
				temp2->data = temp;
			}
			// now proceed to next 2 nodes
			temp1 = temp2;
			temp2 = temp2->next;
		}  // end of inner loop
	} // end of outer loop
	printf("Data sorted successfully!");
}

void display_revll(struct node *temp)
{
	if (temp != NULL)
	{
		display_revll(temp->next);   // recursive call
		printf("%d ",temp->data);  // printf() kept on hold till recursion doesn't terminate
	}
}

