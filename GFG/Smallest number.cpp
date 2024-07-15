// Given two integers s and d. The task is to find the smallest number such that the sum of its 
// digits is s and the number of digits in the number are d. Return a string that is the smallest 
// possible number. If it is not possible then return -1.

// Examples:

// Input: s = 9, d = 2
// Output: 18 
// Explanation: 18 is the smallest number possible with the sum of digits = 9 and total digits = 2.

x-------------------------------------------------------x-----------------x-----------------------------------------x

class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
         if(s>9*d) return "-1";
        string res(d,' ');
        // putting 1 in the begining
        s--;
        for(int i=d-1;i>=1;i--){
            int diff=min(9,s); // appending 9 in end or req sum
            res[i]='0'+diff;
            s-=diff;
        }
        
        res[0]='1'+s;
        return res;
    }
};
