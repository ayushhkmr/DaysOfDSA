// Given the root of a binary tree. Check whether it is a BST or not.
// Note: We are considering that BSTs can not contain duplicate Nodes.
// A BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
// Examples:

// Input:
//    2
//  /    \
// 1      3
//         \
//          5
// Output: true 
// Explanation: 
// The left subtree of every node contains smaller keys and right subtree of every node contains greater. Hence, the tree is a BST.

x-----------------------------------------------------------x-------------------------x---------------------------------------------------x

lass Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
     bool isBSTUtil(Node* node, int min, int max) {
        if (node == nullptr) {
            return true;
        }
        if (node->data <= min || node->data >= max) {
            return false;
        }
     
        return isBSTUtil(node->left, min, node->data) && 
               isBSTUtil(node->right, node->data, max);
    }
    bool isBST(Node* root) {
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }
};
