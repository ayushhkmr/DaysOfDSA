// Given a string str without spaces, the task is to remove all duplicate characters from it, keeping only the first occurrence.
// Note: The original order of characters must be kept the same. 

// Examples :
// Input: str = "zvvo"
// Output: "zvo"
// Explanation: Only keep the first occurrence
// x----------------------------------------------x----------------------------x-----------------------------------------------------------x

class Solution {
  public:

    string removeDups(string str) {
        // Your code goes here
        unordered_map<char,bool>mp;
        int n=str.length();
        string ans;
        
        for(int i=0;i<n;i++){
            if(mp[str[i]]==false){
                ans+=str[i];
                mp[str[i]]=true;
            }
        }
        return ans;
    }
};
