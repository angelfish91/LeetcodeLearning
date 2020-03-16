//字符串压缩，注意字符串的拼接    s = s+'a' 和s += 'a'是不一样的
//和int转字符 to_string的应用，也可以用
//char c = (char)(count + '0');

class Solution {
public:
    string compressString(string S) {
        if(S.length() == 0) return S;
        string ans;
        int count = 1;
        char tmp = S[0];

        for(int i = 1; i < S.length(); i++){
            if(tmp == S[i]){
                count ++;
            }
            else{              
                ans += tmp + to_string(count);
                tmp = S[i];
                count = 1;
            }
        }
        ans += tmp + to_string(count);
        //ans = ans + tmp + to_string(count);     //还差最后一个，for循环里if判断完了但是没加进去
        //这道题还要考虑内存限制的问题，会出现超出内存限制错误
        //这个涉及到c++字符串拼接的问题，s = s + 'A'会产生一个新的对象，在返回结果给s，s += 'A'应该是涉及到对象的引用，不需要产生额外的对象，因此s = s + 'A'在每次拼接时都产生额外的对象占用内存.
        return (ans.length() < S.length()) ? ans : S;
    }
};