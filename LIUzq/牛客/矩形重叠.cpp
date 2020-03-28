//矩形重叠的最大个数

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    //int dp[51];    //保存最大重叠的矩形个数
    //vector<int> x1, y1, x2, y2;
    int x1[n],y1[n],x2[n],y2[n];    //n还不知道是多少呢，应该先获取n的值！！
    //cin >> n;
    //scanf("%d", n);
    //scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &x1[i]);
    }
    for(int i=0; i<n; i++){
        scanf("%d", &y1[i]);
    }
    for(int i=0; i<n; i++){
        scanf("%d", &x2[i]);
    }
    for(int i=0; i<n; i++){
        scanf("%d", &y2[i]);
        //cin >> y2[i];            //y2.push_back(cin);
    }
    int cnt = 0;
    int ans = 0;
    for(int x : x1){
        for(int y : y1){
            for(int i=0; i<n; i++){
                if(x >= x1[i] && x < x2[i] && y >= y1[i] && y < y2[i]){
                    cnt ++;
                }
            }
            if(cnt > ans)
                ans = cnt;
            cnt = 0;
        }
    }
    printf("%d\n", ans);    //牛客是用cout的，不是return
}