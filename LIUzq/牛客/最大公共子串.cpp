//给定两个字符串，请编写代码，输出最长公共子串（Longest Common Substring），
//是指两个字符串中的最长的公共子串，要求子串一定是连续。



#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string str,str1,str2;
    cin >> str;
    //vector<char> vec1,vec2;
    int s = str.find(',');
    str1 = str.substr(0, s);
    str2 = str.substr(s+1);
    
    //int m = vec1.size();
    //int n = vec2.size();
    int m = str1.length();
    int n = str2.length();
    int dp[m + 1][n + 1];
    int res = 0;
    for(int i=0; i < m; i++){
        for(int j=0; j < n; j++){
            if(str1[i] == str2[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
                //res = max(res, dp[i+1][j+1]);
            }
            else
                dp[i+1][j+1] = 0;
            res = max(res, dp[i+1][j+1]);
        }
    }
    cout << res;
    return 0;
}