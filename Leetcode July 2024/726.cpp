// Given a string formula representing a chemical formula, return the count of each atom.
// The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.
// One or more digits representing that element's count may follow if the count is greater than 1. 
// If the count is 1, no digits will follow.
// For example, "H2O" and "H2O2" are possible, but "H1O2" is impossible.
// Two formulas are concatenated together to produce another formula.
// For example, "H2O2He3Mg4" is also a formula.
// A formula placed in parentheses, and a count (optionally added) is also a formula.
// For example, "(H2O2)" and "(H2O2)3" are formulas.
// Return the count of all elements as a string in the following form: the first name (in sorted order), 
// followed by its count (if that count is more than 1), followed by the second name (in sorted order), 
// followed by its count (if that count is more than 1), and so on.
// The test cases are generated so that all the values in the output fit in a 32-bit integer.

Example 1:

Input: formula = "H2O"
Output: "H2O"
Explanation: The count of elements are {'H': 2, 'O': 1}.

x-----------------------------------------------x-----------------x-----------------------------------------------------------x

class Solution {
public:
    string countOfAtoms(string s) {
        stack<pair<string, int>> st; 
        stack<int> fact;
        int n = s.length(), m = 1, val = 1;

        for(int i = n - 1; i >= 0; i--){
            char ch = s[i];
            // ch --> lowercase letter
            if(ch >= 'a' && ch <= 'z'){
                string element = "";
                while(!(s[i] >= 'A' && s[i] <= 'Z')){
                    element = s[i] + element;
                    i--;
                }
                element = s[i] + element;
                int freq = m*val;
                st.push({element, freq});
                val = 1;
            }
            // ch --> uppercase letter
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                string element = "";
                element += s[i];
                int freq = m*val;
                st.push({element, freq});
                val = 1;
            }
            else if(ch == ')'){
                fact.push(val);
                m *= val;
                val = 1;
            }
            else if(ch == '('){
                m /= fact.top();
                fact.pop();
            }
            else{
                string num = "";
                while(s[i] <= '9' && s[i] >= '0'){
                    num = s[i] + num;
                    i--;
                }
                i++; 
                val = stoi(num);
            }
        }
        
        map<string, int> mp;
        while(! st.empty()){
            auto it = st.top(); st.pop();
            string str = it.first;
            int freq = it.second;
            mp[str] += freq;
        }
        string res = "";
        for(auto it : mp){
            string ele = it.first;
            string freq = "";
            if(it.second != 1) freq += to_string(it.second);
            res += ele + freq;
        }
        return res;
    }
};
