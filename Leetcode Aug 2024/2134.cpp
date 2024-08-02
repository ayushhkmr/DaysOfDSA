A swap is defined as taking two distinct positions in an array and swapping the values in them.
A circular array is defined as an array where we consider the first element and the last element to be adjacent.
Given a binary circular array nums, return the minimum number of swaps required to group all 1's present in the array together at any location.

Example 1:
Input: nums = [0,1,0,1,1,0,0]
Output: 1
Explanation: Here are a few of the ways to group all the 1's together:
[0,0,1,1,1,0,0] using 1 swap.
[0,1,1,1,0,0,0] using 1 swap.
[1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
There is no way to group all 1's together with 0 swaps.
Thus, the minimum number of swaps required is 1.

x--------------------------------------------------------------------x---------------------------x-----------------------------------------------------x
class Solution {
public:
    int minSwaps(std::vector<int>& nums) {
        int total = std::accumulate(nums.begin(), nums.end(), 0); // Total number of 1's in the array
        int n = nums.size();
        
        // If there are no 1's, no swaps are needed
        if (total == 0) {
            return 0;
        }
        
        // Extend the array to handle the circular nature
        nums.insert(nums.end(), nums.begin(), nums.end());
        
        // Initialize the sliding window
        int window_sum = std::accumulate(nums.begin(), nums.begin() + total, 0);
        int max_ones = window_sum;
        int swaps = total - max_ones;
        
        for (int i = 1; i < n; ++i) {
            // Update the number of 1's in the current window by sliding the window
            window_sum += nums[i + total - 1] - nums[i - 1];
            max_ones = std::max(max_ones, window_sum);
            swaps = std::min(swaps, total - max_ones);
        }
        
        return swaps;
    }
};
