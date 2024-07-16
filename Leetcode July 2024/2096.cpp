You are given the root of a binary tree with n nodes. Each node is uniquely assigned 
a value from 1 to n. You are also given an integer startValue representing the value 
of the start node s, and a different integer destValue representing the value of the 
destination node t.

Find the shortest path starting from node s and ending at node t. Generate step-by-step 
directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. 
Each letter indicates a specific direction:

'L' means to go from a node to its left child node.
'R' means to go from a node to its right child node.
'U' means to go from a node to its parent node.
Return the step-by-step directions of the shortest path from node s to node t.

Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
Output: "UURL"
Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.

x------------------------------------------------------x-----------------------x--------------------------------------------x

class Solution {

private:
    void rootToNode(TreeNode* root,int &n,int &m,string &temp,string &s,string &d){
        if(!root) return;

        if(root->val == n) s=temp;
        if(root->val == m) d=temp;
        
        temp.push_back('L');
        rootToNode(root->left, n, m, temp, s, d);
        temp.pop_back();

        temp.push_back('R');
        rootToNode(root->right, n, m, temp, s, d);
        temp.pop_back();
    }


public:
    string getDirections(TreeNode* root, int n, int m) {

        string s,d,temp;
        rootToNode(root,n,m,temp,s,d);

        int ind = 0;

        for(int i=0;i<s.size() && i<d.size();i++){
            if(s[i]==d[i]) ind=i+1;
            else break;
        }

        string ans;

        for(int i = ind;i<s.size();i++){
            ans.push_back('U');
        }

        for(int i = ind;i<d.size();i++){
            ans.push_back(d[i]);
        }

        return ans;
    }
};
