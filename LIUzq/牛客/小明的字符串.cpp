有几点注意：
// #include "stdafx.h"  这个是包含很多头文件的
//cout << i << ' '; 后面不加一个空格的话输出很有可能不对，会连到一起，加endl也行，看要不要换行了。
//关于string的操作，需要熟悉
//

#include <bits/stdc++.h>

using namespace std;

void operate1Str(string &str, int N, int X){ //这种方法效率很低
    string s = "";
    for(int i = N-X; i < N; i++){
        s += str[i];
    }
    for(int i = 0; i < N-X; i++){
        s += str[i];
    }
    str = s;
}
void operate2Str(string &str, int X){
    cout << str[X] << endl;   //就是因为没加 endl，导致字符连到了一起或者用
    //cout << str[X] << ' ';加个空格
}

int main(){
    int N,T,TYPE,X;
    string str;
    cin >> N >> T;
    cin >> str;
    for(int i = 0; i < T; i++){
        cin >> TYPE >> X;
        if(TYPE == 1){
            operate1Str(str,N, X);
            //str = str.substr(N-X) + str.substr(0, N-X);    //这种方法效率高。
        }
        if(TYPE == 2){
            operate2Str(str, X);
        }
    }

}

