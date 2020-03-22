/*************************************************************************
#    > File Name: 43.cpp
#    > Author: sparrowsong
#    > Mail: sparrowsong@tencent.com
#    > Created Time: 2020-03-20 00:33
#    > Last modified: 2020-03-20 00:33
# ************************************************************************/
#include<stdio.h>
#include<string>
#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string a, b;
        if(num1.size() > num2.size()){
            b=num1, a=num2;
        } else {
            a=num1, b=num2;
        }
        int ans = 0;
        for(int i=0;i<a.size();i++){
            int tmp = 0;
            for(int j=0; j<b.size(); j++){
                int aa = a[a.size()-i-1]-'0';
                int bb = b[b.size()-j-1]-'0';
                tmp += aa*bb*pow(10, j);
            }
            ans += tmp*pow(10, i);
        }
        return to_string(ans);
    }
};

int main(){
    Solution ss;
    printf("%s\n", ss.multiply("3", "3").c_str());
    printf("%s\n", ss.multiply("10", "11").c_str());
    printf("%s\n", ss.multiply("1", "11").c_str());
    printf("%s\n", ss.multiply("20", "2").c_str());
    printf("%s\n", ss.multiply("21", "2").c_str());
    printf("%s\n", ss.multiply("2", "20").c_str());
}
