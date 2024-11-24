// Implementation of static dequeue
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct queue
{
	int data[SIZE];
	int front, rear;
};

// fn declarations
void addl(struct queue *,int);
void addr(struct queue *,int);
int dell(struct queue *);
int delr(struct queue *);
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
		printf("Operations on Dequeue\n");
		printf("1. Add from Left\n");
		printf("2. Add from Right\n");	
		printf("3. Delete from Left\n");
		printf("4. Delete from Right\n");		
		printf("5. Display Queue\n");
		printf("6. Exit\n\n");
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
					addl(&q,no);
				}
				break;
				
			case 2:
				if (isqfull(&q))
					printf("Queue is full");
				else
				{
					printf("Enter the no :- ");
					scanf("%d",&no);
					addr(&q,no);
				}
				break;
				
			case 3:
				if (isqempty(&q))
					printf("Queue is empty");
				else
					printf("Element deleted is %d",dell(&q));
					
				break;
				
			case 4:
				if (isqempty(&q))
					printf("Queue is empty");
				else
					printf("Element deleted is %d",delr(&q));
					
				break;				
				
				
			case 5:
				if (isqempty(&q))
					printf("Queue is empty");
				else
					displayq(&q);
					
				break;
				
			case 6:
				exit(0);
				
			default:
				printf("Error in choice, try again...");				
		}
		printf("\n");
		system("pause");	
	}  // end of loop
	return 0;
}

void addl(struct queue *pq,int no)
{
	int i;
	// case -1, queue is empty
	if (isqempty(pq))
		pq->front = pq->rear = 0;
	else
	{
		if (pq->front != 0)
			pq->front--;
		else
		{
			// shift elements to the right
			pq->rear++;
			for (i=pq->rear;i!=pq->front;i--)
				pq->data[i] = pq->data[i-1];
		}	
	}
	pq->data[pq->front] = no;
}

void addr(struct queue *pq,int no)
{
	int i;
	// case -1, queue is empty
	if (isqempty(pq))
		pq->front = pq->rear = 0;
	else
	{
		if (pq->rear != SIZE-1)
			pq->rear++;
		else
		{
			// shift elements to the right
			pq->front--;
			for (i=pq->front;i!=pq->rear;i++)
				pq->data[i] = pq->data[i+1];
		}	
	}
	pq->data[pq->rear] = no;
}

int dell(struct queue *pq)
{
	int no;
	no = pq->data[pq->front];
	pq->front++;
	// check whether front crosses rear
	// if so, it means the last element is deleted & now queue is empty
	if (pq->front > pq->rear)
		pq->front = pq->rear = -1;  // reset front & rear to -1

	return no;
}

int delr(struct queue *pq)
{
	int no;
	no = pq->data[pq->rear];
	pq->rear--;
	// check whether front crosses rear
	// if so, it means the last element is deleted & now queue is empty
	if (pq->rear < pq->front)
		pq->front = pq->rear = -1;  // reset front & rear to -1

	return no;
}

int isqempty(struct queue *pq)
{
	if (pq->front == -1)
		return 1;
		
	return 0;	
}

int isqfull(struct queue *pq)
{
	if (pq->front == 0 && pq->rear == SIZE-1)
		return 1;
		
	return 0;
}

void displayq(struct queue *pq)
{
	int i;
	for (i=pq->front;i<=pq->rear;i++)
		printf("%d  ",pq->data[i]);
}
