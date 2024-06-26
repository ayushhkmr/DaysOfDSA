// Given a binary matrix contains 0s and 1s only, we need to find the sum of coverage
// of all zeros of the matrix where coverage for a particular 0 is defined as a total 
// number of ones around a zero in left, right, up and bottom directions.

Input:
matrix = [[0, 1, 0],
          [0, 1, 1],
          [0, 0, 0]]
Output: 6
Explanation: There are a total of 6 coverage are there

Input: 
matrix = [[0, 1]]
Output: 1
Explanation: There are only 1 coverage.

x------------------------------------------------------------x----------------x-------------------------------------x

class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        // Code here
         int rows = matrix.size();
    int cols = matrix[0].size();
    int totalCoverage = 0;

    // Iterate through each cell
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 0) {
                // Calculate coverage for this zero
                int coverage = 0;
                if (i > 0 && matrix[i - 1][j] == 1) coverage++; // Up
                if (i < rows - 1 && matrix[i + 1][j] == 1) coverage++; // Down
                if (j > 0 && matrix[i][j - 1] == 1) coverage++; // Left
                if (j < cols - 1 && matrix[i][j + 1] == 1) coverage++; // Right
                totalCoverage += coverage;
            }
        }
    }

    return totalCoverage;
    }
};
