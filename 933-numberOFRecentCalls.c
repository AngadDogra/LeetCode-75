#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *times;
    int head;
    int tail;
    int size;
    int capacity;
} RecentCounter;

RecentCounter* recentCounterCreate() {
    RecentCounter* obj = (RecentCounter*)malloc(sizeof(RecentCounter));
    obj->capacity = 10000; // Initialize with a large capacity
    obj->times = (int*)malloc(sizeof(int) * obj->capacity);
    obj->head = 0;
    obj->tail = 0;
    obj->size = 0;
    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {
    obj->times[obj->tail] = t;
    obj->tail = (obj->tail + 1) % obj->capacity;
    obj->size++;

    // Remove elements outside the 3000 ms window
    while (obj->times[obj->head] < t - 3000) {
        obj->head = (obj->head + 1) % obj->capacity;
        obj->size--;
    }

    return obj->size;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj->times);
    free(obj);
}

int main() {
    RecentCounter* recentCounter = recentCounterCreate();
    printf("%d\n", recentCounterPing(recentCounter, 1));   // Output: 1
    printf("%d\n", recentCounterPing(recentCounter, 100)); // Output: 2
    printf("%d\n", recentCounterPing(recentCounter, 3001));// Output: 3
    printf("%d\n", recentCounterPing(recentCounter, 3002));// Output: 3
    recentCounterFree(recentCounter);
    return 0;
}
