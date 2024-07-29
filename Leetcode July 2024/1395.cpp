// There are n soldiers standing in a line. Each soldier is assigned a unique rating value.
// You have to form a team of 3 soldiers amongst them under the following rules:
// Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
// A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
// Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

// Example 1:
// Input: rating = [2,5,3,4,1]
// Output: 3
// Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 
// x----------------------------------------------------------x------------------------------x----------------------------------------x

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int total = 0;

        for ( int i = 0 ; i < rating.size() ; i ++ ){
            int right_less = 0 , right_more = 0 , left_less = 0 , left_more = 0;

            for ( int j = i + 1 ; j < rating.size() ; j ++ ){
                if ( rating[j] < rating[i] ) right_less++;
                else if ( rating[i] < rating[j] ) right_more++;
            }
            for ( int j = 0 ; j < i ; j ++ ){
                if ( rating[j] < rating[i] ) left_less++;
                else if ( rating[i] < rating[j] ) left_more ++;
            }

            total += right_less*left_more + right_more*left_less;
        }

        return total;
    }
};
