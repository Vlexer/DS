// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>
// typedef struct node_t {
//     int data;
//     struct node_t * next;
// } node_t;

// void createNode ( node_t ** head , int x)  {
//     node_t * temp = (node_t * ) malloc ( sizeof(node_t) );
//     temp->data = x;
//     temp->next = NULL;
//     node_t * cur;
//     if ( *head == NULL ) {
//         *head = temp;
//     } else {

//         for ( cur = *head; cur->next != NULL; cur = cur->next );
//         cur->next = temp;
//     }

// }
// node_t * deleteNode ( node_t ** head ) {
//     if ( *head == NULL ) return NULL;
//     node_t * cur = *head;
//     if ( cur->next == NULL ) {
//         node_t * temp = cur;
//         *head = NULL;
//         return temp;
        
//     } 
//     // for( cur = *head; cur->next->next != NULL; cur = cur->next );
//     // node_t * temp = cur->next;
//     // cur->next = NULL;
//     // return temp;
//     node_t * temp = *head;

//     cur = cur->next;
//     *head = cur;
//     return temp;
// }

// void printLL( node_t * head ) {
//     for ( node_t * cur = head; cur != NULL; cur = cur-> next ) {
//         printf("%d ",cur->data);
//     }
//  }

//  void main () {
//     // node_t * head = NULL;
//     // int i = 1;
//     // while ( i != 0 ) {
//     //     printf("Enter the element to add to the linked list\n");
//     //     int x;
//     //     scanf("%d",&x);
//     //     createNode(&head,x);
//     //     printf("Enter y to insert new element or n\n");
//     //     scanf("%d",&i);
//     // } 
//     printf("enter the number of arrays in the list\n");
//     int n;
//     node_t * heads[10] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
//     scanf("%d",&n);
//     int arr[n];
//     int max = -2147483648;
//     printf("enter the array elements\n");
//     for(int i = 0 ; i < n; i++) {
//         scanf("%d",&arr[i]);
//         if ( arr[i] > max ) max = arr[i];
//     }
//     int temp[n];
//     int j = 0;
//     int k = 1;
//     int maxIter = log10(max) + 1;
//     while ( maxIter > 0 ){
//         for(int i = 0 ; i < n; i++) {
//             int lastdig = (arr[i]/k) % 10;
//             createNode(&heads[lastdig], arr[i]);
            
//         }
//         for ( int i = 0; i < 10; i++ ) {
//             while( heads[i] != NULL ) {
//                 // temp[j++] = deleteNode(&heads[i])->data;
//                 node_t * deletedNoded;
//                 deletedNoded = deleteNode(&heads[i]);
//                 if ( deletedNoded != NULL ) {
//                     temp[j++] = deletedNoded->data;
//                 }
//             }
//         }
//         for (int i = 0; i < n; i++)
//         {
//             /* code */
//             arr[i] = temp[i];
//         }
        
//         j = 0;
//         maxIter--;
//         k *= 10;
//         printf("\n");
//     }
//     for (int  i = 0; i < n; i++)
//     {
//         /* code */
//         printf("%d ",arr[i]);
//     }
    
//   }

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>  // For INT_MIN

typedef struct node_t {
    int data;
    struct node_t * next;
} node_t;

void createNode ( node_t ** head , int x)  {
    node_t * temp = (node_t * ) malloc ( sizeof(node_t) );
    temp->data = x;
    temp->next = NULL;
    if (*head == NULL) {
        *head = temp;
    } else {
        node_t * cur = *head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = temp;
    }
}

node_t * deleteNode ( node_t ** head ) {
    if (*head == NULL) return NULL;
    node_t * temp = *head;
    *head = (*head)->next;
    return temp;
}

void printLL( node_t * head ) {
    for (node_t * cur = head; cur != NULL; cur = cur-> next) {
        printf("%d ", cur->data);
    }
}

void main () {
    printf("Enter the number of arrays in the list\n");
    int n;
    node_t * heads[10] = {NULL};
    scanf("%d", &n);
    
    int arr[n];
    int max = INT_MIN;  // Use INT_MIN from limits.h for clarity
    printf("Enter the array elements\n");
    for (int i = 0 ; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max) max = arr[i];
    }
    
    int temp[n];
    int j = 0;
    int k = 1;
    int maxIter = (int)log10(max) + 1;  // Ensure integer conversion
    
    while (maxIter > 0) {
        // Distribute numbers into buckets based on the current digit
        for (int i = 0 ; i < n; i++) {
            int lastdig = (arr[i] / k) % 10;
            createNode(&heads[lastdig], arr[i]);
        }
        
        // Collect numbers back from buckets
        for (int i = 0; i < 10; i++) {
            while (heads[i] != NULL) {
                node_t * deletedNode = deleteNode(&heads[i]);
                if (deletedNode != NULL) {
                    temp[j++] = deletedNode->data;
                    free(deletedNode);  // Free the node after deletion
                }
            }
        }
        
        // Copy the sorted elements back to the original array
        for (int i = 0; i < n; i++) {
            arr[i] = temp[i];
        }
        
        // Reset for the next pass
        j = 0;
        maxIter--;
        k *= 10;
        printf("\n");
    }
    
    // Output the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
