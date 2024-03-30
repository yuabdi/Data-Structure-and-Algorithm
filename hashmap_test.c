// Note: This is not an exhaustive test suite, but gives you the idea
//       of some tests you might want to create.
//       Adding more tests and slowly making them more and more complicated
//       as you develop your library is recommended.
//
// Compile this assignment with: gcc -g -Wall hashmap_test.c hashmap_t.c -o prog
//
// Run with: ./prog
//
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.

#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "hashmap_t.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.


// A sample collection of tests for your program
// You can add as many unit tests as you like
// We will be adding our own to test your program.


// Tests creation and deletion of the hashmap
// Ideally does not cause any segfaults, and this
// is considered passing.
int unitTest1(int status){
    int passed = 0;
    hashmap_t* test = hashmap_create(12);    
    hashmap_delete(test);
    passed = 1;
    return passed;
}

// Tests has_key for a missing key
int unitTest2(int status){
    int passed = 0;
    hashmap_t* test = hashmap_create(12);
    
    if(hashmap_hasKey(test, "cow")==0){
      passed = 1;
    }
    
    hashmap_delete(test);
    return passed;
}


// Tests insert and has_key
int unitTest3(int status){
    int passed = 0;
    hashmap_t* test = hashmap_create(12);
    hashmap_insert(test,"cow","A common farm animal.");
    
    if(hashmap_hasKey(test, "cow")==1){
      passed = 1;
    }
    
    hashmap_delete(test);
    return passed;
}

// Tests insert and has_key and remove key
int unitTest4(int status){
    int passed = 0;
    hashmap_t* test = hashmap_create(12);
    hashmap_insert(test,"cow","A common farm animal.");
    hashmap_removeKey(test, "cow");
    
    if(hashmap_hasKey(test, "cow")==0){
      passed = 1;
    }
    
    hashmap_delete(test);

    return passed;
}

// Tests update_key
int unitTest5(int status){
    int passed = 0;
    hashmap_t* test = hashmap_create(12);
    hashmap_insert(test,"cow","A common farm animal.");
    hashmap_update(test, "cow", "A common farm animal in Ohio.");
    
    if(hashmap_hasKey(test, "cow")==1){
      passed = 1;
    }
    
    hashmap_delete(test);
    return passed;
}

int unitTest6(int status){
    // Create our hashmap
    hashmap_t* myHashmap = hashmap_create(5); 
    // Insert a first key/value pair
    hashmap_insert(myHashmap,"pig", "a farm animal");
    // Does hashmap contain key?
    printf("\tpig was added should be 1: %d\n",hashmap_hasKey(myHashmap,"pig"));
    // Print out the keys
    hashmap_printKeys(myHashmap);
    // Retrieve pig's value 
    printf("\tpig's value is %s\n",hashmap_getValue(myHashmap, "pig"));
    hashmap_update(myHashmap,"pig","a really cool farm animal");    
    printf("\tpig's value is updated to: %s\n",hashmap_getValue(myHashmap, "pig"));
    // Remove a key
    hashmap_removeKey(myHashmap,"pig");
    // Does hashmap contain key?
    printf("\tpig was removed should be 0: %d\n",hashmap_hasKey(myHashmap,"pig"));
    // Finally terminate our hashmap
    hashmap_delete(myHashmap);

    printf("\tNote--This test needs to be manually inspected\n");
    return 1;
}

int unitTest7(int status){
    // Create our hashmap
    hashmap_t* myHashmap = hashmap_create(5); 
    // Insert a first key/value pair
    hashmap_insert(myHashmap,"pig", "a farm animal");
    hashmap_insert(myHashmap,"bat", "a farm creature");
    hashmap_insert(myHashmap,"cat", "a funny farm animal");
    hashmap_insert(myHashmap,"dog", "a fun farm animal");
    hashmap_insert(myHashmap,"bear", "a wild farm animal");
    hashmap_insert(myHashmap,"ox", "another farm animal");
    hashmap_insert(myHashmap,"cow", "a favorite farm animal");
    hashmap_insert(myHashmap,"hippo", "a farm animal?");
    hashmap_insert(myHashmap,"elephant", "not a farm animal");
    hashmap_insert(myHashmap,"human", "an animal that farms");
    // Print the keys
    hashmap_printKeys(myHashmap);
    // Finally terminate our hashmap
    hashmap_delete(myHashmap);

    printf("\tNote--This test needs to be manually inspected\n");


    return 1;
}

