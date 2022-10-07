#include <stdio.h>
#include <stdlib.h>

#define MAX 50

void insert();
void delete();
void display();

int queue_array[MAX];
int rear = -1;
int front = -1;

int main(void)
{
	int choice;
	while (1)
	{
		printf("1.Insert element to queue n\n");
		printf("2.Delete element from queue n\n");
		printf("3.Display all elements of queue n\n");
		printf("4.Quit n\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
			case 4:
				exit(1);
			default:
				printf("Failed, wrong choice n");
		}
	}
	return (0);
}

void insert()
{
	int item;
	if (rear == MAX -1)
		printf("Queue Overflow n\n");
	else
	{
		if (front == -1)
			front = 0;
		printf("Insert the element in queue: ");
		scanf("%d", &item);
		rear++;
		queue_array[rear] = item;
	}
}

void delete()
{
	if (front == -1 || front > rear)
	{
		printf("Queue underflow n\n");
		return;
	}
	else
	{
		printf("Element deleted in queue is: %d\n", queue_array[front]);
		front++;
	}
}

void display()
{
	int i;
	if (front == -1)
		printf("Queue is empty n\n");
	else
	{
		printf("Queue is: n");
		for (i = front; i <= rear; i++)
		{
			printf("%d ", queue_array[i]);
			printf("n");
		}
		printf("\n");
	}
}

