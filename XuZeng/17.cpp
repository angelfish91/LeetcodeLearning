class Solution {
    vector<string> result;
    string digits;
    unordered_map<char, string> store;
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
        {
            return result;
        }
        this->digits = digits;
        //´¢´æ×Öµä
        store = unordered_map<char, string>{
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        dfs("", 0);
        return result;
    }
    void dfs(string resultStr, int index)
    {
        int digitsSize = int(this->digits.size());
        if (digitsSize == index)
        {
            result.push_back(resultStr);
            return;
        }
        char targetChar = this->digits[index];
        string targetStr = store[targetChar];
        for (auto tmpChar : targetStr)
        {
            dfs(resultStr + tmpChar, index + 1);//µÝ¹éµ÷ÓÃ
        }
        return;
    }
};