// Given a Linked List Representation of Complete Binary Tree. 
// Your task is to construct the Binary tree from the given linkedlist and return the root of the tree.
// The result will be judged by printing the level order traversal of the Binary tree. 
// Note: The complete binary tree is represented as a linked list in a way 
// where if the root node is stored at position i, its left, and right children 
// are stored at position 2*i+1, and 2*i+2 respectively. H is the height of the 
// tree and this space is used implicitly for the recursion stack.

// Examples:
Input: list = 1->2->3->4->5
Output: 1 2 3 4 5
Explanation: The tree would look like
      1
    /   \
   2     3
 /  \
4   5
Now, the level order traversal of
the above tree is 1 2 3 4 5.

x----------------------------------------------------x--------------x------------------------------------------x

class Solution {
  public:
    void convert(Node *h, TreeNode *&r) {
          queue<TreeNode*> q;
        TreeNode *t = NULL;
        
        r = new TreeNode(h->data);
        q.push(r);
        h = h->next;
        while(h and q.size()){
            t = q.front(), q.pop();
            t->left = new TreeNode(h->data);
            h = h->next;
            q.push(t->left);
            
            if(h){
                t->right = new TreeNode(h->data);
                q.push(t->right);
                h = h->next;
            }
        }
    }
};
