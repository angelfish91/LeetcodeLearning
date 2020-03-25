//【思路】
做这个题要先看懂《剑指Offer》之变态跳台阶
变态跳台阶：https://blog.csdn.net/qq_37375427/article/details/85093644
本题与变态跳台阶的本质区别就是规定了一次跳台阶的数目为2的n次幂，而且给的测试用例的结果较大，
需要对动态规划的每个结果取模，不能只求最后一次结果的模，不然会超范围。
————————————————
版权声明：本文为CSDN博主「我是大龙啊」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_42809993/article/details/98873780



#include <bits/stdc++.h>

using namespace std;

int main(){
    int M;
    vector<int> stairs(M, 0);
    vector<long long> dp(1001, 0);
    vector<int> p = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    
    cin >> M;
    for(int i=0; i<M; i++){
        cin >> stairs[i];
    }
    
    //这里其实在没有输入前就已经有了答案，所以在打印结果的时候只需要根据对应的值打印即可，也就有了另外一种打印方式
	//见另外一种解答方式
    dp[0] = dp[1] = 1;    //初始化前两个
    for(int i=2; i<1001; i++){        //这里i从2开始而不是0！！！
        for(int j=0; j<p.size(); j++){
            if(i - p[j] >= 0){
                dp[i] += dp[i - p[j]];
                //dp[i] %= 1000000000 + 3;
            }
        }
        dp[i] %= 1000000000 + 3;    //这里也是可以的，不需要每次都去计算，增加运算量  这里根据题目要求
    }
    //while(M --) {
        for(int i=0; i<M; i++){
            cout << dp[stairs[i]] << endl;
        }
    //}
    return 0;
}

//这种输出方式也可：
    // while(M --){
        // cin >> N;
        // cout << dp[N] << endl;
    // }

//另一种解答方式（输出方式）：

#include<iostream>
#include<vector>
 
using namespace std;
 
int main(){
 
    vector<int> p = {1,2,4,8,16,32,64,128,256,512};
    vector<long long> dp(1001,0);
    dp[0] = 1;
    for (int i = 1; i < dp.size();i++){			//这里是从1开始的，dp[1]的初值为0，和上面的解法有点稍微的差别
        for (int j = 0; j < p.size();j++){
            if (i >= p[j]){
                dp[i] = dp[i] + dp[i - p[j]];
                dp[i] %= 1000000003LL;
            }
        }
    }
	
	//【关注这种方式】
    int T;
    std::cin >> T;
    for (int n; T--; std::cout << dp[std::cin >> n, n] << std::endl) {}
    return 0;
}