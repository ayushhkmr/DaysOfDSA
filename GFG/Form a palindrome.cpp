// Given a string, find the minimum number of characters to be inserted to convert it to a palindrome.

// Examples :
// Input: str = "abcd"
// Output: 3
// Explanation: Inserted character marked with bold characters in dcbabcd, here we need minimum three characters to make it palindrome.
// Input: str = "aa"
// Output: 0
// Explanation: "aa" is already a palindrome.
// x---------------------------------------------------------x-----------------------------------x---------------------------------------------x

class Solution{
  public:
    vector<vector<int>> memo; 

    int dp(int i, int j, const string& str) {
        if (i >= j) 
        {
            return 0;
        }
        
        if (memo[i][j] != -1) 
        {
            return memo[i][j];
        }
        
        if (str[i] == str[j]) {
            memo[i][j] = dp(i + 1, j - 1, str);
        } else {
            int ans = INT_MAX;
            ans = min(ans, 1 + dp(i + 1, j, str)); 
            ans = min(ans, 1 + dp(i, j - 1, str));
            memo[i][j] = ans;
        }
        return memo[i][j];
    }

    int countMin(string str) {
        int n = str.size();
        memo.resize(n, vector<int>(n, -1));
        return dp(0, n - 1, str);
    }
};
