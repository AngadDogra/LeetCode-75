/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    ArrayList<Integer> list = new ArrayList<>();

    public  boolean isSorted(ArrayList<Integer> list) {
        // Traverse the list and compare each element with the next one
        for (int i = 0; i < list.size() - 1; i++) {
            if (list.get(i) >= list.get(i + 1)) {
                return false;  // Return false if the list is not sorted
            }
        }
        return true;  // If no issues, the list is sorted
    }

    public  ArrayList<Integer> helper(TreeNode root){
        if (root == null) return list;
        helper(root.left);
        list.add(root.val);
        helper(root.right);

        return list;
    }

    public boolean isValidBST(TreeNode root) {

        ArrayList<Integer> list = helper(root);

        return isSorted(list);        
    }
}
