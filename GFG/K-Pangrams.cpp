// Given a string str and an integer k, return true if the string can be changed into a pangram after at most k operations, else return false.
// A single operation consists of swapping an existing alphabetic character with any other lowercase alphabetic character.
// Note - A pangram is a sentence containing every letter in the english alphabet.
// Examples :
// Input: str = "the quick brown fox jumps over the lazy dog", k = 0
// Output: true
// Explanation: the sentence contains all 26 characters and is already a pangram.
// x---------------------------------------------x------------------------------x------------------------------------------------------------------------x
class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
         set<char>st;
        int count = 0;
        for(int i=0;i<str.length();i++)
        {
             if(str[i]!=' ' and str[i]!=',' and str[i]!='.'){
             count++;
             st.insert(str[i]);
             }
        }
        if(count < 26 ) return false;
        // cout<<st.size()<<endl;
        if(st.size()==26)return true;
        if(26 - st.size() <= k) return true;
        return false;
    }
};
