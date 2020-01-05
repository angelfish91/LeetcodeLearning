class Solution {
public:
    void backtrace(int left, int right, int n, string& s, vector<string>& res) {
        if (left == n && right == n) {
            res.push_back(s);
            return;
        }
        if (left < n) {
            s += "(";
            backtrace(left + 1, right, n, s, res);
            s.pop_back();
        }
        if (right < left) {
            s += ")";
            backtrace(left, right + 1, n, s, res);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        backtrace(0, 0, n, s, res);
        return res;
    }
};