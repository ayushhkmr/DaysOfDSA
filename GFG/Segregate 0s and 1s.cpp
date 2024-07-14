Given an array arr consisting of only 0's and 1's in random order. Modify 
the array in-place to segregate 0s onto the left side and 1s onto the right side of the array.
  
Examples :
Input: arr[] = [0, 0, 1, 1, 0]
Output: [0, 0, 0, 1, 1]
Explanation:  After segregation, all the 0's are on the left and 1's are on the right. 
Modified array will be [0, 0, 0, 1, 1].

x-----------------------------------------------------------x----------------------x-----------------------------------------x

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
         int zeroes = 0;
        int ones = 0;
        
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == 0) zeroes++;
            else ones++;
        }
        
        for(int i = 0; i < arr.size(); i++){
            if(zeroes == 0 && ones == 0) break;
            if(zeroes > 0){
                arr[i] = 0;
                zeroes--;
            }
            else if(zeroes == 0 && ones > 0){
                arr[i] = 1;
                ones--;
            }
        }
    }
};
