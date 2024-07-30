// You are given a string s consisting only of characters 'a' and 'b'​​​​.
// You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices 
// (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.
// Return the minimum number of deletions needed to make s balanced.

// Example 1:
// Input: s = "aababbab"
// Output: 2
// Explanation: You can either:
// Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
// Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").

// x-------------------------------------------------------------------x---------------------------x----------------------------------------------x

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        stack<char>st ; 
        int count = 0 ;
        st.push(s[0]);
        for(int i=1;i<n;i++){
            if(!st.empty()  && (st.top() == 'b' && s[i] == 'a')){
                st.pop();
                count+=1;
            }
            else{
                st.push(s[i]);
            }
        }
        return count ;
    }
};
