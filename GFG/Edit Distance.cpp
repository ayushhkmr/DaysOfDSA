Given two strings str1 and str2. Return the minimum number of operations required to convert str1 to str2.
The possible operations are permitted:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.
Examples:

Input: str1 = "geek", srt2 = "gesek"
Output: 1
Explanation: One operation is required, inserting 's' between two 'e'.

x-------------------------------------x------------------------------x-------------------------------------------------x

class Solution {
  public:
   int solve(string &str1,string &str2,int i,int j,vector<vector<int>>&dp){
      if(i==str1.length()&&j!=str2.length()){
          return str2.length()-j;
      }
      
      if(j==str2.length()&&i!=str1.length()){
          return str1.length()-i;
      }
      
      if(i==str1.length()&&j==str2.length()){
          return 0;
      }
      if(dp[i][j]!=-1){
          return dp[i][j];
      }
      
      int ans=0;
      if(str1[i]==str2[j]){
          return solve(str1,str2,i+1,j+1,dp);
      }else{
          // insert
          int insert=solve(str1,str2,i,j+1,dp)+1;
          // remove
          int remove=solve(str1,str2,i+1,j,dp)+1;
         // replace
         int replace=solve(str1,str2,i+1,j+1,dp)+1;
         
         dp[i][j]=min(insert,min(remove,replace));
      }
      return dp[i][j];
      
      
  }
    int editDistance(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans=solve(str1,str2,0,0,dp);
        return ans;
    }
};
