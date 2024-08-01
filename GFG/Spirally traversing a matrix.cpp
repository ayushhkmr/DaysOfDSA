# You are given a rectangular matrix, and your task is to return an array while traversing the matrix in spiral form.

# Examples:
# Input: matrix[][] = [[1, 2, 3, 4],
#                   [5, 6, 7, 8],
#                   [9, 10, 11, 12],
#                   [13, 14, 15,16]]
# Output: [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]
# x-----------------------------------------------------------------x-------------------x---------------------------------------x

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        int top = 0;
        int left = 0;
        int right = matrix[0].size()-1;
        int bottom = matrix.size()-1;
        int totalElements = ( matrix.size() * matrix[0].size() );
        vector<int> ans;
        
        if (matrix.empty() || matrix[0].empty()) {
        return ans; // Return an empty vector for an empty matrix
        }
        
        while(totalElements > 0 ){
            
            // top
            for(int j=left; j<=right && totalElements>0; j++){
                ans.push_back(matrix[top][j]);
                totalElements--;
            }
            top++;
            // right
            for(int i=top; i<=bottom && totalElements>0; i++){
                ans.push_back(matrix[i][right]);
                totalElements--;
            }
            right--;
            //bottom 
            for(int j=right; j>=left && totalElements>0; j--){
                ans.push_back(matrix[bottom][j]);
                totalElements--;
            }
            bottom--;
            //left
            for(int i=bottom; i>=top && totalElements>0; i--){
                ans.push_back(matrix[i][left]);
                totalElements--;
            }
            left++;
        }
        return ans;
    }
};
