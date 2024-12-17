/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode trav = head;
        int size = 0;
        while (trav != null){
            trav = trav.next;
            size++;
        }
        int middle = (size / 2) + 1;
        ListNode returnNode = head;
        for (int i = 1; i < middle; i++){
            returnNode = returnNode.next;
        }
        return returnNode;
    }
}
