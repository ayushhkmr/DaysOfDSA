// You are given an integer k and matrix mat. Rotate the elements 
// of the given matrix to the left k times and return the resulting matrix.

Examples:

Input: k=1, mat=[[1,2,3],[4,5,6],[7,8,9]]
Output:
2 3 1
5 6 4
8 9 7
Explanation: Rotate the matrix by one
1 2 3       2 3 1
4 5 6  =>  5 6 4
7 8 9       8 9 7
  
Input: k=2, mat=[[1,2,3],[4,5,6],[7,8,9]]
Output:
3 1 2
6 4 5
9 7 8
Explanation: After rotating the matrix looks like
1 2 3       2 3 1       3 1 2
4 5 6  =>  5 6 4  =>   6 4 5
7 8 9       8 9 7       9 7 8

x------------------------------------x--------------------x----------------------------------------------------x

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        int n = mat.size();  // Number of rows
        int m = mat[0].size();  // Number of columns
      
        // Adjust k to avoid excess shifts
        k %= m;
        // Rotate each row
        for (auto& row : mat) {
            reverse(row.begin(), row.end());  // Reverse the row
            reverse(row.begin(), row.begin() + (m-k));  // Reverse the first k elements
            reverse(row.begin() + (m-k), row.end());  // Reverse the remaining elements
        }
        return mat;
    }
};
