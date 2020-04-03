字符串转换为整数

【学习：
		遍历字符串的新方法，用while
		isdigit函数的使用（用来判断是不是数字）
		】
// #define INT_MAX pow(2.0,31) -1    已经定义好了
// #define INT_MIN -pow(2.0,31)
class Solution {
public:
    int myAtoi(string str) {
        int flag = 1;
        int ans = 0;
        int i = 0;
        while(str[i] == ' '){i++;}  //跳过空格字符
        if(str[i] == '-'){flag = -1;}   //有负号，
        if(str[i] == '+' || str[i] == '-') {i++;}  //下一个字符
        while(i < str.size() && isdigit(str[i])){   //判断是不是数字， 数字不连续就停止录入
            int num = str[i] - '0';
            if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && num > 7)){ //2^31 -1 = 2,147,483,647
                return flag > 0 ? INT_MAX : INT_MIN;
            }
            ans = ans * 10 + num;
            i++;
        }
        return flag > 0 ? ans : -ans;
    }
};