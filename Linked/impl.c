#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node * next;
} node_t;

void createNodeAtEnd ( node_t ** head , int x )
{
    node_t * temp = ( node_t * ) malloc ( sizeof(node_t) );
    temp->data = x;
    temp->next = NULL;
    if ( *head == NULL ) *head = temp;
    else {
        node_t * cur;
        for( cur = *head; cur->next != NULL; cur = cur->next );
        cur->next = temp;
    }

} 
void insertAtBeg ( node_t ** head , int x ) {
    node_t * temp = ( node_t *) malloc ( sizeof(node_t) );
    temp->data = x;
    temp->next = *head;
    *head = temp;
}
void printLL ( node_t * head ) {
    node_t * temp = head;
    while ( temp != NULL ) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void insertAtPosition ( node_t ** head, int x, int pos ) {
    
    if ( pos == 1 ) {
        insertAtBeg(head, x);
    } else {
        node_t * temp = ( node_t * ) malloc ( sizeof(node_t) );
        temp->data = x;
        int j;
        node_t * cur;
        for ( cur = *head, j = 1; j != pos - 1 && cur != NULL; cur = cur->next, j++ );
        if ( cur != NULL ){
            temp->next = cur->next;
            cur->next = temp;

        } else {
            printf("Invalid pos\n");
        }

    }
}

void insertAfterElement ( node_t ** head, int x, int ele ) {
    if ( *head == NULL ) {
        printf("List is empty!\n");
    } else {
        node_t * temp = ( node_t * ) malloc ( sizeof(node_t) );
        temp->data = x;
        node_t * cur;
        cur = *head;
        if ( cur->data == ele ) { insertAtPosition(head, x,2); return;}
        for ( cur = *head ; cur != NULL && cur->data != ele; cur = cur->next );
        if ( cur != NULL) {
            temp->next = cur->next;
            cur->next = temp;

        } else {
            printf("ELement not found in the list\n");
        }

    }
}

void insertBeforeElement ( node_t ** head, int x, int ele ) {
    if ( *head == NULL ) {
        printf("List is empty!\n");
    } else {
        node_t * temp = ( node_t * ) malloc ( sizeof(node_t) );
        temp->data = x;
        node_t * cur;
        cur = *head;
        if ( cur->data == ele ) { insertAtBeg(head, x); return;}
        for ( cur = *head;cur != NULL; cur = cur->next ) {
            if ( cur->next != NULL ) {
                if ( cur->next->data == ele ) break;
            }
        }
        if ( cur != NULL) {
            temp->next = cur->next;
            cur->next = temp;

        } else {
            printf("ELement not found in the list\n");
        }

    }
}

void deleteNodeAtEnd ( node_t ** head ){
    node_t * cur = *head;
    if ( *head != NULL ) {
        if ( cur->next != NULL ) {
            for ( cur = *head ; cur != NULL && cur->next->next != NULL ; cur = cur->next );
             cur->next = NULL;
        } else {
            *head = NULL;
        }
        

    } else {
        printf("List is EMpty\n");
    }
}

void deleteNodeAtBeg ( node_t ** head )
{
    node_t * temp = *head;
    temp = temp->next;
    *head = temp;
} 

void deleteAtPos ( node_t ** head, int pos ) {
    if ( *head == NULL ){ printf("List is empty\n"); return; }
    node_t * cur = *head;
    if ( pos == 1 ) {
        deleteNodeAtBeg(head);
        return;
    } else {
        int j;
        for ( cur = *head , j = 1 ; cur!=NULL && j != pos - 1 ; cur = cur->next , j++ );
        if ( cur != NULL ) cur->next = cur->next->next; else printf("Not a valid position\n");
        
    }   

}
void deleteNodeAfterElement ( node_t ** head, int ele ) {
    if ( *head == NULL ){ printf("List is empty\n"); return; }
    node_t * cur;
    for ( cur = *head ; cur != NULL && cur->data != ele ; cur = cur->next );
    if ( cur != NULL && cur->next != NULL ) {
        cur->next = cur->next->next;
    } else {
        printf("element not found\n");
    }
}

void deleteNodeBeforeElement ( node_t ** head, int ele ) {
    if ( *head == NULL ) {printf("List is empty \n"); return;}
    node_t * cur;
    node_t * prev;
    for ( cur = *head, prev = NULL; cur != NULL && ele != cur->next->data; prev = cur, cur = cur->next );
    if ( cur != NULL ) {
        prev->next = cur->next;
    } else {
        printf("Element NOt found\n");
    }


}

node_t * searchElement ( node_t ** head, int ele ) {
    node_t * cur;
    for ( cur = *head; cur!= NULL&&cur->data != ele; cur = cur->next );
    if ( cur != NULL ) {
        return cur;  
    } else {
        return  NULL;
    }
} 

node_t * searchByPosition ( node_t ** head, int pos ) {
    node_t * cur;
    int j;
    for ( cur = *head, j = 1; cur != NULL && j != pos; cur = cur->next, j++ );
    return cur;
}


void main () {
    node_t * head = NULL;
    createNodeAtEnd(&head, 1);
    insertAtBeg(&head, 10);
    insertAtBeg(&head, 5);
    createNodeAtEnd(&head, 16);
    createNodeAtEnd(&head, 41);
    printf("OG ll = ");
    printLL(head);
    printf("\n");
    insertAtPosition(&head, 2, 5);
    insertBeforeElement(&head, 100, 5);
    printLL(head);
    printf("\n");
    insertAfterElement(&head, 7 , 100);
    printLL(head);
    printf("\n");
    deleteNodeAtBeg(&head);
    printLL(head);
    deleteAtPos(&head, 10);
    printf("\n");printLL(head);
    deleteNodeAfterElement(&head, 41);
    printf("\n");printLL(head);
    // deleteNodeBeforeElement(&head, 5);
    // printf("\n");printLL(head);
    node_t * ele = searchElement(&head,41);
    printf("\nData at element %d\n",ele->data);
    ele = searchByPosition(&head,1);
    printf("\nData at element %d\n",ele->data);

}