#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int coeff;
    int exp;
    struct node * next;
} node;

node * createNode ( int coeff, int exp ) {
    node * temp = ( node * )malloc ( sizeof(node) );
    temp->coeff = coeff;
    temp->exp = exp;
    temp->next = NULL;
    return temp;
}

typedef struct LinkedList {
    node  * head;
    node * tail;
} LinkedList;

LinkedList * LinkedListInit () {
    LinkedList * temp = ( LinkedList * )malloc ( sizeof(LinkedList) );
    temp->head = NULL;
    temp->tail = NULL;
    return temp;
}

int getInt( char * s ) {
    printf("%s ",s);
    int x;
    scanf("%d", &x);
    return x;
}

void insertAtEnd ( LinkedList * list, node * n ) {
    if ( list->head == NULL ) {
        node * temp = n;
        list->head = temp;
        list->tail = temp;
        return;
    }
    list->tail->next = n;
    list->tail = n;
}

LinkedList * inputExpression () {
    LinkedList * list = LinkedListInit();
    int n = getInt("Enter number of terms\n");
    for ( int i = 0 ; i < n; i++ ) {
        int coeff = getInt("Enter the coefficient");
        int exp = getInt("Enter the exponent");
        node * temp = createNode(coeff, exp);
        insertAtEnd(list, temp);
    }
    return list;
}

LinkedList * addPolynomials ( LinkedList * list1, LinkedList * list2 ) {
    if ( list1->head == NULL && list2->head == NULL ) return NULL;
    if ( list1->head == NULL && list2->head != NULL ) return list2;
    if ( list1->head != NULL && list2->head == NULL  ) return list1;
    LinkedList * res = LinkedListInit();
    node * cur1 = list1->head;
    node * cur2 = list2->head;
    while ( cur1 != NULL && cur2 != NULL ) {
        if ( cur1->exp == cur2->exp ) {
            node * temp = createNode(cur1->coeff+cur2->coeff, cur1->exp);
            insertAtEnd(res, temp);
            cur1 = cur1->next;
            cur2 = cur2->next;
        } else if ( cur1->exp > cur2->exp ) {
            node * temp = createNode(cur1->coeff, cur1->exp);
            insertAtEnd(res, temp);
            cur1 = cur1->next;
        } else {
            node * temp = createNode(cur2->coeff, cur2->exp);
            insertAtEnd(res, temp);
            cur2 = cur2->next;
        }
    } 

    while ( cur1 != NULL ) {
        insertAtEnd(res, createNode(cur1->coeff, cur1->exp));
        cur1 = cur1->next;
    }
    while ( cur2 != NULL ) {
        insertAtEnd(res, createNode(cur2->coeff, cur2->exp));
        cur2 = cur2->next;
    }
    return res;
}

void printLL( LinkedList * res ) {
    node * cur = res->head;
    while ( cur != NULL ) {
        printf("%dx^%d +", cur->coeff, cur->exp);
        cur = cur->next;
    }
}


int main () {
    LinkedList * list1 = inputExpression();
    LinkedList * list2 = inputExpression();
    LinkedList * res = addPolynomials(list1, list2);
    printLL(res);
}