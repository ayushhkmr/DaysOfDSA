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
      vector<int> ans;
    int n= arr.size();
    vector<int> temp;
      
        for(int i=0;i<n;i++){
            temp.push_back(arr[i]);
        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<n;i++){
            int index=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
            ans.push_back(index);
            temp.erase(temp.begin()+index);
        }
        return ans;
    }
};
