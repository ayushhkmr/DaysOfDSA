// Given a boolean 2D array, consisting of only 1's and 0's, where each row is sorted. 
// Return the 0-based index of the first row that has the most number of 1s. If no such row exists, return -1.
// Examples:
// Input: arr[][] = [[0, 1, 1, 1],
//                [0, 0, 1, 1],
//                [1, 1, 1, 1],
//                [0, 0, 0, 0]]
// Output: 2
// Explanation: Row 2 contains 4 1's (0-based indexing).
// x------------------------------------x-----------------------------------------x-----------------------------------------------------x
class Solution {
public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int ans = 0;
        int row = -1;  // Initialize row to -1 to handle the case when no 1s are found
        int n = arr.size();
        int m = arr[0].size();

        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < m; j++) {
                if(arr[i][j] == 1) {
                    count++;
                }
            }
            if(count > ans) {
                ans = count;
                row = i;
            }
        }

        return row;
    }
};
