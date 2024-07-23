// Given an array of integers nums, sort the array in increasing order based on the frequency of the values. 
// If multiple values have the same frequency, sort them in decreasing order.
// Return the sorted array.
  
// Example 1:
// Input: nums = [1,1,2,2,2,3]
// Output: [3,1,1,2,2,2]
// Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.

// x-----------------------------------------------------------x-----------------------------x----------------------------------x
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {

        unordered_map<int,int> freq;

        for(auto &num: nums){
            freq[num]++;           
        }
        map<int,vector<int>> freqGrp;

        for(auto &it: freq){
            freqGrp[it.second].push_back(it.first);       
        }
        vector<int> ans;

        for(auto &it: freqGrp){
            if(it.second.size() > 1){
                sort(it.second.rbegin(), it.second.rend());              
            }
            for(auto &num: it.second){
                for(int i=0;i<it.first;i++){
                    ans.push_back(num);
                }  
            }
        }
        return ans;
    }
};
