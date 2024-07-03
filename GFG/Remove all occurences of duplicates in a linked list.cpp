// Given a sorted linked list, delete all nodes that have duplicate numbers 
// (all occurrences), leaving only numbers that appear once in the original list, 
// and return the head of the modified linked list. 

Examples:
Input: Linked List = 23->28->28->35->49->49->53->53
Output: 23 35
Explanation: 
The duplicate numbers are 28, 49 and 53 which are removed from the list.

x---------------------------x------------------------------x-----------------------------------x--------x

class Solution {
  public:
     void del(Node* &curr, Node* &next1) {
    // delete nodes one by one
        delete curr;
        delete next1;
    }

    Node* removeAllDuplicates(struct Node* head) {
        if (!head || !head->next) return head;

        Node* dummy = new Node(0); // Dummy node to simplify edge cases
        dummy->next = head;
        Node* prev = dummy;
        Node* curr = head;

        while (curr != nullptr && curr->next != nullptr) {
            if (curr->data == curr->next->data) {
                // Skip all nodes with the same value
                while (curr->next != nullptr && curr->data == curr->next->data) {
                    Node* temp = curr->next;
                    curr->next = temp->next;
                    delete temp;
                }
                // Remove the first duplicate node
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        Node* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
