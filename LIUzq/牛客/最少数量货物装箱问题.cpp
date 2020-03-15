#include <iostream>
#include <vector>

using namespace std;

int main(){
    int X,ans;
    cin >> X;
    vector<int> dp(X+1, X+1); //初始化为正无穷，用X+1表示即可
    //for(int i=0; i<=X; i++);
      //  dp[i] = i;
    //dp[0] = 1;
    dp[0] = 0;        //初始化为0
    int thing[] = {3, 5, 7};
    for(int i=0; i<=X; i++){
        for(int j=0; j<3; j++){
            if(i - thing[j] >= 0){        //这里是if！！！不是while
                dp[i] = min(dp[i], dp[i-thing[j]]+1);
            }
        }
    }
    ans = (dp[X] == X+1) ? -1 : dp[X];
    cout << ans;
    return 0;
    
}