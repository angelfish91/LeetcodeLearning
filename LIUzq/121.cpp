//121 买卖股票的最佳时机

//错误解答，只有最后一个测试用例不通过，[10000,9999,...0,0,0...0],运算时间超时

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //没有买卖，或者只买了一股
        if(prices.empty() || prices.size() == 1) return 0;

        vector<int> dp(prices.size(), 0);
        for(int i=0; i<prices.size()-1; i++){   //如果i<prices.size()-2的话，[1,2]i即为i<0，不成立
            for(int j=i+1; j<prices.size(); j++){
                dp[j] = max(dp[j], prices[j]-prices[i]);
            }
        }
        sort(dp.begin(), dp.end());
        return (dp[prices.size()-1] > 0) ? dp[prices.size()-1] : 0;
    }
};

//虽然是dp思想但是想法太复杂，本题就是为了记录今天买入之前的最小值和今天卖出获取的利润最大值，
//上面只是获取了最大值，通过两层循环挨个比较，时间复杂度为O（n2），故运算超时，用一个缓存器记录一下今天之前的最小值，再做差复杂度就
//降了一个等级。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //没有买卖，或者只买了一股
        if(prices.empty() || prices.size() == 1) return 0;
        int mn = prices[0];
        int mx = 0;
        for(int i=1; i<prices.size(); i++){  
            mx = max(prices[i]-mn, mx);
            mn = min(prices[i], mn);
        }
        return mx;
    }
};