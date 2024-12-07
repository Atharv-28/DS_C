# include <stdio.h>
# define MAX 10
int top = -1;
int stack[MAX];

void push(){
    int data;
    if(top == MAX-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter the data: ");
        scanf("%d", &data);
        top++;
        stack[top] = data;
    }
}

void pop(){
    if(top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Popped element is %d\n", stack[top]);
        top--;
    }
}

void show(){
    int i;
    if(top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        for(i=0; i<=top; i++)
        {
            printf("%d ", stack[i]);
        }
    }
}

void main(){
    int ch;
    while(1)
    {
        printf("\n1. Push\n2. Pop\n3. Show\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: show();
                    break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}