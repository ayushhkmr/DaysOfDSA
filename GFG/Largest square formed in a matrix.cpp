Given a binary matrix mat of size n * m, find out the maximum length of a side of a square sub-matrix with all 1s.
Examples:

Input: n = 6, m = 5
mat = [[0, 1, 1, 0, 1], 
       [1, 1, 0, 1, 0],
       [0, 1, 1, 1, 0],
       [1, 1, 1, 1, 0],
       [1, 1, 1, 1, 1],
       [0, 0, 0, 0, 0]]
Output: 3
  The maximum length of a side of the square sub-matrix is 3 where every element is 1.

Input: n = 2, m = 2
mat = [[1, 1], 
       [1, 1]]
Output: 2
Explanation: The maximum length of a side of the square sub-matrix is 2. The matrix itself is the maximum sized sub-matrix in this case.

x-----------------------------------------x------------------------------x--------------------------------------------------------------------x

class Solution {
  public:
     int solve(vector<vector<int>> &mat,int i,int j,int &maxi,vector<vector<int>> &dp){
        if(i>=mat.size() || j>=mat[0].size())
            return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }   
        int right=solve(mat,i,j+1,maxi,dp);
        int diagonal=solve(mat,i+1,j+1,maxi,dp);
        int down=solve(mat,i+1,j,maxi,dp);
        
        if(mat[i][j]==1){
           dp[i][j]=1+min(right,min(diagonal,down));
           maxi=max(maxi,dp[i][j]);
           return dp[i][j];
        }
        else{
            return dp[i][j]=0;
        }
        
    }
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        int maxi=0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        solve(mat,0,0,maxi,dp);
        return maxi;
    }
};
