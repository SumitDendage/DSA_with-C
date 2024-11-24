// Implementation of static linear queue
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct queue
{
	int data[SIZE];
	int front, rear;
};

// fn declarations
void addq(struct queue *,int);
int delq(struct queue *);
int isqempty(struct queue *);
int isqfull(struct queue *);
void displayq(struct queue *);

int main()
{
	struct queue q;
	q.front = q.rear = -1;  // initialise the queue
	int choice, no;
	while (1)
	{
		system("cls");
		printf("Operations on Static Linear Queue\n");
		printf("1. Add to Queue\n");
		printf("2. Delete from Queue\n");
		printf("3. Display Queue\n");
		printf("4. Exit\n\n");
		printf("Enter your choice :- ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				if (isqfull(&q))
					printf("Queue is full");
				else
				{
					printf("Enter the no :- ");
					scanf("%d",&no);
					addq(&q,no);
				}
				break;
				
			case 2:
				if (isqempty(&q))
					printf("Queue is empty");
				else
					printf("Element deleted is %d",delq(&q));
					
				break;
				
			case 3:
				if (isqempty(&q))
					printf("Queue is empty");
				else
					displayq(&q);
					
				break;
				
			case 4:
				exit(0);
				
			default:
				printf("Error in choice, try again...");				
		}
		printf("\n");
		system("pause");	
	}  // end of loop
	return 0;
}

void addq(struct queue *pq,int no)
{
	pq->rear++;
	pq->data[pq->rear] = no;
	// imp - check whether it is 1st element
	if (pq->front == -1)
		pq->front = 0;
}

int delq(struct queue *pq)
{
	return pq->data[pq->front++];
}

int isqempty(struct queue *pq)
{
	if (pq->front == -1 || pq->front > pq->rear)
		return 1;
		
	return 0;	
}

int isqfull(struct queue *pq)
{
	if (pq->rear == SIZE-1)
		return 1;
		
	return 0;
}

void displayq(struct queue *pq)
{
	int i;
	for (i=pq->front;i<=pq->rear;i++)
		printf("%d  ",pq->data[i]);
}
