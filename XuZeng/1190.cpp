class Solution {
public:
    string reverseParentheses(string s) {
    string res;
    stack<string> stk;
    for (char &c : s) {
        if (c == '(') {
            stk.push(res);
            res = "";
        } else if (c == ')') {
            reverse(res.begin(), res.end());
            res = stk.top() + res;
            stk.pop();
        } else {
            res.push_back(c);
        }
    }
    return res;
    }
};