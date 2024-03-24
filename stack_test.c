//Yusuf Abdi



#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

#include "stack_t.h"


// Tests the capacity of a stack
int unitTest1(int status) {
    int passed = 0;

    stack_t* test_s = create_stack(32);
    if (32 == test_s->capacity) {
        passed = 1;
    }

    free_stack(test_s);

    return passed;
}

// Enqueu several items into a stack and test the size
int unitTest2(int status) {
    int passed = 0;

    stack_t* test_s = create_stack(MAX_DEPTH);
    stack_enqueue(test_s, 1);
    stack_enqueue(test_s, 2);
    stack_enqueue(test_s, 3);
    stack_enqueue(test_s, 4);
    stack_enqueue(test_s, 5);
    stack_enqueue(test_s, 6);
    stack_enqueue(test_s, 7);
    stack_enqueue(test_s, 8);
    stack_enqueue(test_s, 9);
    stack_enqueue(test_s, 10);

    if (10 == stack_size(test_s)) {
        passed = 1;
    }

    free_stack(test_s);

    return passed;
}

// Tests enqueuing and fully dequeing a stack
int unitTest3(int status) {
    int passed = 0;

    stack_t* test_s = create_stack(32);
    int i = 0;
    for (i = 0; i < 32; i++) {
        stack_enqueue(test_s, 1);
    }
    for (i = 0; i < 32; i++) {
        stack_dequeue(test_s);
    }

    if (0 == stack_size(test_s)) {
        passed = 1;
    }

    free_stack(test_s);

    return passed;
}

// Tests enqueuing and fully dequeing a stack multiple times
int unitTest4(int status) {
    int passed = 0;

    stack_t* test_s = create_stack(32);
    int i = 0;
    for (i = 0; i < 32; i++) {
        stack_enqueue(test_s, 1);
    }
    for (i = 0; i < 32; i++) {
        stack_dequeue(test_s);
    }
    for (i = 0; i < 32; i++) {
        stack_enqueue(test_s, 1);
    }
    for (i = 0; i < 32; i++) {
        stack_dequeue(test_s);
    }
    if (0 == stack_size(test_s)) {
        passed = 1;
    }

    free_stack(test_s);

    return passed;
}

// Simple enqueu and deque stack test
// Also confirms that a stack is full
int unitTest5(int status) {
    int passed = 0;

    stack_t* test_s = create_stack(1);
    stack_enqueue(test_s, 1);
    if (1 == stack_full(test_s)) {
        passed = 1;
    }
    else {
        free_stack(test_s);
        return 0;
    }

    stack_dequeue(test_s);
    if (0 == stack_full(test_s)) {
        passed = 1;
    }
    else {
        passed = 0;
    }

    free_stack(test_s);

    return passed;
}

// enqueu and deque stack test
// Also confirms that a stack is full
int unitTest6(int status) {
    int passed = 0;
    int i;

    stack_t* test_s = create_stack(MAX_DEPTH);
    for (i = 0; i < MAX_DEPTH; i++)
    {
        stack_enqueue(test_s, i);
    }
    
    if (1 == stack_full(test_s)) {
        passed = 1;
    }
    else {
        free_stack(test_s);
        return 0;
    }

    for (i = 0; i < MAX_DEPTH; i++)
    {
        if (MAX_DEPTH - i - 1 == stack_dequeue(test_s)) {
            passed = 1;
        }
        else {
            passed = 0;
            break;
        }

        if (0 == stack_full(test_s)) {
            passed = 1;
        }
        else {
            passed = 0;
            break;
        }
    }


    free_stack(test_s);

    return passed;
}

// test peak and equals
int unitTest7(int status) {

    int i;
    int passed = 0;
    stack_t* test_s1;
    stack_t* test_s2;
    stack_t* test_s3;

    test_s1 = create_stack(MAX_DEPTH);
    test_s2 = create_stack(MAX_DEPTH);

    if (1 == stack_equals(test_s1, test_s2)) {
        passed = 1;
    }
    else {
        free_stack(test_s1);
        free_stack(test_s2);
        return 0;
    }

    for (i = 0; i < MAX_DEPTH; i++)
    {
        stack_enqueue(test_s1, i);
        stack_enqueue(test_s2, i);

        if (stack_peek(test_s1) == stack_peek(test_s2)) {
            passed = 1;
        }
        else {
            free_stack(test_s1);
            free_stack(test_s2);
            return 0;
        }

        if (1 == stack_equals(test_s1, test_s2)) {
            passed = 1;
        }
        else {
            free_stack(test_s1);
            free_stack(test_s2);
            return 0;
        }
    }

    if (1 == stack_equals(test_s1, test_s2)) {
        passed = 1;
    }
    else {
        free_stack(test_s1);
        free_stack(test_s2);
        return 0;
    }

    test_s3 = create_stack(1);
    stack_enqueue(test_s3, 2);

    if (0 == stack_equals(test_s1, test_s3)) {
        passed = 1;
    }
    else {
        free_stack(test_s1);
        free_stack(test_s2);
        free_stack(test_s3);
        return 0;
    }


    free_stack(test_s1);
    free_stack(test_s2);
    free_stack(test_s3);

    return passed;
}


// behavior of your data structure, as well as to 'stress test'
// your data structures.
int (*unitTests[])(int) = {
    unitTest1,
    unitTest2,
    unitTest3,
    unitTest4,
    unitTest5,
    unitTest6,
    unitTest7,
    NULL
};

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main() {
    unsigned int testsPassed = 0;
    // List of Unit Tests to test your data structure
    int counter = 0;
    while (unitTests[counter] != NULL) {
        printf("========unitTest %d========\n", counter);
        if (1 == unitTests[counter](1)) {
            printf("passed test\n");
            testsPassed++;
        }
        else {
            printf("failed test, missing functionality, or incorrect test\n");
        }
        counter++;
    }

    printf("%d of %d tests passed\n", testsPassed, counter);

    return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
