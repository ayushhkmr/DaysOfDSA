// Given the two singly Linked Lists respectively. The task is to check whether two linked lists are identical or not. 
// Two Linked Lists are identical when they have the same data and with the same arrangement too. 
//   If both Linked Lists are identical then return true otherwise return false. 

Input:
LinkedList1: 1->2->3->4->5->6
LinkedList2: 99->59->42->20
Output: false
  
x----------------------------------------------x-----------x-----------------------------------------------------------x

// Function to check whether two linked lists are identical or not.
bool areIdentical(struct Node *head1, struct Node *head2) {
    Node* temp1=head1;
    Node* temp2=head2;
    
    while(temp1!=NULL && temp2!=NULL){
        
        if((temp1->data)!=(temp2->data)) return false;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    
    if( temp1==NULL && temp2==NULL) return true;
    
    else{
        return false;
    }
}
