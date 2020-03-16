#include <bits/stdc++.h>

using namespace std;

//最大无非两种情况，三个数相乘，或者最大乘其他两数的和
int maxN(int a, int b, int c){
    //int m = a;
    int m1,m2;
    m1 = a * (b + c);
    m2 = b * a * c;
    //三个数如何求最大
    if(a <= b && c <= b){
        m1 = b * (a + c);     
    }
    if(a <= c && b <= c){
        m1 = c * (a + b);
    }
    if (m1 >= m2) return m1;
    else return m2;
}

int main(){
    int a,b,c;
    int M;
    cin >> a >> b >> c;
    
    M = maxN(a, b, c);
    cout << M;
    
}