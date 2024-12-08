# include <stdio.h>
# include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next; 
} Node; 

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, int data)
{
    Node* newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next= newNode;
}

void displayList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        printf("%d  ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteFirst(Node** head)
{
    if(*head == NULL)
    {
        printf("SLL is empty!");
    }
    else{
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    printf("Singly Linked List: ");
    displayList(head);

    deleteFirst(&head);
    printf("After deleting first node: ");
    displayList(head);

    return 0;
}