/*
 *Yusuf Abdi
 *  */

#include "hashmap_t.h"

#include <stdio.h>  // For IO operations, print keys only

// Simple hash function that will put a key into a bucket
// You should not modify this
int stringHash(char* myKey, int numberOfBuckets) {
    return strlen(myKey) % numberOfBuckets;
}

// Creates a new hashmap
// Allocates memory for a new hashmap.
// Initializes the capacity(i.e. number of buckets)
hashmap_t* hashmap_create(unsigned int _buckets) {
    // Allocate memory for our hashmap
    hashmap_t* map = (hashmap_t*)malloc(sizeof(hashmap_t));

    // Set the number of buckets
    map->buckets = _buckets;

    // Initialize our array of lists for each bucket
    map->arrayOfLists = (node_t**)malloc(sizeof(node_t*) * _buckets);
    
    // Iterate through all of our buckets and set them to NULL
    int i;
    for ( i = 0; i < _buckets; i++) {
        map->arrayOfLists[i] = NULL;
    }
    // Setup our hashFunction to point to our
    // stringHash function.
    map->hashFunction = stringHash;

    // Return the new map that we have created
    return map;
}

// Frees a hashmap
// Responsibility to free a hashmap that has been previously allocated.
// Must also free all of the chains in the hashmap
// This function should run in O(n) time
void hashmap_delete(hashmap_t* _hashmap) {

    int i;

    if (_hashmap != NULL) {
        for (i = 0; i < _hashmap->buckets; i++) {

            node_t* current = _hashmap->arrayOfLists[i];
            node_t* temp;

            //iterate the linked list and delete item
            while (current != NULL) {
                temp = current;
                current = current->next;

                free(temp->kv->key);
                free(temp->kv->value);
                free(temp->kv); //delete data of node
                free(temp);     //delete node
            }
        }

        //free table
        free(_hashmap->arrayOfLists);
        free(_hashmap);
    }
}

// Returns a boolean value if a key has been put into
// the hashmap
//  - Returns a '1' if a key exists already
//  - Returns a '0' if the key does not exist
//  - Returns a '-9999' if the hashmap is NULL
// The algorithm is:
//  - Call the _hashmap's hash function on the key
//  - Search that bucket to see if the key exists.
// This function should run in average-case constant time
int hashmap_hasKey(hashmap_t* _hashmap, char* key) {

    if (_hashmap == NULL) {
        return -9999;
    }

    //Call the _hashmap's hash function on the key
    unsigned int bucket = _hashmap->hashFunction(key, _hashmap->buckets);

    //find in the bucket
    node_t* current = _hashmap->arrayOfLists[bucket];

    //iterate the linked list and find item
    while (current != NULL) {

        if (strcmp(current->kv->key, key) == 0){
            return 1;
        }

        current = current->next;
    }

    return 0;//not found
}

// Insert a new key/value pair into a hashmap
// The algorithm is:
//  - If a key already exists, do not add it--return
//  - Call the _hashmap's hash function on the key
//  - Store the key/value pair at the end of the buckets chain
//      - You should malloc the key/value in this function
// This function should run in average-case constant time
void hashmap_insert(hashmap_t* _hashmap, char* key, char* value) {
    // Perhaps logic on handling if the key already exists
     // and just return...
     // and more error handling if the hashmap is NULL.
    if (_hashmap == NULL) {
        return;
    }

    //check key exists
    if (hashmap_hasKey(_hashmap, key) == 1) {
        return;
    }

    pair_t* newpair = (pair_t*)malloc(sizeof(pair_t));
    newpair->key = (char*)malloc(strlen(key) * sizeof(char) + 1);
    newpair->value = (char*)malloc(strlen(value) * sizeof(char) + 1);

    // Copy the string s
    strcpy(newpair->key, key);
    strcpy(newpair->value, value);

    // Create our new node
    node_t* newnode = (node_t*)malloc(sizeof(node_t));
    newnode->next = NULL;
    newnode->kv = newpair;

    // Now figure out where to put this key/value pair in
    // our hashmap
    unsigned int bucket = _hashmap->hashFunction(key, _hashmap->buckets);

    // Create an iterator and set it to the bucket that we want
    // Then we'll iterate through this bucket to the end of the chain
    // (which remember, is just the end of the linked list)
    node_t* iter = _hashmap->arrayOfLists[bucket];
    if (iter == NULL) {
        // If there is nothing in our bucket, then make this
        // the first node
        _hashmap->arrayOfLists[bucket] = newnode;
    }
    else {

        // iterate to the end of the array and attach our node
        while (iter->next != NULL) {
            iter = iter->next;
        }

        // new node is the next node of tail
        iter->next = newnode;
    }
}

