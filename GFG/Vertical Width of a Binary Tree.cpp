Given a Binary Tree. You need to find and return the vertical width of the tree.

Examples :

Input:
         1
       /    \
      2      3
     / \    /  \
    4   5  6   7
            \   \
             8   9
Output: 6
Explanation: The width of a binary tree is
the number of vertical paths in that tree.

x--------------------------------------------------x----------------------x-------------------------------------x
  
class Solution {
  public:
    // Function to find the vertical width of a Binary Tree.
    int s=0;
    int l=0;
    void calculate(Node*root, int d)
    {
        if(!root) return;
        s=min(d,s);
        l=max(d,l);
        calculate(root->left, d-1);
        calculate(root->right, d+1);
    }
    int verticalWidth(Node* root) {
        // code here
        if(!root) return 0;
        calculate(root, 0);
        return l-s+1;
    }
};
