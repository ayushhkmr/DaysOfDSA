Given an array arr containing non-negative integers. Count and return an array ans where ans[i] 
denotes the number of smaller elements on right side of arr[i].

Examples:
Input: arr[] = [12, 1, 2, 3, 0, 11, 4]
Output: [6, 1, 1, 1, 0, 1, 0]
Explanation: There are 6 smaller elements right after 12. There is 1 smaller element right after 1. And so on.

x--------------------------------------------------------x-------------------x---------------------------------------x

class Solution {
  public:
    vector<int> constructLowerArray(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int>ans(n, 0);
        multiset<int>st;
        st.insert(arr[n-1]);
        for(int i=n-2; i>=0; i--){
            int dist = distance(st.begin(), st.lower_bound(arr[i]));
            ans[i]=dist;
            st.insert(arr[i]);
        }
        return ans;
    }
};
