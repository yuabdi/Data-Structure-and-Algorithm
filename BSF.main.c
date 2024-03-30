// Compile this assignment with: gcc main.c -o main
//
// This is a great assignment to practice debugging.
// First compile with debugging symbols
// Compile with: clang -g main.c my_bst.c -o main
// Run with: gdb ./main --tui
// Then type 'start'
// Then type 'next' or 'n' and enter
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_bst.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.

// You may add as many unit tests as you like here
// A few have been provided for your convenience.
// We will use our own test suite (i.e. replacing this file)
// in order to test your implementation from my_bst.

// Testing allocation
int unitTest1(){
    int result;
    bst_t * testBST = bst_create();
    if (testBST!=NULL){
        result = 1;
    }else{
        result = 0;
    }
    bst_free(testBST);
    return result;    
}

// Add and find a node
int unitTest2(){
    int result = 0;
    bst_t * testBST = bst_create();
    bst_add(testBST,78);
    bst_add(testBST,88); //add on the right
    bst_add(testBST,28); //add on the left
    result = bst_find(testBST,78);
    bst_free(testBST);    
    return result;
}

// Sums the nodes in a BST
int unitTest3(){
    int result;
    bst_t * testBST = bst_create();
    bst_add(testBST, 5);
    result = bst_sum(testBST);
    bst_free(testBST);   

    if(result==5){ 
        return 1;
    }
    return 0;
}

// print BST
int unitTest4() {
	int result = 1; // 1: pass
	bst_t* testBST = bst_create();
    	bst_add(testBST,78);
    	bst_add(testBST,158);
    	bst_add(testBST,60);
    	bst_add(testBST,51);
    	bst_add(testBST,90);

	bst_print(testBST, 0); //ascending
	printf("\n");
	bst_print(testBST, 1); //descending
	printf("\n");

    	bst_free(testBST);   

	return result;
}

// test for BST sum
int unitTest5() {
	int result = 0; // 0: fail
	bst_t* testBST = bst_create();

        bst_add(testBST,1);
        bst_add(testBST,2);
        bst_add(testBST,3);
        bst_add(testBST,4);
        bst_add(testBST,5);

        result = bst_sum(testBST);

        if (result == 15)
                result = 1;

        bst_free(testBST);

        return result;

}

// test for BST size
int unitTest6() {
	int result = 0;

	bst_t* testBST = bst_create();

        bst_add(testBST,1);
        bst_add(testBST,2);
        bst_add(testBST,3);
        bst_add(testBST,4);
        bst_add(testBST,5);
        bst_add(testBST,6);
        bst_add(testBST,7);
        bst_add(testBST,8);
        bst_add(testBST,9);
        bst_add(testBST,10);


	if (10  == bst_size(testBST))
		result = 1;


	bst_free(testBST);
	
	return result;
}

// TODO: Add more tests here at your discretion
int (*unitTests[])(int)={
    unitTest1,
    unitTest2,
    unitTest3,
    unitTest4,
    unitTest5,
    unitTest6,
    NULL
};

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){
	
	unsigned int testsPassed = 0;
    // List of Unit Tests to test your data structure
    int counter =0;
    while(unitTests[counter]!=NULL){
		printf("========unitTest %d========\n",counter);
		if(1==unitTests[counter](1)){
			printf("passed test\n");
			testsPassed++;	
		}else{
			printf("failed test, missing functionality, or incorrect test\n");
		}
        counter++;
    }

    printf("%d of %d tests passed\n",testsPassed,counter);

    return 0;
}
