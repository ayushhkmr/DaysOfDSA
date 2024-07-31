// Given an array of strings arr. Return the longest common prefix among all strings present in the array. 
// If there's no prefix common in all the strings, return "-1".

// Examples :
// Input: arr[] = ["geeksforgeeks", "geeks", "geek", "geezer"]
// Output: gee
// Explanation: "gee" is the longest common prefix in all the given strings.
// x-------------------------------------------------------x-----------------------------x-------------------------------------------------x
class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        sort(arr.begin(),arr.end());
        
        string a = arr[0];
        string b = arr[arr.size()-1];
        int i = 0;
        string ans="";
        char ch;
        while(i<a.size() ){
            if( a[i] == b[i]){
                ans+=a[i];
                i++;
            }
            else break;
        }
        if(ans.size() == 0)return "-1";
        else 
        return ans;
    }
};
