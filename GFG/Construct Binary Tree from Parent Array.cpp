// Given an array parent that is used to represent a tree. The array indices (0-based indexing) 
// are the values of the tree nodes and parent[i] denotes the parent node of a particular node. 
// The parent of the root node would always be -1, as there is no parent for the root. 
// Construct the standard linked representation of Binary Tree from this array representation 
// and return the root node of the constructed tree.

// Note: If two elements have the same parent, the one that appears first in the array will be 
// the left child and the other is the right child. You don't need to print anything, 
// the driver code will print the level order traversal of the returned root node to verify the output.

// Examples:

// Input: parent[] = [-1, 0, 0, 1, 1, 3,5]
// Output: 0 1 2 3 4 5 6
// Explanation: the tree generated
// will have a structure like 
//           0
//         /   \
//        1     2
//       / \
//      3   4
//     /
//    5
//  /
// 6

x---------------------------------------------------------------x---------------------------x--------------------------------------------------x

class Solution {
  public:
    // Function to construct binary tree from parent array.
    Node *createTree(vector<int> parent) {
        // Your code here
         queue<Node*> q;
        Node* root;
        
        int n=parent.size();
        for(int i=0;i<n;i++){
            if(parent[i]==-1){
                root=new Node(i);
                q.push(root);
                break;
            }
        }
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[parent[i]].push_back(i);
        }
        
        
        while(!q.empty()){
            auto node=q.front(); q.pop();
            int cnt=0,rc=-1,lc=-1;
            if(mp.find(node->data)!=mp.end()){
                
                    lc=mp[node->data][0];
                    if(mp[node->data].size()>1) rc=mp[node->data][1];
                }
            if(lc!=-1) { node->left=new Node(lc); q.push(node->left); }
            if(rc!=-1) { node->right=new Node(rc); q.push(node->right); }
    }
        return root;
    }
};
