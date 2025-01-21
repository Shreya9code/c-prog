#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create the list
Node* createList() 
{
    Node* head = NULL;
    Node* tail = NULL;
    int data, more;
    
    printf("Enter data for node: ");
    scanf("%d", &data);
    
    head = createNode(data);
    tail = head;
    
    printf("Add more nodes? (1 for Yes, 0 for No): ");
    scanf("%d", &more);
    
    while (more) {
        printf("Enter data for the next node: ");
        scanf("%d", &data);
        tail->next = createNode(data);
        tail = tail->next;
        
        printf("Do you want to add more nodes? (1 for Yes, 0 for No): ");
        scanf("%d", &more);
    }
    
    return head;
}

// Function to insert a node at a specific position
Node* insertNode(Node** head, int data, int position) 
{
    Node* newNode = createNode(data);
    Node* temp = *head;
    
    if (position == 0) 
    { // Insert at the front
        newNode->next = *head;
        *head = newNode;
        return head;
    }
    int i=0;
    while(temp )
    {
        temp = temp->next;
        i++;
    }
    /*for (int i = 0; temp != NULL && i < position - 1; i++) 
        temp = temp->next;*/
    
    if (temp == NULL)
    {
        printf("Position out of bounds\n");
        free(newNode);
        return NULL;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
    //return newNode;
}

// Function to insert a node after a given node
void insertAfter(Node* head, int data, int target)
{
    Node* temp = head;
    
    while (temp != NULL && temp->data != target) 
        temp = temp->next;
    
    if (temp == NULL) 
    {
        printf("Node with data %d not found\n", target);
        return;
    }
    
    Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to insert a node before a given node
void insertBefore(Node* head, int data, int target) {
    Node* temp = head;
    Node* prev = NULL;
    
    if (temp != NULL && temp->data == target) {
        Node* newNode = createNode(data);
        newNode->next = head;
        head = newNode;
        return;
    }
    
    while (temp != NULL && temp->data != target) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Node with data %d not found\n", target);
        return;
    }
    
    Node* newNode = createNode(data);
    prev->next = newNode;
    newNode->next = temp;
}

// Function to delete a node at a specific position
void deleteNode(Node** head, int position) 
{
    if (*head == NULL) 
    {
        printf("List is empty\n");
        return ;
    }
    
    Node* temp = head;
    
    if (position == 0) 
    { // Delete the head node
        head = temp->next;
        free(temp);
        return ;
    }
    
    Node* prev = NULL;
    for (int i = 0; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) 
    {
        printf("Position out of bounds\n");
        return NULL;
    }
    
    prev->next = temp->next;
    free(temp);
}

// Function to display the list
void displayList(Node* head) 
{
    Node* temp = head;
    if (temp == NULL) 
    {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to search for an element in the list
void searchList(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL) 
    {
        if (temp->data == key) 
        {
            printf("Element %d found\n", key);
            return;
        }
        temp = temp->next;
    }
    printf("Element %d not found\n", key);
}

// Main function to drive the menu
int main() 
{
    Node* head = NULL;
    int choice, data, position, target;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create List\n");
        printf("2. Insert at Position\n");
        printf("3. Insert After a Node\n");
        printf("4. Insert Before a Node\n");
        printf("5. Delete from Position\n");
        printf("6. Display List\n");
        printf("7. Search in List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                head = createList();
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert (0 for front, n for nth position): ");
                scanf("%d", &position);
                head=insertNode(head, data, position);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d",&data);
                printf("Enter target node data to insert after: ");
                scanf("%d", &target);
                insertAfter(head, data, target);
                break;
            case 4:
                printf("Enter data to insert: ");
                scanf("%d",&data);
                printf("Enter target node data to insert before: ");
                scanf("%d", &target);
                insertBefore(head, data, target);
                break;
            case 5:
                printf("Enter position to delete (0 for front, n for nth position): ");
                scanf("%d", &position);
                head=deleteNode(head, position);
                break;
            case 6:
                displayList(head);
                break;
            case 7:
                printf("Enter data to search: ");
                scanf("%d",&data);
                searchList(head, data);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}