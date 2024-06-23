// Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
// Q. Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray 
// such that the absolute difference between any two elements of this subarray is less than or equal to limit.

Example 1:
Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.

Example 2:
Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3

  class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> m;
        int j = 0;
        int ans = 1;
        for (int i = 0; i < nums.size(); i++) {
            m.insert(nums[i]);

            while(!m.empty() && *m.rbegin()-*m.begin()>limit){
                m.erase(m.find(nums[j++]));
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};
