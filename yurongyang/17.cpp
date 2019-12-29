class Solution {
public:
    unordered_map<char,string> dict {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};

public:
    void func(vector<string> &res, string str, string &digits, unordered_map<char, string> &m, int k){
        if(str.size() == digits.size()){
            res.push_back(str);
            return;
        }
        string tmp = m[digits[k]];
        for(char w : tmp){
            str += w;
            func(res, str, digits, m, k+1);
            str.pop_back();
        }
        return ;
    }

    vector<string> letterCombinations(string digits) {
       if(digits.size() == 0){
            return {};
        }
        vector<string> res;
        func(res,"",digits,dict,0);
        return res;
    }
};
