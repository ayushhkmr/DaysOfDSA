// Given an array arr. The task is to find and return the maximum product possible with the subset of elements present in the array.
// Note:
// The maximum product can be a single element also.
// Since the product can be large, return it modulo 109 + 7.
// Examples:
// Input: arr[] = [-1, 0, -2, 4, 3]
// Output: 24
// Explanation: Maximum product will be ( -1 * -2 * 4 * 3 ) = 24

 x------------------------------------------------------------------------------x----------------------x----------------------------------x
  
class Solution {
   public:
    int mod = 1e9 + 7;
    long long int findMaxProduct(vector<int>& arr) {
    sort(arr.begin(), arr.end());
        long long ans = 0;
        
        int n = arr.size();
        if(n==1) return arr[0];
        int i= n-1;
        for( ; i>=0; i--){
            if(arr[i] < 0) break;
            if(arr[i] == 0) continue;
            
            if(ans == 0) ans+=arr[i];
            else ans = (ans * arr[i]) % mod;
        }
        
        if((i+1)%2 != 0) i--;
        
        while(i>=0){
            if(ans == 0) ans+=abs(arr[i]);
            else ans = (ans * abs(arr[i])) % mod;
            i--;
        }
        
        return ans;
    }
};
