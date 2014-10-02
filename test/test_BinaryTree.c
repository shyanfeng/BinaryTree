#include "unity.h"
#include "BinaryTree.h"
#include "mock_Print.h"
#include "mock_Stack.h"
#include "Traversal.h"

void setUp(void){}

void tearDown(void){}

/*
 *			6
 *		   /  \
 *		  -    -
 *
 */
void test_binary_tree_with_1_node(void){
	Node root = {NULL, NULL, 6};
	Stack stack;
	printf("Starts test_binary_tree_with_1_node\n");
	stackNew_ExpectAndReturn(&stack);
	display_Expect(6);
	stackPop_ExpectAndReturn(&stack, NULL);
	stackDel_Expect(&stack);
	
	binaryTreeTraverseInOrder(&root);
}

/*
 *			10
 *		   /  \
 *		  5    -
 *
 */
 
void test_binary_tree_with_2_node_parent_and_left_child(void){
	Node leftChild = {NULL, NULL, 5};
	Node root = {&leftChild, NULL, 10};
	Stack stack;
	
	printf("Starts test_binary_tree_with_2_nodes_parent_and_left_child\n");
	stackNew_ExpectAndReturn(&stack);
	stackPush_Expect(&stack, &root);
	display_Expect(5);
	stackPop_ExpectAndReturn(&stack, &root);
	display_Expect(10);
	stackPop_ExpectAndReturn(&stack, NULL);
	stackDel_Expect(&stack);
	
	binaryTreeTraverseInOrder(&root);
}


/*
 *			10
 *		   /  \
 *		  5    -
 *       / \
 *      1   -
 */
void test_binary_tree_with_3_node_parent_and_left_child_and_grand_child(void){
	Node leftGrandChild = {NULL, NULL, 1};
    Node leftChild = {&leftGrandChild, NULL, 5};
	Node root = {&leftChild, NULL, 10};
	Stack stack;
	
	printf("Starts test_binary_tree_with_3_nodes_parent_and_left_child_and_grand_child\n");
	stackNew_ExpectAndReturn(&stack);
	stackPush_Expect(&stack, &root);
    stackPush_Expect(&stack, &leftChild);
	display_Expect(1);
	stackPop_ExpectAndReturn(&stack, &leftChild);
	display_Expect(5);
    stackPop_ExpectAndReturn(&stack, &root);
    display_Expect(10);
	stackPop_ExpectAndReturn(&stack, NULL);
	stackDel_Expect(&stack);
	
	binaryTreeTraverseInOrder(&root);
}

/*
 *			4
 *		   /  \
 *		  -    8
 *
 */
void test_binary_tree_with_2_node_parent_and_right_child(void){
	Node rightChild = {NULL, NULL, 8};
	Node root = {NULL, &rightChild, 4};
	Stack stack;
	
	printf("Starts test_binary_tree_with_2_nodes_parent_and_right_child\n");
	stackNew_ExpectAndReturn(&stack);
    display_Expect(4);
	stackPush_Expect(&stack, &root);
	display_Expect(8);
    stackPop_ExpectAndReturn(&stack, &root);
	stackPop_ExpectAndReturn(&stack, NULL);
	stackDel_Expect(&stack);
	
	binaryTreeTraverseInOrder(&root);
}

/*
 *			12
 *		   /  \
 *		  6    20
 *
 */
void test_binary_tree_with_3_node_parent_and_left_child(void){
	Node leftChild = {NULL, NULL, 6};
	Node rightChild = {NULL, NULL, 20};
	Node root = {&leftChild, &rightChild, 12};
	Stack stack;
	
	printf("Starts test_binary_tree_with_3_nodes_parent_and_left_child_and_right_child\n");
	stackNew_ExpectAndReturn(&stack);
	stackPush_Expect(&stack, &root);
	display_Expect(6);
	stackPop_ExpectAndReturn(&stack, &root);
	display_Expect(12);
	stackPush_Expect(&stack, &root);
	display_Expect(20);
	stackPop_ExpectAndReturn(&stack, &root);
	stackPop_ExpectAndReturn(&stack, NULL);
	stackDel_Expect(&stack);
	
	binaryTreeTraverseInOrder(&root);
}

/*
 *			10
 *		   /  \
 *		  5    -
 *       / \
 *      1   6
 */
