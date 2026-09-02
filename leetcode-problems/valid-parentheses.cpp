/*
    20. Valid Parentheses
    Given a string s containing just 
        the characters '(', ')', '{', '}', '[' and ']', 
        determine if the input string is valid.

    An input string is valid if:
        Open brackets must be closed by the 
            same type of brackets.
        Open brackets must be closed in the correct order.
        Every close bracket has a corresponding 
            open bracket of the same type.

    Example 1:
        Input: s = "()"
        Output: true
    Example 2:
        Input: s = "()[]{}"
        Output: true
    Example 3:
        Input: s = "(]"
        Output: false
    Example 4:
        Input: s = "([])"
        Output: true
    Example 5:
        Input: s = "([)]"
        Output: false
*/

#include <iostream>
#include <string>
#include <stack>
#define DEBUG(x) std::cout << #x << " = " << (x) << '\n'

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        for (const char& c : s) {

            if (isBracketOpen(c)) {
                brackets.push(
                    transformOpenBracketToClosed(c)
                );
                continue;
            } 
            if (brackets.empty()) {
                return false;
            }
            if (brackets.top() == c) {
                brackets.pop();
                continue;
            }

            return false;
        }
        return brackets.empty();
    }
private:
    bool isBracketOpen(char c) {
        return (c == '{' || c == '[' || c == '(');
    }

    char transformOpenBracketToClosed(char c) {
        switch (c)
        {
            case '{':
                return '}';
            case '[':
                return ']';
            case '(':
                return ')';
        }
        return ' ';
    }
};

int main() {
    Solution solution;

    string s = "";
    DEBUG(s);
    bool result = solution.isValid(s);
    DEBUG(result);

    s = "{{{";
    DEBUG(s);
    result = solution.isValid(s);
    DEBUG(result);

    s = "){}";
    DEBUG(s);
    result = solution.isValid(s);
    DEBUG(result);

    s = "{((}))}";
    DEBUG(s);
    result = solution.isValid(s);
    DEBUG(result);

    s = "{[]}({})";
    DEBUG(s);
    result = solution.isValid(s);
    DEBUG(result);

    return 0;
}