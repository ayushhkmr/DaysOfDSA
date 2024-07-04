// Given a binary tree, your task is to find all duplicate subtrees from the given binary tree.
// Duplicate Subtree : Two trees are duplicates if they have the same structure with the same node values.
// Note:  Return the root of each tree in the form of a list array & 
// the driver code will print the tree in pre-order tree traversal in lexicographically increasing order.
Examples:
Input:     5
          / \
         4   6
        / \
       3   4
          / \
         3   6
Output: 
3
6
Explanation: In the above tree, there are two duplicate subtrees.i.e
3 and 6. Therefore, you need to return the above subtrees root in the form of a list. 
  Here, 4 3  is not considered because for a subtree to be equal, it should have the 
same values as well as structure. If we consider the first subtree on the left, it has  
two children, 3 on the left and 4 3 6   on the right. And for the second subtree it 
has 3 on the left and 6 on the right.
Since the structures are not same for the subtrees hence they are not equal

x-----------------------------------------------x---------------x---------------------------------------------------------
  
class Solution {
  public:
    string helper(Node *root, vector<Node*> &ans, 
                unordered_map<string,int> &mp)
    {
        string temp = "";
        if(root == NULL)
            return "#";
        temp += to_string(root->data);
        temp += helper(root->left,ans,mp);
        temp += helper(root->right,ans,mp);
        if(mp[temp] == 1)
            ans.push_back(root);
        mp[temp]++;
        return temp;
        
    }
    vector<Node*> printAllDups(Node* root) 
    {
        vector<Node*> ans;
        unordered_map<string,int> mp;
        helper(root,ans,mp);
        return ans;
        // Code here
    }
};
