# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>

# define MAX 10
int Queue[MAX];
int rear = -1, front = 0;

void enqueue()
{
    int data;
    if(rear == MAX-1)
    {
        printf("Queue is full");
    }
    else{
        printf("Enter data : ");
        scanf("%d",&data);
        rear+=1;
        Queue[rear] = data;
    }
}
void dequeue()
{
    if(front == rear)
    {
        printf("Queue is Empty");
    }
    else{
        printf("Dequeued Element is %d",Queue[front]);
        front++;
    }
}

void Show()
{
    int i;
    for(i=front+1; i<=rear; i++)
    {
        printf("%d   ",Queue[i]);
    }
}

void main()
{
    int ch;
    while(1)
    {
        printf("\n1. Push\n2. Pop\n3. Show\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: Show();
                    break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}