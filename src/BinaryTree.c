#include <stdio.h>
#include "BinaryTree.h"
#include "Stack.h"

void binaryTreeTraverseInOrder(Node *rootPtr){
	Node *currentNode = rootPtr;
	Stack *stackPtr = stackNew();
	printf("created a stack\n");
    
    currentNode->state = ENTERED_NODE;
    
    while(currentNode != NULL){
        if((currentNode->left == NULL) && (currentNode->right == NULL) && (currentNode->state == ENTERED_NODE)){
           display(currentNode->data);
           currentNode->state = VISITED_RIGHT_NODE;
        }else if(currentNode->left != NULL && currentNode->state == ENTERED_NODE){
            stackPush(stackPtr, currentNode);
            currentNode = currentNode->left;
            currentNode->state = ENTERED_NODE;
		}else if((currentNode->right != NULL) && (currentNode->state == VISITED_LEFT_NODE)){
            display(currentNode->data);
            stackPush(stackPtr, currentNode);
            currentNode = currentNode->right;
            currentNode->state = ENTERED_NODE;
        }else if(currentNode->right == NULL && currentNode->state == VISITED_LEFT_NODE){
            display(currentNode->data);
            currentNode->state = VISITED_RIGHT_NODE;
        }else{
			if(currentNode->state == ENTERED_NODE){
                currentNode->state = VISITED_LEFT_NODE;
			}else if(currentNode->state == VISITED_LEFT_NODE){
                currentNode->state = VISITED_RIGHT_NODE;
            }
        }
		
        if(currentNode->state == VISITED_RIGHT_NODE){
            currentNode = stackPop(stackPtr);
			if(currentNode == NULL){
				break;
			}
			if(currentNode->right != NULL && currentNode->state == VISITED_LEFT_NODE){
                currentNode->state = VISITED_RIGHT_NODE;
            }else if(currentNode->state == ENTERED_NODE){
                currentNode->state = VISITED_LEFT_NODE;
            }
        }
    }
    
    stackDel(stackPtr);
	printf("deleted a stack\n");

}

void binaryTreePrintInOrder(Node * node){
	if(node != NULL){
		binaryTreePrintInOrder(node->left);
		printf("Node: %d\n", node->data);
		binaryTreePrintInOrder(node->right);
	}
}