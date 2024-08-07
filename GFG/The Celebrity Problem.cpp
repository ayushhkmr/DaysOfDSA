// A celebrity is a person who is known to all but does not know anyone at a party. 
// A party is being organized by some people.  A square matrix mat is used to represent 
// people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person.
// You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.
// Note: Follow 0-based indexing.

// Examples:
// Input: mat[][] = [[0 1 0],
//                 [0 0 0], 
//                 [0 1 0]]
// Output: 1
// Explanation: 0th and 2nd person both know 1. Therefore, 1 is the celebrity. 
// x-------------------------------------------------------------x--------------------------------------x----------------------------x
lass Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int n=mat.size();
        int res = -1;
        int count1 = 0;
        int count2 = 0;
        for(int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ; j++){
                    count1+=mat[i][j];
                    count2+=mat[j][i];
            }
            if (count1 == 0 && count2==n-1){
                res = i;
            }
            count1=0;
            count2=0;
        }
        return res;
    }
};
