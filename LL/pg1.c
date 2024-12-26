#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; // Making it circular
        return;
    }
   
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

// Function to split the circular linked list into two halves
void splitCircularList(struct Node* head, struct Node** head1, struct Node** head2) {
    struct Node* slow = head;
    struct Node* fast = head;

    if (head == NULL) {
        return;
    }

    // Use the fast and slow pointer technique to find the middle of the list
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // If the number of nodes is even, move fast to the last node
    if (fast->next->next == head) {
        fast = fast->next;
    }

    // Set the head pointers for the two halves
    *head1 = head;
    *head2 = slow->next;

    // Make the first half circular
    slow->next = *head1;

    // Make the second half circular
    fast->next = *head2;
}

// Function to print the circular linked list
void printCircularList(struct Node* head) {
    if (head == NULL) {
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    int n, data;

    printf("Enter the number of elements in the circular linked list: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    printf("Original Circular Linked List: \n");
    printCircularList(head);

    // Split the list into two halves
    splitCircularList(head, &head1, &head2);

    printf("First Circular Linked List: \n");
    printCircularList(head1);

    printf("Second Circular Linked List: \n");
    printCircularList(head2);

    return 0;
}