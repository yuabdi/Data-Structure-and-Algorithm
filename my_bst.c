// Include our header file for our my_bst.c
#include "my_bst.h"

// Include any other libraries needed
#include <stdio.h>
#include <stdlib.h>

// Creates a BST
// Returns a pointer to a newly created BST.
// The BST should be initialized with data on the heap.
// The BST fields should also be initialized to default values(i.e. size=0).
bst_t* bst_create(){
    // Modify the body of this function as needed.
    bst_t* myBST = (bst_t*)malloc(sizeof(bst_t));
    if(myBST == NULL){
      return NULL;
    }
    
    myBST->root= NULL; 
    
    myBST->size = 0;
    return myBST;
}

// BST Empty
// Check if the BST is empty
// Returns 1 if true (The BST is completely empty)
// Returns 0 if false (the BST has at least one element)
int bst_empty(bst_t* t){
   if(t->root == NULL && t->size == 0){
     return 1;
   }
    return 0;
}

bstnode_t* newNode(item) {
	bstnode_t* new_node = (bstnode_t*)malloc(sizeof(bstnode_t));

	new_node->data = item;
	new_node->leftChild = NULL;
	new_node->rightChild = NULL;

	return new_node;
}

int insert_node(bstnode_t* root_node, int item) {

	// left side
	if (root_node->data >= item) {
		// base case
		if (root_node->leftChild == NULL)
			root_node->leftChild = newNode(item);
		// recursion
		else 
			insert_node(root_node->leftChild, item);
		return 1; //pass
	} else {
	// right side
		//base case
		if (root_node->rightChild == NULL)
			root_node->rightChild = newNode(item);
		//recursion	
		else 
			insert_node(root_node->rightChild, item);
		return 1; //pass
	}
}

// Adds a new node containng item to the BST
// The item is added in the correct position in the BST.
//  - If the data is less than or equal to the current node we traverse left
//  - otherwise we traverse right.
// The bst_function returns '1' upon success
//  - bst_add should increment the 'size' of our BST.
// Returns a -1 if the operation fails.
//      (i.e. the memory allocation for a new node failed).
// Your implementation should should run in O(log(n)) time.
//  - A recursive imlementation is suggested.
int bst_add(bst_t* t, int item) {

	if (t == NULL)
		return -1;

	if (bst_empty(t) == 1) {
		t->root = newNode(item);
		t->size++;
		return 1;
	}

	bstnode_t* root_node = t->root;

	if (insert_node(root_node, item) == 1) {

		t->size++;
		return 1;
	}

	return -1;
}

void printBST(bstnode_t* root_node, int order) {

	// base case
	if (root_node == NULL)
		return;
	// recursion
	if (order == 0) { //ascending order
		printBST(root_node->leftChild, order);
		printf("%d ", root_node->data);
		printBST(root_node->rightChild, order);

	} else { // descending order
		printBST(root_node->rightChild, order);
		printf("%d ", root_node->data);
		printBST(root_node->leftChild, order);

	}

}

// Prints the tree in ascending order if order = 0, otherwise prints in descending order.
// For NULL tree -- print "(NULL)".
// It should run in O(n) time.
void bst_print(bst_t *t, int order){
	if (NULL == t) {
		printf("(NULL)");
	} else {
		bstnode_t* root_node = t->root;

		// ascending order
		if (order == 0)
			printf("Ascending Order:\n");
		// descending order
		else 
			printf("Descending Order:\n");

		printBST(root_node, order);

	}	
}

int sumBST(bstnode_t* root_node) {
	
	// base case
	if (root_node == NULL)
		return 0;
	// recursion
	return root_node->data + sumBST(root_node->leftChild) + sumBST(root_node->rightChild);
	// add: current data + left data + right data
}

// Returns the sum of all the nodes in the bst. 
// exits the program for a NULL tree. 
// It should run in O(n) time.
int bst_sum(bst_t *t){
	if (t == NULL)
		exit(0);

	bstnode_t* root_node = t->root;

	return sumBST(root_node); 
}

int find_node(bstnode_t* root_node, int value) {

	if (root_node == NULL)
		return 0;

	// base case
	if (root_node->data == value)
		return 1;
	// find left BST
	else if (root_node->data > value)
		return find_node(root_node->leftChild, value);
	// find right BST
	else if (root_node->data < value)
		return find_node(root_node->rightChild, value);

	return 0; // cannot find node
}

// Returns 1 if value is found in the tree, 0 otherwise. 
// For NULL tree it exists the program. 
// It should run in O(log(n)) time.
int bst_find(bst_t * t, int value){

	if (t == NULL) 
		exit(0);

	if (t->root->data == value)
		return 1;

	bstnode_t* root_node = t->root;

	if (find_node(root_node, value) == 1)
		return 1;

	return 0;  
}

// Returns the size of the BST
// A BST that is NULL exits the program.
// (i.e. A NULL BST cannot return the size)
unsigned int bst_size(bst_t* t){
	if (t == NULL)
		exit(0);
    
	return t->size;
}

void freeBST(bstnode_t* root_node) {

	// base case
	if (root_node == NULL)
		return;

	// recursion
	freeBST(root_node->leftChild);
	freeBST(root_node->rightChild);
	free(root_node);
}

// Free BST
// Removes a BST and ALL of its elements from memory.
// This should be called before the proram terminates.
void bst_free(bst_t* t){
	
	if (t == NULL)
		return;

	bstnode_t* root_node = t->root;

	freeBST(root_node);
	free(t);

}

