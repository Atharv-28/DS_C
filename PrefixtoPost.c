#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define the maximum size of the stack
#define MAX 100

// Stack structure
typedef struct {
    char items[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initializeStack(Stack* s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(Stack* s) {
    return s->top == MAX - 1;
}

// Function to push an element onto the stack
void push(Stack* s, char value) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->items[++s->top] = value;
}

// Function to pop an element from the stack
char pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->items[s->top--];
}

// Function to peek the top element of the stack
char peek(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return -1;
}

// Function to check the precedence of operators
int precedence(char operator) {
    if (operator == '+' || operator == '-') {
        return 1;
    }
    if (operator == '*' || operator == '/') {
        return 2;
    }
    return 0;
}

// Function to check if the character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char* infix, char* postfix) {
    Stack stack;
    initializeStack(&stack);
    int i = 0, k = 0;

    while (infix[i] != '\0') {
        char current = infix[i];

        // If the character is an operand, add it to the postfix expression
        if (isalnum(current)) {
            postfix[k++] = current;
        }
        // If the character is '(', push it onto the stack
        else if (current == '(') {
            push(&stack, current);
        }
        // If the character is ')', pop from the stack until '(' is found
        else if (current == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[k++] = pop(&stack);
            }
            pop(&stack); // Discard the '(' from the stack
        }
        // If the character is an operator
        else if (isOperator(current)) {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(current)) {
                postfix[k++] = pop(&stack);
            }
            push(&stack, current);
        }
        i++;
    }

    while (!isEmpty(&stack)) {
        postfix[k++] = pop(&stack);
    }

    postfix[k] = '\0'; 
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("The postfix expression is: %s\n", postfix);

    return 0;
}
