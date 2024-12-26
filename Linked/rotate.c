#include<stdio.h>
#include<stdlib.h>

typedef struct  node_t
{
    /* data */
    int data;
    struct node_t * next;
} node_t ;

void createNode(  node_t ** head, int x ) 

{
    node_t * temp = (node_t *) malloc ( sizeof(node_t) );
    temp->data = x;
    temp->next = NULL;

    if ( *head == NULL) {
        *head = temp;
    } else {
        node_t * cur;
        for(cur = *head; cur->next != NULL ; cur = cur->next);
        cur->next =temp;
    }
}

node_t *  deleteNode ( node_t **head ) {
    if ( *head == NULL ) return NULL;
    node_t * cur = *head;
    if ( cur->next == NULL ) 
    {
        *head = NULL;
        return cur;
    }

}

void main () {
    node_t * head = NULL;
    int i = 1;
    while ( i != 0 ) {
        printf("Enter the element to add to the linked list\n");
        int x;
        scanf("%d",&x);
        createNode(&head,x);
        printf("Enter y to insert new element or n\n");
        scanf("%d",&i);
    } 
    printf("Enter K\n");
    int k;
    scanf("%d",&k);
    int n = 0;
    node_t * cur = head;
    for ( cur = head; cur!= NULL; cur = cur->next){
        n++;
    }
    printf("%d",n);


}