//test duplicate key
int unitTest8(int status) {

    // Create our hashmap
    hashmap_t* myHashmap = hashmap_create(5);

    hashmap_insert(myHashmap, "a", "rose");

    // Does hashmap contain key?
    printf("\ta was added should be 1: %d\n", hashmap_hasKey(myHashmap, "a"));
    // Retrieve pig's value 
    printf("\ta's value is %s\n", hashmap_getValue(myHashmap, "a"));
    
    // Print the keys
    hashmap_printKeys(myHashmap);

    printf("add (a, sun), duplicate\n");

    hashmap_insert(myHashmap, "a", "sun");

    // Does hashmap contain key?
    printf("\ta was added should be 1: %d\n", hashmap_hasKey(myHashmap, "a"));

    // Retrieve pig's value 
    printf("\ta's value is %s\n", hashmap_getValue(myHashmap, "a"));

    // Print the keys
    hashmap_printKeys(myHashmap);

    printf("\tNote--This test needs to be manually inspected\n");

    hashmap_delete(myHashmap);

    return 1;
}

int unitTest9(int status) {
    // Create our hashmap
    hashmap_t* myHashmap = hashmap_create(1);

    hashmap_insert(myHashmap, "one", "1");
    hashmap_insert(myHashmap, "two", "2");
    hashmap_insert(myHashmap, "three", "3");
    hashmap_insert(myHashmap, "four", "4");

    if (hashmap_getValue(myHashmap, "one") == NULL ||
        strcmp(hashmap_getValue(myHashmap, "one"), "1") != 0)
    {
        hashmap_delete(myHashmap);
        return 0;
    }

    if (hashmap_getValue(myHashmap, "two") == NULL ||
        strcmp(hashmap_getValue(myHashmap, "two"), "2") != 0)
    {
        hashmap_delete(myHashmap);
        return 0;
    }

    if (hashmap_getValue(myHashmap, "three") == NULL ||
        strcmp(hashmap_getValue(myHashmap, "three"), "3") != 0)
    {
        hashmap_delete(myHashmap);
        return 0;
    }

    if (hashmap_getValue(myHashmap, "four") == NULL ||
        strcmp(hashmap_getValue(myHashmap, "four"), "4") != 0)
    {

        hashmap_delete(myHashmap);
        return 0;
    }

    hashmap_delete(myHashmap);

    return 1;
}

//test add, update, remove
int unitTest10(int status) {

    //test null
    if (hashmap_getValue(NULL, "abc") != NULL)
    {
        return 0;
    }

    // Create our hashmap
    hashmap_t* myHashmap = hashmap_create(5);

    hashmap_insert(myHashmap, "one", "1");
    hashmap_insert(myHashmap, "two", "2");

    if (hashmap_getValue(myHashmap, "one") == NULL ||
        strcmp(hashmap_getValue(myHashmap, "one"), "1") != 0)
    {
        hashmap_delete(myHashmap);
        return 0;
    }

    //update
    hashmap_update(myHashmap, "one", "new value for one");

    if (hashmap_getValue(myHashmap, "one") == NULL ||
        strcmp(hashmap_getValue(myHashmap, "one"), "new value for one") != 0)
    {
        hashmap_delete(myHashmap);
        return 0;
    }

    //delete
    hashmap_removeKey(myHashmap, "one");

    if (hashmap_hasKey(myHashmap, "one") == 1)
    {
        hashmap_delete(myHashmap);
        return 0;
    }

    if (hashmap_getValue(myHashmap, "one") != NULL)
    {
        hashmap_delete(myHashmap);
        return 0;
    }

    hashmap_delete(myHashmap);

    return 1;
}



// Add more tests here at your discretion
int (*unitTests[])(int)={
    unitTest1,
    unitTest2,
    unitTest3,
    unitTest4,
    unitTest5,
    unitTest6,
    unitTest7,
    unitTest8,
    unitTest9,
    unitTest10,
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
                                           // Added + 1 so printout corresponds
                                           // with the test number
    	printf("========unitTest %d========\n",counter+1);
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

