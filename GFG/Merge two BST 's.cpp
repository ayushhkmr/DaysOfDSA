// Given two BSTs, return elements of merged BSTs in sorted form.

// Examples :

// Input:
// BST1:
//        5
//      /   \
//     3     6
//    / \
//   2   4  
// BST2:
//         2
//       /   \
//      1     3
//             \
//              7
//             /
//            6
// Output: 1 2 2 3 3 4 5 6 6 7
// Explanation: After merging and sorting the two BST we get 1 2 2 3 3 4 5 6 6 7.

x--------------------------------------------------------------x-------------------------------x-----------------------------x

class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
   vector<int> ans;
    
    void tree(Node *root){
        if(root == NULL){
            return;
        }
        ans.push_back(root->data);
        tree(root->left);
        tree(root->right);
    }
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        tree(root1);
        tree(root2);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
