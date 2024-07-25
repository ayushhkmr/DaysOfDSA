// Given a sorted array. Convert it into a Height Balanced Binary Search Tree (BST). Return the root of the BST.

// Height-balanced BST means a binary tree in which the depth of the left subtree and the right subtree of every node never differ by more than 1.

// Note: The driver code will check the BST, if it is a Height-balanced BST, the output will be true otherwise the output will be false.

// Examples :

// Input: nums = [1, 2, 3, 4]
// Output: true
// Explanation: The preorder traversal of the following BST formed is [2, 1, 3, 4]:
//            2
//          /   \
//         1     3
//                \
//                 4

// x------------------------------------------------------------------x----------------------x-------------------------------------------------------x
class Solution {
  public:
     Node* BST(vector<int>&nums,int i,int j){
        if(i>j)
            return NULL;
        int mid=(i+j)/2;
        Node* root= new Node(nums[mid]);
        root->left=BST(nums,i,mid-1);
        root->right=BST(nums,mid+1,j);
        
        return root;
    }
    Node* sortedArrayToBST(vector<int>& nums) {
        return BST(nums,0,nums.size()-1);
    }
};