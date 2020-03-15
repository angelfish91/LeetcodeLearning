//322.零钱兑换
//该题和网易面试题《找零》有所差别：《找零》是有最小面值1的，而且一定是可以找开的，所以有非-1值返回，
//本题中存在零钱兑换失败的情况，即返回-1

//所以对dp[]的初始化有所不同《找零》初始化为[0,1,2,3,....amount],而本题初始化为[amount+1,amount+1,.....]amount+1个元素


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //将dp初始化为amount+1 是因为： 金额为amount时最多硬币数为amount（全为1元硬币），所以初始化为amount+1，相当于正无穷，最后去硬币的最小值即可，返回dp[amount]
        vector<int> dp(amount+1, amount+1);

        //对dp[0]的初始化非常重要，当amount为0时，硬币数也为0！！
        dp[0] = 0;
        // sort(coins.begin(), coins.end());
        // for(int i=0; i <= amount; i++){
        //     dp[i] = i;
        // }
        for(int i=0; i <= amount; i++){
            for(int j=0; j < coins.size(); j++){
                if(i - coins[j] >= 0){
                    dp[i] = min(dp[i-coins[j]]+1, dp[i]);
                }
            }
        }
        //有可能最小金额数很大，比如 【186,419,83,408】 amount = 6249 应该输出20而不是-1
        // if(dp[amount]%coins[0] != 0)
        //     return -1;
        // return dp[amount]/coins[0];

        return (dp[amount] == amount + 1) ? -1 : dp[amount];
		//凡是能取到最小的，都是和dp[coins[]]有关的，
		//比如coins={3,5,7}  dp[3],dp[0],dp[5],dp[7]或其倍数，dp[2],dp[4]都为amount+1，意为正无穷大，及不能刚好找开
    }
};

//《找零》：

#include <iostream>
#include <algorithm>
 
 
using namespace std;
 
int main(){
    int N;
    cin >> N;
    int rest;
    rest = 1024 - N;
    int money[] = {1, 4, 16, 64};  //有最小面值1元
     
    int dp[rest+1];
    for(int i=0; i <= rest; i++){
        dp[i] = i;
    }
    for(int i=0; i <= rest; i++){
        for(int j=0; j<4; j++){
            if(i - money[j] >= 0){
                dp[i] = min(dp[i-money[j]]+1 , dp[i]);
            }
        }
    }
    cout << dp[rest];
     
}