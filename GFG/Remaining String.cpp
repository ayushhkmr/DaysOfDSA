// Given a string s without spaces, a character ch and an integer count. 
// Your task is to return the substring that remains after the character ch has appeared count number of times.
// Note:  Assume upper case and lower case alphabets are different. 
// “”(Empty string) should be returned if it is not possible, or the remaining substring is empty.

// Examples:

// Input: s = "Thisisdemostring", ch = 'i', count = 3
// Output: ng
// Explanation: The remaining substring of s after the 3rd
// occurrence of 'i' is "ng", hence the output is ng.
  
x-----------------------------------------------x--------------------------x-----------------------------------------------x
  
class Solution {
  public:

    string printString(string s, char ch, int count) {
        // Your code goes here
        int occurs = 0;
        
        for(int i=0; i<s.size(); i++){
            if(s[i] == ch){
                occurs++;
            }
            
            if(occurs == count){
                return s.substr(i+1);
            }
        }
        return "";
    }
};
