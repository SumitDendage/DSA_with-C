// Merging of 2 sorted LLs into a single LL
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

// fn declarations
struct node *createll(struct node *), *mergell(struct node *,struct node *);
void displayll(struct node *);

int main()
{
	struct node *head1 = NULL, *head2 = NULL, *head3 = NULL;
	printf("Create LL1\n");
	head1 = createll(head1);
	printf("Create LL2\n");
	head2 = createll(head2);
	head3 = mergell(head1,head2);
	system("cls");
	printf("LL1 is\n");
	displayll(head1);
	printf("\nLL2 is\n");
	displayll(head2);
	printf("\nMerged LL is\n");
	displayll(head3);
	return 0;	
}

struct node *createll(struct node *head)
{
	struct node *newnode, *temp;
	int i, no_nodes;
	printf("Enter the no of nodes :- ");
	scanf("%d",&no_nodes);
	printf("Enter the nodes with data in ASC order\n");
	for (i=0;i<no_nodes;i++)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("Enter data for newnode :- ");
		scanf("%d",&newnode->data);
		newnode->next = NULL;
		if (head == NULL)
			head = temp = newnode;
		else
		{
			temp->next = newnode;
			temp = newnode;
		}
	}
	return head;	
}

void displayll(struct node *temp)
{
	while (temp != NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	 } 
}

struct node *mergell(struct node *head1,struct node *head2)
{
	struct node *head = NULL, *newnode, *temp;  // code to create LL3 is similar to createll() 
								// except that the data for newnode is taken from either
							//  LL1 or LL2. Also head denotes the head of LL3 which is to be
							// created yet
	// now compare the data of nodes from LL1 & LL2 till nodes exist in both the lists
	while (head1 != NULL && head2 != NULL)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->next = NULL;
		if (head1->data < head2->data)
		{
			newnode->data = head1->data;
			head1 = head1->next;  // so that in next iteration, next node data is used for
									// comparison
		}
		else
		{
			newnode->data = head2->data;
			head2 = head2->next;
		}
		// attach newnode to LL3
		if (head == NULL)
			head = temp = newnode;
		else
		{
			temp->next = newnode;
			temp = newnode;  // temp is on current last node
		}
	}
	// Case-1, if nodes of LL1 are exhausted, copy 1 by 1 node of LL2 in LL3
	while (head2 != NULL)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->next = NULL;
		newnode->data = head2->data;
		// attach newnode to LL3
		head2 = head2->next;
		temp->next = newnode;
		temp = newnode;
	}
	// Case-2, if nodes of LL2 are exhausted, copy 1 by 1 node of LL1 in LL3
	while (head1 != NULL)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->next = NULL;
		newnode->data = head1->data;
		head1 = head1->next;
		// attach newnode to LL3
		temp->next = newnode;
		temp = newnode;
	}
	return head;
}

