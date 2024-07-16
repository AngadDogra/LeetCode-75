// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>


// // Helper function to perform pre-order traversal and collect leaf nodes.
// void collectLeaves(struct TreeNode* root, int* leafNodes, int* index) {
//     if (root == NULL) return;
    
//     if (root->left == NULL && root->right == NULL) {
//         leafNodes[*index] = root->val;
//         (*index)++;
//     }
    
//     collectLeaves(root->left, leafNodes, index);
//     collectLeaves(root->right, leafNodes, index);
// }

// // Function to check if two trees are leaf-similar.
// bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
//     int* leaves1 = (int*)malloc(100 * sizeof(int));
//     int* leaves2 = (int*)malloc(100 * sizeof(int));
//     int index1 = 0, index2 = 0;
    
//     collectLeaves(root1, leaves1, &index1);
//     collectLeaves(root2, leaves2, &index2);
    
//     if (index1 != index2) {
//         free(leaves1);
//         free(leaves2);
//         return false;
//     }
    
//     for (int i = 0; i < index1; i++) {
//         if (leaves1[i] != leaves2[i]) {
//             free(leaves1);
//             free(leaves2);
//             return false;
//         }
//     }
    
//     free(leaves1);
//     free(leaves2);
//     return true;
// }

// // Helper function to create a new TreeNode
// struct TreeNode* createNode(int val) {
//     struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//     newNode->val = val;
//     newNode->left = NULL;
//     newNode->right = NULL;
//     return newNode;
// }


