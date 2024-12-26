#include<stdio.h>
#include<stdlib.h>

typedef struct node_t {
    int coeff;
    int power;
    struct node_t * next;
} node_t;

void createNodeAtEnd(node_t **head, int coeff, int exp) {
    node_t *temp = (node_t *)malloc(sizeof(node_t)); // Allocate memory for the new node
    temp->coeff = coeff;
    temp->power = exp; // Note: Corrected from 'power' to 'exp' for consistency
    temp->next = NULL;

    if (*head == NULL) {
        // If the list is empty, make the new node the head
        *head = temp;
    } else {
        // Traverse to the end of the list
        node_t *cur = *head;
        while (cur->next != NULL) { // Find the last node
            cur = cur->next;
        }
        cur->next = temp; // Link the new node to the last node
    }
}

node_t * polyAdd ( node_t ** head1, node_t ** head2 ) {
    node_t * res = NULL;
    node_t * cur1 = *head1, * cur2 = *head2;
    while ( cur1 != NULL && cur2 != NULL ) {
        if ( cur1->power == cur2->power ) {
            createNodeAtEnd(&res, cur1->coeff + cur2->coeff, cur1->power);
            cur1 = cur1->next;
            cur2 = cur2->next;
        } else if ( cur1->power > cur2->power ) {
            createNodeAtEnd(&res, cur1->coeff, cur1->power);
            cur1 = cur1->next;
        } else {
            createNodeAtEnd(&res, cur2->coeff, cur2->power);
            cur2 = cur2->next;
        }
    }
    if ( cur1 != NULL ) {
        while ( cur1 != NULL ) {
            createNodeAtEnd(&res, cur1->coeff, cur1->power);
            cur1= cur1->next;
        }
    }
    if ( cur2 != NULL ) {
        while ( cur2 != NULL ) {
            createNodeAtEnd(&res, cur2->coeff, cur2->power);
            cur2 =cur2->next;
        }
    }
    return res;
}
void printPoly(node_t* head) {
    node_t* cur = head;
    while (cur != NULL) {
        printf("%dx^%d ", cur->coeff, cur->power);
        cur = cur->next;
    }
    printf("\n");
}
int main() {
    node_t* poly1 = NULL;
    node_t* poly2 = NULL;

    // Populate poly1 and poly2
    createNodeAtEnd(&poly1, 3, 5); // 3x^4
    createNodeAtEnd(&poly1, 2, 2); // 2x^2

    createNodeAtEnd(&poly2, 5, 4); // 5x^4
    createNodeAtEnd(&poly2, 4, 2); // 4x^2
    createNodeAtEnd(&poly2, 1, 0); // 1

    node_t* result = polyAdd(&poly1, &poly2);

    // Print the resulting polynomial
    printPoly(result); // Output should be 8x^4 6x^2 1

    return 0;
}