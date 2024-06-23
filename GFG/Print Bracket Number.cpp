//Given a string str, the task is to find the bracket numbers, i.e., for each bracket in str, 
// return i if the bracket is the ith opening or closing bracket to appear in the string. 
//  Examples:

// Input:  str = "(aa(bdc))p(dee)"
// Output: 1 2 2 1 3 3
// Explanation: The highlighted brackets in
// the given string (aa(bdc))p(dee) are
// assigned the numbers as: 1 2 2 1 3 3.

// Input:  str = "(((()("
// Output: 1 2 3 4 4 5
// Explanation: The highlighted brackets in
// the given string (((()( are assigned
// the numbers as: 1 2 3 4 4 5

class Solution {
  public:
    vector<int> bracketNumbers(string str) {
        stack<int>s;
        vector<int>print;
        int count=0;
        for(char ch:str){
            if(ch=='('){
                count++;
                s.push(count);
                print.push_back(count);
                
            }
            else if(ch==')'){
                print.push_back(s.top());
                s.pop();
            }
        }
        return print;
    }
};