void test_binary_tree_with_3_node_parent_and_left_child_and_grand_childs(void){
	Node LRightGrandChild = {NULL, NULL, 6};
	Node leftGrandChild = {NULL, NULL, 1};
    Node leftChild = {&leftGrandChild, &LRightGrandChild, 5};
	Node root = {&leftChild, NULL, 10};
	Stack stack;
	
	printf("Starts test_binary_tree_with_3_nodes_parent_and_left_child_and_grand_childs\n");
	stackNew_ExpectAndReturn(&stack);
	stackPush_Expect(&stack, &root);
    stackPush_Expect(&stack, &leftChild);
	display_Expect(1);
	stackPop_ExpectAndReturn(&stack, &leftChild);
	display_Expect(5);
	stackPush_Expect(&stack, &leftChild);
	display_Expect(6);
    stackPop_ExpectAndReturn(&stack, &leftChild);
	stackPop_ExpectAndReturn(&stack, &root);
    display_Expect(10);
	stackPop_ExpectAndReturn(&stack, NULL);
	stackDel_Expect(&stack);
	
	binaryTreeTraverseInOrder(&root);
}

/*
 *			10
 *		   /  \
 *		  -    5    
 *            / \
 *           1   6
 */
void test_binary_tree_with_3_node_parent_and_right_child_and_grand_childs(void){
	Node LRightGrandChild = {NULL, NULL, 6};
	Node leftGrandChild = {NULL, NULL, 1};
    Node leftChild = {&leftGrandChild, &LRightGrandChild, 5};
	Node root = {NULL, &leftChild, 10};
	Stack stack;
	
	printf("Starts test_binary_tree_with_3_nodes_parent_and_right_child_and_grand_childs\n");
	stackNew_ExpectAndReturn(&stack);
	display_Expect(10);
	stackPush_Expect(&stack, &root);
    stackPush_Expect(&stack, &leftChild);
	display_Expect(1);
	stackPop_ExpectAndReturn(&stack, &leftChild);
	display_Expect(5);
	stackPush_Expect(&stack, &leftChild);
	display_Expect(6);
    stackPop_ExpectAndReturn(&stack, &leftChild);
	stackPop_ExpectAndReturn(&stack, &root);
	stackPop_ExpectAndReturn(&stack, NULL);
	stackDel_Expect(&stack);
	
	binaryTreeTraverseInOrder(&root);
}

/*
 *			10
 *		   /  \
 *	   	  5    9
 *      / \   / \
 *    1   6  8  12
 */
void test_binary_tree_with_3_node_parent_and_left_child_and_right_child_with_childs(void){
	Node rightGrandChild = {NULL,NULL,12};
	Node RLeftGrandChild = {NULL,NULL,8};
	Node rightChild = {&rightGrandChild,&RLeftGrandChild,9};
	Node LRightGrandChild = {NULL, NULL, 6};
	Node leftGrandChild = {NULL, NULL, 1};
    Node leftChild = {&leftGrandChild, &LRightGrandChild, 5};
	Node root = {&leftChild,&rightChild, 10};
	Stack stack;
	
	printf("Starts test_binary_tree_with_3_nodes_parent_and_left_child_and_right_child_with_childs\n");
	stackNew_ExpectAndReturn(&stack);
	stackPush_Expect(&stack, &root);
    stackPush_Expect(&stack, &leftChild);
	display_Expect(1);
	stackPop_ExpectAndReturn(&stack, &leftChild);
	display_Expect(5);
	stackPush_Expect(&stack, &leftChild);
	display_Expect(6);
    stackPop_ExpectAndReturn(&stack, &leftChild);
	stackPop_ExpectAndReturn(&stack, &root);
    display_Expect(10);
	stackPush_Expect(&stack, &root);
    stackPush_Expect(&stack, &rightChild);
	display_Expect(12);
	stackPop_ExpectAndReturn(&stack, &rightChild);
	display_Expect(9);
	stackPush_Expect(&stack, &rightChild);
	display_Expect(8);
    stackPop_ExpectAndReturn(&stack, &rightChild);
	stackPop_ExpectAndReturn(&stack, &root);
	stackPop_ExpectAndReturn(&stack, NULL);
	stackDel_Expect(&stack);
	
	binaryTreeTraverseInOrder(&root);
}