// Return a value from a key 
// Returns NULL if the _hashmap is NULL
// Returns NULL if the key is not found
// The algorithm is:
//  - If the key does not exist, then--return NULL if not found.
//  - Call the _hashmap's hash function on the key
//  - Search the _hashmap's bucket for the key and return the value
// This function should run in average-case constant time
char* hashmap_getValue(hashmap_t* _hashmap, char* key) {
    //Returns NULL if the _hashmap is NULL
    if (_hashmap == NULL) {
        return NULL;
    }

    //Call the _hashmap's hash function on the key
    unsigned int bucket = _hashmap->hashFunction(key, _hashmap->buckets);

    //find in the bucket
    node_t* current = _hashmap->arrayOfLists[bucket];

    //iterate the linked list and find item
    while (current != NULL) {

        if (strcmp(current->kv->key, key) == 0){
            return current->kv->value;
        }

        current = current->next;
    }

    return NULL;//Returns NULL if the key is not found
}

// Remove a key from a hashmap
// The algorithm is:
//  - Determine if the key exists--return if it does not.
//  - Call the _hashmap's hash function on the key
//  - Search the _hashmap's bucket for the key and then remove it
// This function should run in average-case constant time
void hashmap_removeKey(hashmap_t* _hashmap, char* key) {
    //if the _hashmap is NULL
    if (_hashmap == NULL) {
        return;
    }

    //Call the _hashmap's hash function on the key
    unsigned int bucket = _hashmap->hashFunction(key, _hashmap->buckets);

    //find in the bucket
    node_t* current = _hashmap->arrayOfLists[bucket];
    node_t* previous = NULL; //previous node of current

    //iterate the linked list and find item
    while (current != NULL) {

        if (strcmp(current->kv->key, key) == 0) {
            break;
        }

        previous = current;
        current = current->next;
    }

    if (current != NULL) { //key exists

        if (previous == NULL) {//delete head node
            _hashmap->arrayOfLists[bucket] = current->next;
        }
        else {
            previous->next = current->next;
        }

        free(current->kv->key);
        free(current->kv->value);
        free(current->kv);         //free data of node
        free(current);             //free node
    }
}

// Update a key with a new Value
// The algorithm is:
//  - Returns immediately if the key does not exist
//  - Call the _hashmap's hash function on the key
//  - Updates the value of the key to the new value
// This function should run in average-case constant time
void hashmap_update(hashmap_t* _hashmap, char* key, char* newValue) {
    if (_hashmap == NULL) {
        return;
    }

    //check key not exists
    if (hashmap_hasKey(_hashmap, key) == 0) {
        return;
    }

    //Call the _hashmap's hash function on the key
    unsigned int bucket = _hashmap->hashFunction(key, _hashmap->buckets);

    //find in the bucket
    node_t* current = _hashmap->arrayOfLists[bucket];

    //iterate the linked list and find item
    while (current != NULL) {

        if (strcmp(current->kv->key, key) == 0) {
            //free current memory for value
            free(current->kv->value);
            //allocate for new value
            current->kv->value = (char*)malloc(strlen(newValue) * sizeof(char) + 1);
            //copy string
            strcpy(current->kv->value, newValue);
            break;
        }

        current = current->next;
    }
    
}

// Prints all of the keys in a hashmap
// The algorithm is:
//  - Iterate through every bucket and print out the keys
// This function should run in O(n) time
void hashmap_printKeys(hashmap_t* _hashmap) {

    int i;

    // Iterate through all of our buckets and print out the keys
    for (i = 0; i < _hashmap->buckets; i++) {
        
        node_t* current = _hashmap->arrayOfLists[i];

        //iterate the linked list and print keys
        while (current != NULL) {

            printf("%s\n", current->kv->key);

            current = current->next;
        }        
    }
}
