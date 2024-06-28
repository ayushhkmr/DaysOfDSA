 // Given a two-dimensional integer array arr of dimensions n x n, 
// consisting solely of zeros and ones, identify the row or column 
// (using 0-based indexing) where all elements form a palindrome. 
// If multiple palindromes are identified, prioritize the palindromes 
// found in rows over those in columns. Within rows or columns, the palindrome 
// with the smaller index takes precedence. The result should be represented by 
// the index followed by either 'R' or 'C', indicating whether the palindrome was 
// located in a row or column. The output should be space-separated. If no palindrome is found, return the string -1.

Examples:

Input: 
arr[][] =  [[1, 0, 0], 
           [0, 1, 0],
           [1, 1, 0]]
Output: 1 R
Explanation: In the first test case, 0-1-0 is a palindrome 
occuring in a row having index 1.

x--------------------------------------------------x-----------x---------------------------------------------------------------x
class Solution{
  public:

    string pattern(vector<vector<int>> &arr) {
        // Code Here
         string ans = "-1";
        int n = arr.size();
        for(int i = 0; i < n; i++){
            bool flag = true;
            
            int temp1 = 0;
            int temp2 = n-1;
            
            while(temp1 <= temp2){
                if(arr[i][temp1] != arr[i][temp2]){
                    flag = false;
                }
                temp1++;
                temp2--;
            }
            
            if(flag){
                ans.erase();
                ans.append(to_string(i));
                ans.append(" R");
                return ans;
            }
        }
        
        for(int i = 0; i < n; i++){
            bool flag = true;
            
            int temp1 = 0;
            int temp2 = n-1;
            
            while(temp1 <= temp2){
                if(arr[temp1][i] != arr[temp2][i]){
                    flag = false;
                }
                temp1++;
                temp2--;
            }
            
            if(flag){
                ans.erase();
                ans.append(to_string(i));
                ans.append(" C");
                return ans;
            }
        }
        
        return ans;
    }
};
