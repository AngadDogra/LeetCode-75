/*
 * Author: Angad Dogra
 * GNU License
 * */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct hashEntry {
    int key ;
    struct hashEntry * next ;       // to chain the collisions
} ;

unsigned int hash(int key, int tableSize) {
    return abs(key) % tableSize ;
}

struct hashEntry** createHashTable (int tableSize) {
    struct hashEntry** table = (struct hashEntry**) malloc (tableSize * sizeof(struct hashEntry*)) ;
    for (int i = 0 ; i < tableSize ; i++) {
        table[i] = NULL ;
    }
    return table ;   // returns address of the table
}

void insert (struct hashEntry** table, int key, int tableSize) {
    unsigned int index = hash (key, tableSize) ;
    // now check table at address index
    struct hashEntry* newNode = (struct hashEntry*) malloc (sizeof (struct hashEntry)) ;
    newNode -> key = key ;
    newNode -> next = table[index] ;
    table[index] = newNode ;
}

bool search (struct hashEntry** table, int key, int tableSize) {
    unsigned int index = hash(key, tableSize) ;
    struct hashEntry* node = table[index] ;
    while (node != NULL) {
        if (node -> key == key) {
            return true ;
        }
        node = node -> next ; // check the linked list 
    }
    return false ;
}

void freeHashTable (struct hashEntry** table, int tableSize) {
    for (int i = 0 ; i < tableSize ; i++) {
        struct hashEntry* node = table[i] ;    // points to the first
        while (node != NULL) {
            struct hashEntry* temp = node ;
            node = node -> next ;
            free (temp) ;
        }
    }
    free(table) ;
}

bool containsDuplicate (int* nums, int numsSize) {
    int tableSize = numsSize * 2 ;
    struct hashEntry** hashTable = createHashTable(tableSize) ;

    for (int i = 0 ; i < numsSize ; i++) {
        if (search(hashTable, nums[i], tableSize)){
            freeHashTable(hashTable, tableSize) ;
            return true ;
        }
        insert(hashTable, nums[i], tableSize) ;
    }

    freeHashTable(hashTable, tableSize) ;
    return false ;
}
