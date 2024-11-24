// To Add 2 polynomials in single variable
// p1 = 5x^3 + 6x^2 - 10
// p2 = 10x^4 + 3x^3 - 6x^2 + 4x^1
// p3 = 10x^4 + 8x^3 + 4x^1 - 10
// Note that the polynomials are always written in DESC order by power & terms with same power
// are added
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int coeff, pow;
	struct node *next;
};

// fn declarations
struct node *createpoly(struct node *);
void displaypoly(struct node *);
struct node *addpoly(struct node *,struct node *);

int main()
{
	struct node *head1 = NULL, *head2 = NULL, *head3 = NULL;
	printf("Create poly 1\n");
	head1 = createpoly(head1);
	printf("Create poly 2\n");
	head2 = createpoly(head2);
	head3 = addpoly(head1,head2);
	system("cls");
	printf("Poly1 is\n");
	displaypoly(head1);
	printf("\nPoly2 is\n");
	displaypoly(head2);
	printf("\nPoly3 is\n");
	displaypoly(head3);
	return 0;	
}

struct node *createpoly(struct node *head)
{
	struct node *newnode, *temp;
	int i, no_nodes;
	printf("Enter the no of terms for polynomial :- ");
	scanf("%d",&no_nodes);
	printf("Enter the terms in DESC order by power\n");
	for (i=0;i<no_nodes;i++)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("Enter the coefficient & power :- ");
		scanf("%d %d",&newnode->coeff,&newnode->pow);
		newnode->next = NULL;
		// check whether it is 1st node or sunsequent node
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

void displaypoly(struct node *temp)
{
	// Note that if the term is +ve, we need to print "+" before the term & also if power is 0,
	// then we need not print letter 'x'
	while (temp != NULL)   // traversal code of SLL
	{
		if (temp->coeff > 0 && temp->pow > 0)
			printf("+ %dx^%d ",temp->coeff,temp->pow);
		else if (temp->coeff > 0 && temp->pow == 0)
			printf("+ %d ",temp->coeff);
		else if (temp->coeff < 0 && temp->pow > 0)
			printf(" %dx^%d",temp->coeff,temp->pow);
		else
			printf(" %d",temp->coeff);
			
		temp = temp->next;			
	}
}

struct node *addpoly(struct node *head1,struct node *head2)
{
	struct node *head3 = NULL, *newnode, *temp;
	int ncoeff, npow;
	// compare the terms of poly1 & poly2 till terms exist in both the polynomials
	while (head1 != NULL && head2 != NULL)
	{
		if (head1->pow == head2->pow)
		{
			if (head1->coeff + head2->coeff == 0)  // this term needs to be ignored
			{
				head1 = head1->next;
				head2 = head2->next;
				continue;  // go to start of loop & compare the next set of terms
			}
			else
			{
				ncoeff = head1->coeff + head2->coeff;
				npow = head1->pow;
				head1=head1->next;
				head2=head2->next;
			}			
		}
		else if (head1->pow > head2->pow)
		{
			ncoeff = head1->coeff;
			npow = head1->pow;
			head1 = head1->next;
		}
		else  // head2->pow > head1->pow
		{
			ncoeff = head2->coeff;
			npow = head2->pow;
			head2 = head2->next;
		}
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->coeff = ncoeff;
		newnode->pow = npow;
		newnode->next = NULL;
		// check whether it is 1st node of LL
		if (head3 == NULL)
			head3 = temp = newnode;
		else
		{
			temp->next = newnode;
			temp = newnode;
		}		
	}
	// Case-1, all terms of poly1 are exhausted, copy the remaining terms of poly2 in poly3
	while (head2 != NULL)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->coeff = head2->coeff;
		newnode->pow = head2->pow;
		newnode->next = NULL;
		// attach this node to poly3
		temp->next = newnode;
		temp = newnode;
		head2 = head2->next;		
	}
	// Case-2, all terms of poly2 are exhausted, copy the remaining terms of poly1 in poly3
	while (head1 != NULL)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->coeff = head1->coeff;
		newnode->pow = head1->pow;
		newnode->next = NULL;
		// attach this node to poly3
		temp->next = newnode;
		temp = newnode;
		head1 = head1->next;		
	}	
	return head3;  // added poly starting node (head node) address returned
}
