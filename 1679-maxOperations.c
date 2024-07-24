#include <stdio.h>
#include <stdlib.h>

// Define a hash map entry
typedef struct {
    int key;
    int value;
} HashMapEntry;

// Define a hash map
typedef struct {
    HashMapEntry* entries;
    int size;
    int capacity;
} HashMap;

// Function to create a hash map
HashMap* createHashMap(int capacity) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->entries = (HashMapEntry*)malloc(capacity * sizeof(HashMapEntry));
    map->size = 0;
    map->capacity = capacity;
    for (int i = 0; i < capacity; i++) {
        map->entries[i].key = 0;
        map->entries[i].value = 0;
    }
    return map;
}

// Hash function
int hash(int key, int capacity) {
    return abs(key) % capacity;
}

// Function to find an entry in the hash map
HashMapEntry* findEntry(HashMap* map, int key) {
    int index = hash(key, map->capacity);
    while (map->entries[index].key != 0 && map->entries[index].key != key) {
        index = (index + 1) % map->capacity;
    }
    return &map->entries[index];
}

// Function to insert a key-value pair into the hash map
void insert(HashMap* map, int key, int value) {
    HashMapEntry* entry = findEntry(map, key);
    if (entry->key == 0) {
        map->size++;
    }
    entry->key = key;
    entry->value = value;
}

// Function to get the value associated with a key
int get(HashMap* map, int key) {
    HashMapEntry* entry = findEntry(map, key);
    if (entry->key == 0) {
        return 0;
    }
    return entry->value;
}

// Function to increment the value associated with a key
void increment(HashMap* map, int key) {
    HashMapEntry* entry = findEntry(map, key);
    if (entry->key == 0) {
        map->size++;
    }
    entry->key = key;
    entry->value++;
}

// Function to decrement the value associated with a key
void decrement(HashMap* map, int key) {
    HashMapEntry* entry = findEntry(map, key);
    if (entry->key != 0) {
        entry->value--;
    }
}

// Function to free the hash map
void freeHashMap(HashMap* map) {
    free(map->entries);
    free(map);
}

int maxOperations(int* nums, int numsSize, int k) {
    HashMap* map = createHashMap(numsSize * 2); // Create a hash map with double capacity for better performance
    int maxPairs = 0;

    for (int i = 0; i < numsSize; i++) {
        int complement = k - nums[i];
        int count = get(map, complement);
        if (count > 0) {
            maxPairs++;
            decrement(map, complement);
        } else {
            increment(map, nums[i]);
        }
    }

    freeHashMap(map); // Free the hash map
    return maxPairs;
}

