//Yusuf Abdi


#include "queue_t.h"
#include <stdlib.h> // malloc/free

// Create a queue
queue_t* create_queue(unsigned int _capacity){

    queue_t* q = (queue_t*)malloc(sizeof(queue_t));
    

    q->front = -1;
    q->back = 0;
    q->size = 0;
    q->capacity = _capacity;
    q-> data = (int*)malloc(sizeof(int)*_capacity);

    return q;
}



// Queue Empty
int queue_empty(queue_t* q){
        if(q->size == 0){
        return 1;
        }
        else{
               return 0;
        }
	
}

// Queue Full
int queue_full(queue_t* q){
        if(q->size == q-> capacity){
               return 1;
        }
        else{
               return 0;
        }
	
}

// Enqueue a new item
int queue_enqueue(queue_t* q, int item){

        if (q-> size < q->capacity){
                 // converting the string expression to a number and return its a double
                 q-> front = (q->front +1)% q ->capacity;//increse by one
                 q-> data [q-> front] = item;
                 
                 q->size += 1;
                 return 0;
        }
        else{

                 return -1;
        }

		
}

// Dequeue an item
int queue_dequeue(queue_t *q){
       
        if (q-> size > 0){
                 // converting the string expression to a number and return its a double
                 int val = q-> data[q-> back];
             
                 q-> back = (q -> back +1) %q ->capacity;// increase by one

                 q->size -= 1;
                 return val;
         }else{
                 exit(1);
         }                                                                                                                }
           
}


// Queue Size
unsigned int queue_size(queue_t* q){
        
        return q->size;
}


// Free queue
void free_queue(queue_t* q){

        free(q-> data);
        free(q)
}
