Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.
A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

Example 1:
Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.

x-------------------------------------------------------x----------------------x------------------------------------------------x

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> luckyNumbers;

        for (int i = 0; i < n; i++) {
            int num = numeric_limits<int>::max();
            int index = -1;
            // Find the minimum number in the current row
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] < num) {
                    num = matrix[i][j];
                    index = j;
                }
            }
            // Check if this number is the maximum in its column
            bool flag = true;
            for (int row = 0; row < n; row++) {
                if (matrix[row][index] > num) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                luckyNumbers.push_back(num);
            }
        }
        return luckyNumbers;
    }
};
