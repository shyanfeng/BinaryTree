#include <stdio.h>
#include "BinaryTree.h"
#include "Stack.h"

void binaryTreeTraverseInOrder(Node *rootPtr){
	Node *currentNode = rootPtr;
	Stack *stackPtr = stackNew();
	printf("created a stack\n");
    
    currentNode->state = ENTERED_NODE;
    
    while(currentNode != NULL){
        if(currentNode->left == NULL && currentNode->right == NULL){
           printf("current=%d\n", currentNode->data);
           printf("bbb\n");
           currentNode->state = VISITED_RIGHT_NODE;
           display(currentNode->data);
           
        }else if(currentNode->left != NULL && currentNode->state == ENTERED_NODE){
            printf("current=%d\n", currentNode->data);
            printf("aaa\n");
            stackPush(stackPtr, currentNode);
            printf("push=%d\n", currentNode->data);
            currentNode = currentNode->left;
        }
        
        if(currentNode->state == VISITED_RIGHT_NODE){
            currentNode->state = VISITED_LEFT_NODE;
            currentNode = stackPop(stackPtr);
            printf("ggg");
        }else if(currentNode->state == VISITED_LEFT_NODE){
            if(currentNode->right == NULL){
                display(currentNode->data);
                currentNode = stackPop(stackPtr);
            }
        }
    }
    
    stackDel(stackPtr);
	printf("deleted a stack\n");
    
   /* while(1){
        if(currentNode->left == NULL || currentNode->state == ENTERED_NODE){
            display(currentNode->data);
            currentNode->state = VISITED_LEFT_NODE;
        }
        
        if(currentNode->right != NULL || currentNode->state == VISITED_LEFT_NODE){
                if(currentNode->right == NULL){
                    currentNode->state = VISITED_RIGHT_NODE;
                    currentNode = stackPop(stackPtr);
                    stackDel(stackPtr);
                    printf("deleted a stack\n");
                    break;
                }*//*else{
                    currentNode->state = ENTERED_NODE;
                    printf("current=%d\n", currentNode->data);
                    stackPush(stackPtr, currentNode);
                    printf("push=%d\n", currentNode->data);
                    currentNode = currentNode->right;
                    printf("current=%d\n", currentNode->data);
                    display(currentNode->data);
                    currentNode = stackPop(stackPtr);
                    printf("pop=%d\n", currentNode->data);
                }*/
         /*   }
        
        if(currentNode->left != NULL){
            currentNode->state = ENTERED_NODE;
            printf("current=%d\n", currentNode->data);
            stackPush(stackPtr, currentNode);
            printf("push=%d\n", currentNode->data);
            currentNode = currentNode->left;
            printf("current=%d\n", currentNode->data);
            
            // NO CHILD
            if(currentNode->left == NULL){
                display(currentNode->data);
                currentNode = stackPop(stackPtr);
                printf("pop=%d\n", currentNode->data);
                
            }
        }
    }*/
    
    
    
// while(currentNode != NULL){
	// if(currentNode->left != NULL /*|| currentNode->state == ENTERED_NODE*/){
		// currentNode->state = ENTERED_NODE;
		// printf("current=%d\n", currentNode->data);
		// stackPush(stackPtr, currentNode);
		// printf("push=%d\n", currentNode->data);
		// currentNode = currentNode->left;
		// printf("current=%d\n", currentNode->data);
        // if(currentNode->left == NULL){
			// display(currentNode->data);
			// currentNode = stackPop(stackPtr);
			// printf("pop=%d\n", currentNode->data);
			// currentNode->state = VISITED_LEFT_NODE;
			// display(currentNode->data);
            // currentNode = stackPop(stackPtr);
		// }
	// }else if(currentNode->right != NULL || currentNode->state == VISITED_LEFT_NODE){
		// currentNode->state = ENTERED_NODE;
		// printf("current=%d\n", currentNode->data);
        // display(currentNode->data);
		// stackPush(stackPtr, currentNode);
		// printf("push=%d\n", currentNode->data);
		// currentNode = currentNode->right;
		// printf("current=%d\n", currentNode->data);
        // if(currentNode->right == NULL){
            // display(currentNode->data);
			// currentNode = stackPop(stackPtr);
			// printf("pop=%d\n", currentNode->data);
			// currentNode->state = VISITED_RIGHT_NODE;
            // currentNode = stackPop(stackPtr);
        // }
	// }else{
        // if(currentNode->left == NULL){
            // currentNode->state == VISITED_LEFT_NODE;
        // }
        
        // if(currentNode->state == VISITED_LEFT_NODE){
            // if(currentNode->right == NULL){
                // currentNode->state == VISITED_RIGHT_NODE;
               // }
        // }
		// display(currentNode->data);
		// printf("current=%d\n", currentNode->data);
		// currentNode = stackPop(stackPtr);
	// }
    // }


	// stackDel(stackPtr);
	// printf("deleted a stack\n");
    

}