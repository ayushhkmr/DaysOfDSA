// Given a Binary Tree and an integer target. Find all the ancestors of the given target.
// Note:
// The ancestor of node x is node y, which is at the upper level of node x, and x is 
// directly connected with node y. Consider multiple levels of ancestors to solve this problem.
// In case there are no ancestors available, return an empty list.
Examples:

Input:
         1
       /   \
      2     3
    /  \    /  \
   4   5  6   8
  /
 7
target = 7
Output: [4 2 1]
Explanation: The given target is 7, if we go above the level of node 7, then we find 4, 2 and 1. Hence the ancestors of node 7 are 4 2 and 1

x--------------------------------------------------------------------x-------------x------------------------------------------------------------x

class Solution {
  public:
    // Function should return all the ancestor of the target node
    void solve(struct Node* root, int target, bool& key, vector<int>& ans){
        if (root == nullptr || key==true) return;
        
        if (key == false){
            solve(root->left, target, key, ans);
            solve(root->right, target, key, ans);
        }
        
        if (key == true){
            ans.push_back(root->data);
        }
        
        if (target == root->data){
            key = true;
        }
        
    }
    
    vector<int> Ancestors(struct Node *root, int target) {
        // Code here
        vector<int> ans;
        bool key = false;
        
        solve(root, target, key, ans);
        return ans;
    }
};
