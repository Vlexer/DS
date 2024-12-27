#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    char data;
    struct node * next;
    struct node * prev;
} node;

typedef struct DLL {
    node * head;
    node * tail;
} DLL;

node * createNode ( char x ) {
    node * temp = ( node * )malloc ( sizeof(node) );
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;
} 

void insertAtEnd ( DLL * list, char c ) {
    if ( list->head == NULL  ) {
        node * temp = createNode(c);
        list->head = temp;
        list->tail = temp;
        return;
    }
    node * temp = createNode(c);
    temp->data = c;
    list->tail->next = temp;
    temp->prev = list->tail;
    list->tail = temp;
}

DLL * DLLinit( char * s ) {
    DLL *temp = ( DLL * )malloc ( sizeof(DLL) );
    int i = 0;
    temp->head = NULL;
    temp->tail = NULL;
    while ( s[i] != '\0' ) {
        insertAtEnd(temp, s[i]);
        i++;
    }
    return temp;
}

void printDLL ( DLL * list ) {
    if ( list->head == NULL ) return;
    node * cur = list->head;
    while ( cur != NULL ) {
        printf("%c", cur->data);
        cur = cur->next;
    }
}

void isPalindrome ( DLL * list ) {
    node * head = list->head;
    node * tail = list->tail;
    while ( head != tail ) {
        if ( head->data != tail->data ) {
            printf("NOT PALINDROME\n");
            return;
        }
        head = head->next;
        tail = tail->prev;
        if ( head->next == tail ) {
            break;
        }
    }
    printf(" IS PALINDROME\n");

}

int main () {
    DLL * list = DLLinit("1234");
    printDLL(list);
    isPalindrome(list);
    return 0;
}