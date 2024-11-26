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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0 ;
        ListNode returnListNode = new ListNode(0);
        ListNode returnHead = returnListNode;

        while (l1 != null || l2 != null || carry != 0){
            int value1 = (l1 != null) ? l1.val: 0;
            int value2 = (l2 != null) ? l2.val: 0;
            int sum = value1 + value2 + carry;
            int value = sum % 10;
            ListNode node = new ListNode(value);    
            returnHead.next = node;
            returnHead = node;
            carry = sum / 10;

            if(l1 != null) l1 = l1.next;
            if(l2 != null) l2 = l2.next;
        }

        return returnListNode.next;
    }
}
