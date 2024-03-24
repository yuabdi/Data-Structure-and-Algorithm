//Yusuf Abdi


#include <stdlib.h>  // Include for malloc/free and NULL

#include "stack_t.h" // Include our function declarations and data types


// Creates a stack
stack_t* create_stack(unsigned int capacity) {
	// allocate the memory for the stack
	stack_t* myStack = (stack_t*)malloc(sizeof(stack_t));
	myStack->count = 0;
	myStack->capacity = capacity;
	myStack->head = 0;

	return myStack;
}

// Stack Empty
int stack_empty(stack_t* s) {

	if (s->count == 0) {
		return 1;
	}
	return 0;
}
// Stack Full
int stack_full(stack_t* s) {

	if (s->count < (int)s->capacity) {
		return 0;
	}
	return 1;
}

// Enqueue a new item
int stack_enqueue(stack_t* s, int item) {

	node_t* new_node;

	if (s->count == s->capacity) {
		return -1;//full
	}

	//create new node and insert as head of linked list
	new_node = (node_t*)malloc(sizeof(node_t));
	new_node->data = item;
	new_node->next = s->head;

	s->head = new_node; //new node become the head of linked list
	s->count += 1;

	return 0;
}

// Dequeue an item
int stack_dequeue(stack_t* s) {

	node_t* temp;
	int data;

	if (s->count == 0) {
		exit(1);
	}

	data = s->head->data;//data at head node

	//head will point to next node, free the current head
	temp = s->head;
	s->head = s->head->next;
	s->count -= 1;

	free(temp);

	return data;
}

// Stack Size
unsigned int stack_size(stack_t* s) {
	return s->count;
}

// Free stack
void free_stack(stack_t* s) {

	node_t* iter = s->head; //pointer to iterate the node
	node_t* temp;

	//iterate the 
	while (iter != NULL) {

		temp = iter;
		iter = iter->next;

		free(temp);
	}

	free(s);
}

// Peek from stack

int stack_peek(stack_t* s) {

	if (s->count == 0) {
		exit(1);
	}

	return s->head->data;
}

// Checks if two stacks are equal
int stack_equals(stack_t* s1, stack_t* s2) {

	node_t* iter1;
	node_t* iter2;

	if(s1->count != s2->count){
		return 0;
	}

	//iterate two list and compare data
	iter1 = s1->head; //pointer to iterate the node
	iter2 = s2->head;

	//iterate two lists
	while (iter1 != NULL) {

		if (iter1->data != iter2->data) {
			return 0;
		}

		iter1 = iter1->next;
		iter2 = iter2->next;
	}

	return 1;
}
																																																																															
