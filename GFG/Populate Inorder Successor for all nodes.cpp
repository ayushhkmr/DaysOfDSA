// Given a Binary Tree, complete the function to populate the next pointer for all nodes. 
//   The next pointer for every node should point to the Inorder successor of the node.
// You do not have to return or print anything. Just make changes in the root node given to you.

// Note: The node having no in-order successor will be pointed to -1. You don't 
// have to add -1 explicitly, the driver code will take care of this.

Examples :

Input:
       10
       /  \
      8   12
     /
    3
Output: 3->8 8->10 10->12 12->-1
Explanation: The inorder of the above tree is : 3 8 10 12. So the next pointer of node 3 is pointing to 8 ,
next pointer of 8 is pointing to 10 and so on.And next pointer of 12 is pointing to -1 as there is no inorder successor of 12.

  x----------------------------------x-----------------------------------x------------------------------------------------------------x

class Solution {
  public:

    void build(Node*& root , Node*& prev){
       if(root){
           build(root->left , prev);
           if(prev){
               prev->next=root;
               prev=root;
           }else{
               prev=root;
           }
           
           build(root->right, prev);
       }
   }
    
    void populateNext(Node *root) {
        // code here
      Node* prev=nullptr;
    
      build(root, prev );
       
      
       
    }
};
