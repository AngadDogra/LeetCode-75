#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val ;
    struct TreeNode* left ;
    struct TreeNode* right ;
} ;

struct QueueNode {
    struct TreeNode* node ;
    struct QueueNode* next ;
};

// write a function to create a new tree node.
// returns the address of the created node.
struct TreeNode* createTreeNode(int val)
{
    struct TreeNode* newNode = malloc (sizeof(struct TreeNode)) ;
    newNode -> val = val ;
    newNode -> left = NULL ;
    newNode -> right = NULL ;

    return newNode ;
}

// write a function to create a new queue node
// returns address of created node
struct QueueNode* createQueueNode(struct TreeNode* node)
{
    struct QueueNode* newNode = malloc (sizeof(struct QueueNode)) ;
    newNode -> node = node ;
    newNode -> next = NULL ;

    return newNode ;
}

// write a function to enqueue a tree node
// enqueue needs a front and back ?

int main()
{

}