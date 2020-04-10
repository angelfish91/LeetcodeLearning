括号生成


//昨天没休息好，今天很累，大脑很糊，勉强应付了打卡，明天仔细研究一下

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        //动态规划
        vector<vector<string> > dp(n+1);
        dp[0].push_back("");
        for(int i = 1; i < n+1; i++){
            for(int j = 0; j < i; j++){
                for(string& str1 : dp[j]){
                    for(string& str2 : dp[i-j-1]){
                        dp[i].push_back('(' + str1 + ')' + str2);
                    }
                }
            }
        }
        return dp[n];
    }
};