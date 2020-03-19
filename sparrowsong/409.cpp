/*************************************************************************
#    > File Name: 409.cpp
#    > Author: sparrowsong
#    > Mail: sparrowsong@tencent.com
#    > Created Time: 2020-03-19 23:50
#    > Last modified: 2020-03-19 23:50
# ************************************************************************/
#include<stdio.h>
#include<string>
#include<map>
#include<vector>
#include<iostream>

using namespace std;


class Solution {
public:
    int longestPalindrome(string s){
        map<char, int> helper;
        for(char c: s){
            helper[c]++;
        }
        int ans = 0;
        bool flag = false;
        for(auto it=helper.begin(); it!=helper.end();it++){
            if(it->second%2==0){
                ans += it->second;
            } else {
                
                ans += (it->second)/2*2;
                flag = true;
            }
        }
        ans = flag? ans+1: ans;
        return ans;
    }
};

int main(){
}
