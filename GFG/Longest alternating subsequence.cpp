// You are given an array arr. Your task is to find the longest length of a good sequence. 
// A good sequence {x1, x2, .. xn} is an alternating sequence if its elements satisfy one of the following relations :
// 1.  x1 < x2 > x3 < x4 > x5. . . . . and so on
// 2.  x1 >x2 < x3 > x4 < x5. . . . . and so on

// Examples:
// Input: arr= [1, 5, 4]
// Output: 3
// Explanation: The entire sequenece is a good sequence.

x-------------------------------------------x---------------------------x-----------------------------------------------x

class Solution {
  public:
   int alternatingMaxLength(vector<int>& arr) 
    {
        int inc = 1;
        int dec = 1;
        for(int i = 1; i < arr.size(); i++)
        {
            if(arr[i] > arr[i-1])
                inc = dec +1;
            else if(arr[i] < arr[i-1])
                dec = inc + 1;
        }
        return max(inc,dec);
        // Code here
    }
};
