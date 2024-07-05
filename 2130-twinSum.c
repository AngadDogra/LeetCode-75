/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val ;
    struct ListNode* next ;
} ;

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    struct ListNode* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int pairSum(struct ListNode* head) {
    if (head == NULL) return 0;

    // Step 1: Find the middle of the linked list
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half of the linked list
    struct ListNode* secondHalf = reverseList(slow);

    // Step 3: Calculate the maximum twin sum
    int maxTwinSum = 0;
    struct ListNode* firstHalf = head;
    while (secondHalf != NULL) {
        int twinSum = firstHalf->val + secondHalf->val;
        if (twinSum > maxTwinSum) {
            maxTwinSum = twinSum;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return maxTwinSum;
}

int main () 
{

}