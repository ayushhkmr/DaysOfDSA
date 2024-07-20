// You are given a binary tree and you need to remove all the half nodes (which have only one child). 
// Return the root node of the modified tree after removing all the half-nodes.

// Note: The output will be judged by the inorder traversal of the resultant tree, inside the driver code.

// Examples:

// Input: tree = 5
//             /   \
//           7     8
//         / 
//       2
// Output: 2 5 8
// Explanation: In the above tree, the node 7 has only single child. After removing the node the tree becomes  
// 2<-5->8. Hence, the answer is 2 5 8 & it is in inorder traversal.

x-------------------------------------------------------------x------------------x-----------------------------------------------------x
  
// Return the root of the modified tree after removing all the half nodes.
class Solution {
  public:
    Node *RemoveHalfNodes(Node *root) {
        // code here
           if(root->left==nullptr &&  root->right==nullptr)return root;
        int cheak=0;
        if(!(root->left)){
               cheak=1;
        }
        if(!(root->right)){
              cheak=1;
        }
        if(cheak){
              Node* ptr;
                if(root->left){
                      ptr=RemoveHalfNodes(root->left);
                      return ptr;    
                }
                else{ 
                    ptr=RemoveHalfNodes(root->right);
                         return ptr;       
                }
            
        }
        else {
             root->left=RemoveHalfNodes(root->left);
             root->right=RemoveHalfNodes(root->right);
             return root;
        }
    }
};
