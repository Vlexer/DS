#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node * next;

} node;

node * createNode ( int data ) {
    node * temp = ( node * ) malloc (  sizeof (node) );
    temp->data = data;
    temp->next = NULL;
}

int getInt( char * s ) {
    printf("%s ", s);
    int x;
    scanf("%d", &x);
    return x;
}

typedef struct CircularLinkedList {
    node * head;
    node * tail;
} CircularLinkedList;

CircularLinkedList * CLLinit () {
    CircularLinkedList * temp = ( CircularLinkedList * )malloc ( sizeof( CircularLinkedList ) );
    temp->head = NULL;
    temp->tail = NULL;
    return temp;
}

void insertNodeBeg ( CircularLinkedList * list, int x ) {
    if ( list->head == NULL && list->tail == NULL ) {
        node * temp = createNode(x);
        list->head = temp;
        list->tail = temp;
        list->tail->next = list->head;
        return;
    }
    node * temp = createNode(x);
    temp->next = list->head;
    list->head = temp;
    list->tail->next = temp;
}

void insertAtEnd ( CircularLinkedList * list, int x ) {
    if ( list->head == NULL && list->tail == NULL ) {
       node * temp = createNode(x);
        list->head = temp;
        list->tail = temp;
        list->tail->next = list->head;
        return;
    }
    node * temp = createNode(x);
    temp->next = list->head;
    list->tail->next = temp;
    list->tail = temp;
}

void insertAtPos ( CircularLinkedList * list, int x, int pos ) {
    if ( pos == 0 ) {
        insertNodeBeg(list, x);
        return;
    }

    node * cur = list->head;
    int jumps = 0;
    while ( jumps < pos - 1 && cur->next != list->head ) {
        cur = cur->next;
        jumps ++;
    }
    if ( jumps < pos - 1 ) {
        printf("Invalid position\n");
        return;
    }
    node * temp = createNode(x);
    temp->next = cur->next;
    cur->next = temp;
    if ( cur == list->tail ) list->tail = temp;
}

int isEmpty ( CircularLinkedList * list ) {
    return list->head == NULL && list->tail == NULL;
}

void printLL ( CircularLinkedList * list ) {
    if ( isEmpty(list) ) return;
    node * cur = list->head;
    printf("%d -> ", cur->data);
    cur = cur->next;
    while ( cur != list->head ) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
}

void DeleteLLBeg ( CircularLinkedList * list ) {
    if ( list->head == list->tail ) {
        list->head = NULL;
        list->tail = NULL;
        return;
    }
    node * newHead = list->head->next;
    list->tail->next = newHead;
    list->head = newHead;
}

void DeleteLLEnd ( CircularLinkedList * list ) {
    if ( list->head == list->tail ) {
        list->head = NULL;
        list->tail = NULL;
        return;
    }
    node * cur = list->head;
    while ( cur->next->next != list->head ) {
        cur = cur->next;
    }
    list->tail = cur;
    free(cur->next);
    list->tail->next = list->head;
    
}

int main () {
    CircularLinkedList * list = CLLinit();
    insertAtEnd(list, 1);
    insertAtEnd(list, 2);
    insertAtEnd(list, 3);
    insertAtEnd(list, 4);
    insertAtPos(list, 10, 3);
    printLL(list);
}