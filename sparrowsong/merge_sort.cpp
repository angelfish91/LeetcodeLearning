/*************************************************************************
#    > File Name: c.cpp
#    > Author: sparrowsong
#    > Mail: sparrowsong@tencent.com
#    > Created Time: 2020-03-18 21:56
#    > Last modified: 2020-03-18 21:56
# ************************************************************************/
#include<stdio.h>
#include<vector>
#include<map>

using namespace std;

vector<int> merge(vector<int>& vec0, vector<int>& vec1);

vector<int> merege_sort(vector<int>& vec, int st, int ed){
    vector<int> ans{};
    if(ed == st){
        return ans;
    }
    if((ed - st) == 1){
        ans.push_back(vec[st]);
        return ans;
    }
    if((ed - st) == 2){
        if(vec[st]<vec[st+1]){
            ans.push_back(vec[st]);
            ans.push_back(vec[st+1]);
        } else {
            ans.push_back(vec[st+1]);
            ans.push_back(vec[st]);
        }
        return ans;
    }

    int mid = (st+ed)/2;
    vector<int> vec0 = merege_sort(vec, st, mid);
    vector<int> vec1 = merege_sort(vec, mid, ed);
    return merge(vec0, vec1);
}

vector<int> merge(vector<int>& vec0, vector<int>& vec1){
    vector<int> ans;
    auto s0 = 0;
    auto s1 = 0;
    while(s0<vec0.size() or s1<vec1.size()){
        if(s0<vec0.size() && s1<vec1.size()){
            if(vec0[s0]<vec1[s1]){
                ans.push_back(vec0[s0]);
                s0++;    
            } else {
                ans.push_back(vec1[s1]);
                s1++;
            }
        }
        else if(s0>=vec0.size()){
            ans.push_back(vec1[s1]);
            s1++;
        }
        else if(s1>=vec1.size()){
            ans.push_back(vec0[s1]);
            s0++;
        }
    }
    return ans;
}



int main(){
    vector<int> vec{2, 3, 4, 1, 5};
    auto ans = merege_sort(vec, 0, int(vec.size()));
    for(int i: ans){
        printf("%d\t", i);
    }
    printf("\n");
}



