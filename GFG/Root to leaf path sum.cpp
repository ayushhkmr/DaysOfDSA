//Given a binary tree and an integer target, check whether there is a root-to-leaf path with its sum as target.

Examples :

Input: tree = 1, target = 2
            /   \
          2     3
Output: false
Explanation: There is no root to leaf path with sum 2.

x---------------------------------------------------------------x-------------------x----------------------------------------------x

class Solution {
  public:
     int pathsum=0;
    bool hasPathSum(Node *root, int target) {
        // Your code here
        if(root==nullptr){
            return false;
        }
        queue<pair<Node*,int>> q;
        q.push({root, root->data});
        while(!q.empty()){
            
            auto x = q.front();
            Node *node = x.first;
            int sum = x.second;
            q.pop();

            if (node->left == nullptr && node->right == nullptr && sum == target) {
                return true;
            }

            if (node->left != nullptr) {
                q.push({node->left, sum + node->left->data});
            }

            if (node->right != nullptr) {
                q.push({node->right, sum + node->right->data});
            }
        }
        return false;
    }
};
