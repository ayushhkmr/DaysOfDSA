// Given a linked list with string data, check whether the combined string formed is palindrome. 
// If the combined string is palindrome then return true otherwise return false.

Example:
Input:
a -> bc -> d -> dcb -> a
Output : true
Explanation: As string "abcddcba" is palindrome the function should return true.

x--------------------------------------------------------x--------------x---------------------------------------x

class Solution {
  public:
    bool compute(Node* head) {
        // Your code goes here
         vector<char> nodesvalue;
       
       Node* temp=head;
       while(temp!=NULL){
           vector<char>  charArray(temp->data.begin(),temp->data.end());
           for(char c : charArray)
           nodesvalue.push_back(c);
           temp=temp->next;
       }
       int n = nodesvalue.size();
       
       for(int i=0;i<n/2;i++)
       {
           if(nodesvalue[i]!=nodesvalue[n-1-i])
           return false;
       }
       return true;
    }
};
