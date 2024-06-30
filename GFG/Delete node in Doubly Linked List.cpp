// Given a doubly Linked list and a position. The task is to delete 
// a node from a given position (position starts from 1) in a doubly
// linked list and return the head of the doubly Linked list.

Examples:

Input: LinkedList = 1 <--> 3 <--> 4, x = 3
Output: 1 3  
Explanation: 
After deleting the node at position 3 (position starts from 1),the linked list will be now as 1 <--> 3.

x-----------------------------------------------x---------------x------------------------------------------------------x
  
class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        // Your code here
         if(x == 1)
        {
            head = head->next;
            head->prev = NULL;
            return head;
        }
        int node = 1;
        Node* temp = NULL;
        while(node < x )
        {
            if(!temp)
            {
                temp = head;
            }
            else{
                temp = temp->next;
            }
            node++;
        }
        if(temp->next->next){
            temp->next = temp->next->next;
            Node* fwd = temp->next;
            fwd->prev = temp;
        }
        else{
            temp->next = NULL;
        }
        return head;
    }
};
