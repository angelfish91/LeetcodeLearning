class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        if (len == 0) return true;
        if (len % 2 != 0) return false;
        stack<char> tmp;
        for (int i = 0;i < len;i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                tmp.push(s[i]);
            }
            else {
                if (tmp.empty()) return false;
                char left = tmp.top();
                tmp.pop();
                if ((left == '('&&s[i] != ')') || (left == '['&&s[i] != ']') || (left == '{'&&s[i] != '}')) {
                    return false;
                }
            }
        }
        if (tmp.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};