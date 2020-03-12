//1071. 字符串的最大公因子
//【关于字符串的用法】【辗转相除法】【两个字符串拼接的思想】【注意除0的判断】
//substr(0, , ) 求子字符串
//
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int len = gcd(str1.length(), str2.length());
        string X = str1.substr(0, gcd(str1.length(), str2.length()));  //字符串的用法， substr(0, , )!!!子字符串
        if(check(X,str1) && check(X, str2))
            return X;
        else
            return "";

    }

private:
    bool check(string T, string s){
        if(T.length() == 0) return false;
        int n = s.length() / T.length();
        string ans = "";
        for(int i=1; i<=n; i++){
            ans += T;
        }
        return ans == s;
    }
    //辗转相除法求最大公约数
    int gcd(int a, int b){
        if(a % b == 0) return b;
        return gcd(b, a % b);
        //另一种方法
        //return (b == 0) ? a : gcd(b, a%b)
    }
};

//另一种方法：
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 == str2 + str1)      //拼接的思想，前面做题遇到过的！！！
            return str1.substr(0, gcd(str1.length(), str2.length()));
        return "";
    }
private:
    int gcd(int a, int b){
        return (b == 0) ? a : gcd(b, a % b);
    }
};

//枚举：【实际上就是求最大公约数】
//首先答案肯定是字符串的某个前缀，然后简单直观的想法就是枚举所有的前缀来判断，
//我们知道前缀串的长度必然要是两个字符串长度的【约数】才能满足条件，否则无法经过若干次拼接后得到长度相等的字符串,
//所以我们可以枚举符合长度条件的前缀串，再去判断这个前缀串拼接若干次以后是否等于 str1 和 str2 即可,
//由于题目要求最长的符合要求的字符串 X，所以可以按长度从大到小枚举前缀串，这样碰到第一个满足条件的前缀串返回即可。
