//计算字符串最后一个单词的长度，单词以空格隔开。
#include<iostream>
#include<string>
using namespace std;

int main()
{   
    string str;
    int count = 0;
    int flag = 1;
    getline(cin, str);
    for(int i = str.length() - 1; i >= 0; i--)  //数据从0开始所以：int i = str.length() - 1; i >= 0;
    {
        if(flag == 1 && str[i] == ' ') //预防最后有空格
            continue;
        if(flag == 1 && str[i] != ' ')
        {
            flag = 0;
            count++;
            continue;
        }
        if(flag == 0 && str[i] == ' ')
            break;
        count++;
    }
    cout << count;
}
