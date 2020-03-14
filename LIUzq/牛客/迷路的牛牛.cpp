//迷路的牛牛


#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    string str;
    int N;
    cin >> N;
    cin >> str;
    int count = 0;        //起始方向为北 == 0
    int num = 0;
    //unordered_map<char,int> umap;
    for(int i = 0; i < N; i++){
        if(str[i] == 'L')
            count ++;
        else
            count --;
    }
    if(count >= 0){
        num = count % 4;
    }else num = 4 - abs(count%4);			//避免结果为负数，可以(count+4)%4,一步到位，即使是正数也不影响！！
    switch(num){				//用这种方法代码很长，实际上用一个字符数组即可，如 num[4] = {'N','W','S','E'};
        case 0:
            cout << 'N';
            break;				//【注意每行都要加！！！】不然后面的都会输出！
        case 1:
            cout << 'W';
            break;
        case 2:
            cout << 'S';
            break;
        case 3:
            cout << 'E';
            break;
        default:
            break;
    }
    return 0;
}