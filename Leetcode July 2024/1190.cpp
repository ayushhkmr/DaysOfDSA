// You are given a string s that consists of lower case English letters and brackets.
// Reverse the strings in each pair of matching parentheses, starting from the innermost one.
// Your result should not contain any brackets.

Example 1:

Input: s = "(abcd)"
Output: "dcba"
Example 2:

Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.

x---------------------------------------------------x-----------------------x-------------------------------------x
  
class Solution {
public:
    string reverseParentheses(string s) {
        std::stack<char> stack;
for (int i = 0; i < s.length(); i++) {
    char c = s[i];
    
    if (c == ')') {
        std::string rev = "";
        while (!stack.empty() && stack.top() != '(') {
            rev += stack.top();
            stack.pop();
        }
        if (!stack.empty()) {
            stack.pop(); // pop the opening bracket
        }
        for (int j = 0; j < rev.length(); j++) {
            stack.push(rev[j]);
        }
    } else {
        stack.push(c);
    }
}

std::string result = "";
while (!stack.empty()) {
    result = stack.top() + result;
    stack.pop();
}
return result;
    }
};
