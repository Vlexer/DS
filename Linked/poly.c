#include<stdio.h>
#include<stdlib.h> 

typedef struct node_t {
    int coeff;
    int exp;
    struct node_t * next;

} node_t;

void createNode ( node_t ** head, int coeff, int exp ) {
    node_t * temp = ( node_t * )malloc(sizeof(node_t));
    temp->coeff = coeff;
    temp->exp = exp;
    temp->next = NULL;
    node_t * cur;
    for ( cur = *head; cur != NULL && cur->next != NULL; cur = cur->next );
    if ( cur == NULL ) *head = temp;
    else cur->next = temp;
}

void printLL ( node_t * head ) {
    node_t * cur;
    for ( cur = head; cur != NULL; cur = cur->next ) {
        
        printf(" Coeff = %d Exp = %d ",cur->coeff,cur->exp);

    }
}

node_t * add ( node_t ** head1, node_t ** head2 ) {
    node_t * res = NULL;
    node_t * cur1 = *head1;
    node_t * cur2 = *head2;
    // This loops executes till either one of the polynomial exhausts
    while ( cur1 != NULL && cur2 != NULL ) {
        // First Check if the curr nodes have same exponent
        if ( cur1->exp == cur2->exp ) {
            // If so create a new node to the result linked list with the same exponent and its coeff will be the sum of the curr nodes;
            createNode(&res, cur1->coeff + cur2->coeff, cur1->exp);
            // Move Both the current node pointers to its next position
            cur1 = cur1->next;
            cur2 = cur2->next;

        } else {
            // If the exponent are not Equal then find the maximum exponent and add it to the result linked list;
            if ( cur1->exp > cur2->exp ) {
                // Add the maximum node to the result
                createNode(&res, cur1->coeff, cur1->exp);
                cur1 = cur1->next;

            } else {
                createNode( &res, cur2->coeff, cur2->exp );
                cur2 = cur2->next;
            }
        }
    }
    // Now Append the remaining nodes to the result 
    if ( cur1 != NULL ) {
        node_t * temp;
        for ( temp = res; temp->next != NULL; temp = temp->next );
        temp->next = cur1;
    } else if ( cur2 != NULL ) {
        node_t * temp;
        for ( temp = res; temp->next != NULL; temp = temp->next );
        temp->next = cur2;
    }
    return res;
}

void main () {
    node_t * head1 = NULL;
    printf("Enter the number of terms in the first Polynomial\n");
    int n1;
    scanf("%d",&n1);
    for(int i = 0; i < n1; i++) {
        int coeff, exp;
        printf("Enter the coefficient\n");
        scanf("%d",&coeff);
        printf("Enter the Exponent\n");
        scanf("%d",&exp);
        createNode(&head1, coeff, exp);
    }
    printf("Enter the number of terms in the first Polynomial\n");
    int n2;
    node_t * head2 =NULL;
    scanf("%d",&n2);
    for(int i = 0; i < n2; i++) {
        int coeff, exp;
        printf("Enter the coefficient\n");
        scanf("%d",&coeff);
        printf("Enter the Exponent\n");
        scanf("%d",&exp);
        createNode(&head2, coeff, exp);
    }
    
    node_t * res = add( &head1, &head2 );
    printLL(res);
    
}