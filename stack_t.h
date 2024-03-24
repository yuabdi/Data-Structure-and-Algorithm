//Yusuf Abdi

#ifndef MYSTACK_H
#define MYSTACK_H


// Stores the maximum 'depth' of our stack.
// Our implementation enforces a maximum depth of our stack.
// (i.e. capacity cannot exceed MAX_DEPTH for any stack)

# define MAX_DEPTH 32


// Create a node data structure to store data within
// our stack. In our case, we will stores 'integers'
typedef struct node {
	int data;
	struct node* next;
}node_t;


// Create a stack data structure
// Our stack holds a single pointer to a node, which
// is a linked list of nodes.

typedef struct stack {
	int count;		        // count keeps track of how many items
							// are in the stack.
	unsigned int capacity;	// Stores the maximum size of our stack
	node_t* head;		    // head points to a node on the top of our stack.
}stack_t;

// Creates a stack
// Returns a pointer to a newly created stack.
// The stack should be initialized with data on the heap.
// (Think about what the means in terms of memory allocation)
// The stacks fields should also be initialized to default values.
stack_t* create_stack(unsigned int capacity);


// Stack Empty
// Check if the stack is empty
// Returns 1 if true (The stack is completely empty)
// Returns 0 if false (the stack has at least one element enqueued)
int stack_empty(stack_t* s);


// Stack Full
// Check if the stack is full
// Returns 1 if true (The Stack is completely full, i.e. equal to capacity)
// Returns 0 if false (the Stack has more space available to enqueue items)
int stack_full(stack_t* s);


// Enqueue a new item
// i.e. push a new item into our data structure
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. if the Stack is full that is an error, but does not crash the program).
int stack_enqueue(stack_t* s, int item);


// Dequeue an item
// Returns the item at the front of the stack and
// removes an item from the stack.
// Removing from an empty stack should crash the program, call exit(1).
int stack_dequeue(stack_t* s);


// Stack Size
// Queries the current size of a stack
// A stack that has not been previously created will crash the program.
// (i.e. A NULL stack cannot return the size)
unsigned int stack_size(stack_t* s);


// Free stack
// Removes ALL of its elements from memory and the stack_t itself.
// (Note: This should be called before the program terminates.)
void free_stack(stack_t* s);

// Peek
// Return the top value of the stack (without removing it)
// Peak from an empty stack should crash the program, call exit(1).
int stack_peek(stack_t* s);

// Stack Equals
// Checks if two stacks are equal
// The capacity of stack can be not equal
int stack_equals(stack_t* s1, stack_t* s2);

#endif
