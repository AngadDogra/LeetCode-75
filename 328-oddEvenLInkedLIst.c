#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val ; 
    struct ListNode* next ;
} ;

struct ListNode* oddEvenList(struct ListNode* head) {
    // base - head == null || head -> next == null
    // return head
    struct ListNode* odd = head ; 
    struct ListNode* even = head -> next ;
    struct ListNode* even_head = head -> next ;

    while (even != NULL && even_head != NULL) {
            
    } 
}

int main () {

}