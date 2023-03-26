/**
 * Theodore Preaus & Philip Clarke CMS-230
 *
 *
 * Example ArrayList implementation using C structs
 */

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 5

// Declare ArrayList struct
//
// It has three fields
//   int* array: a pointer to an array allocated by malloc
//   int size: the number of elements inserted into the list
//   int capacity: the length of the current array
typedef struct {
  int *array;
  int size;     // Number of inserted elements
  int capacity; // Size of allocated array
} ArrayList;

/**
 * Construct a new ArrayList and return
 * a pointer to it
 */
ArrayList *arrayListInit() {

  // Allocate a struct for the new list
  ArrayList *newList = malloc(sizeof(ArrayList));

  // Check the return from malloc
  if (newList == 0) {
    perror("arrayListInit");
  }

  // Initialize the struct's fields
  newList->array = malloc(INITIAL_CAPACITY * sizeof(int));
  newList->size = 0;
  newList->capacity = INITIAL_CAPACITY;

  // Return the pointer to the new list
  return newList;
}

// /**
//  * Return the size of an ArrayList
//  */
int arrayListSize(ArrayList *a) { return a->size; }

/**
 * Print the contents of an ArrayList
 */
void arrayListPrint(ArrayList *a) {
  printf("[");
  for (int i = 0; i < a->size; i++) {
    printf("%d", a->array[i]);
    if (i < a->size - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}

/**
 * Append a value to the end of the array list
 */
void arrayListAppend(ArrayList *a, int value) {

  // If the array is full, allocate a new array and
  // copy the elements over to it
  if (a->size == a->capacity) {
    // Allocate a new array that holds
    // 2 * a->capacity * sizeof(int) byte

    // Allocate a struct for the new list
    ArrayList *newList = malloc(2 * a->capacity * sizeof(int));

    // Check the return from malloc
    if (newList == 0) {
      perror("arrayListAppend");
    }

    // Initialize the struct's fields
    newList->array = malloc(2 * a->capacity * sizeof(int));

    // Copy the values from the old array to the new array
    // int size;
    // size = sizeof(a) / sizeof(int);
    // printf("%d", size);
    for (int i = 0; i < a->capacity; i++) {
      newList->array[i] = a->array[i];
    }

    // Free the old array
    free(a->array);
    a->capacity = 2 * a->capacity;

    // Set a->array to point to the new array
    a->array = newList->array;
  }
  a->array[a->size] = value;

  // Put the new value in the next position in a->array
  // Tip: if you're keeping track correctly, the next
  // free position is always a->array[a->size]

  // Increment a->size
  a->size = a->size + 1;
}

/**
 * Return the value at the given index position in list a
 */
int arrayListGet(ArrayList *a, int index) {
  return a->array[index];
  }

/**
 * Insert an element at a given position
 */
void arrayListInsert(ArrayList *a, int value, int index) {
  int size = a->capacity;
  if(index < 0 ||index > size) {
    printf("Invalid position! Please enter position between 1 to %d\n", size);
  }
  for(int i = size; i >= index; i--){
    a->array[i] = a->array[i-1];
  }
  
  a->array[index] = value;

}

/**
 * Remove and return the element at the given position
 */
int arrayListRemove(ArrayList *a, int index) {
  
  int size = a->capacity;
  if(index < 0 ||index > size) {
    printf("Invalid position! Please enter position between 1 to %d\n", size);
  }
  for(int i = index; i < size; i++){
    a->array[i] = a->array[i+1];
    }
  a->capacity = a->capacity - 1;
  return a->array[index];
}

int main(void) {
  ArrayList *a = arrayListInit();

  // Test 1: print the size of a list
  // Prints 0
  printf("%d\n", arrayListSize(a));

  // Test 2: append a few values and print
  // Prints [1, 2, 3]
  arrayListAppend(a, 1);
  arrayListAppend(a, 2);
  arrayListAppend(a, 3);
  arrayListPrint(a);

  // Test 3: append more values
  // Requires reallocating and copying the backing array
  // Prints [1, 2, 3, ..., 48, 49, 50]
  for (int i = 4; i <= 50; i++) {
    arrayListAppend(a, i);
  }
  arrayListPrint(a);

  // // Test 4: verify that size has increased
  // // prints 50
  printf("%d\n", arrayListSize(a));

  // // Test 5: get values
  // // Prints 1, 50, and 26
  printf("%d\n", arrayListGet(a, 0));
  printf("%d\n", arrayListGet(a, arrayListSize(a) - 1));
  printf("%d\n", arrayListGet(a, arrayListSize(a) / 2));

  // Test 6: write your own test for arrayListInsert
  arrayListInsert(a, 69696969, 15);
  arrayListPrint(a);


  // Test 7: write your own test for arrayListRemove
  arrayListRemove(a, 15);
  arrayListPrint(a);
  return 0;
}