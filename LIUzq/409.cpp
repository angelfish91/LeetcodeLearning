最长回文串


//思考不严谨，并不是奇数个就不用了，用最大数的放到中间，而是除了1个的，其他的可以使用偶数个，留一个不用， count += it->second / 2 * 2;
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> um;
        //int c1 = 0;         //每次初始化都最好=0，不然会报错
        int maxo = 0;
        int count = 0;
        for(char ch : s){
            um[ch] ++;
        }
        for(auto it = um.begin(); it != um.end(); it++){
            //偶数都可以用，奇数个只能取最大个数（错误，奇数个可以留一个不用，用偶数个）
            //if(it->second % 2 == 0){

                count += it->second / 2 * 2;
            //}

            if(it->second % 2 != 0 && count % 2 == 0){
                count ++;
            }
            // if(it->second % 2 == 0){
            //     count += it->second;
            // }
            // else if(it->second % 2 != 0 && it->second != 1){
            //     maxo = max(maxo, it->second);
            // }
            // if(it->second == 1){        //注意这个也是满足上一条条件的，会重复计算
            //     c1 ++;
            // }
        }
        //count += maxo;
        //if(c1 > 0) count ++;

        return count;
    }
};

//另一种方法： 既然只有一个奇数个数被使用，找出所有奇数个数字母出现的次数n即可（因为留下来的刚好是n个1，）
class Solution {
public:
    int longestPalindrome(string s) {
        int count = 0;
        unordered_map<char, int> um;    //为了省内存，可以用int数组保存,把字符串的字符转为int型保存进数组即可
        for(auto ch : s){
            um[ch]++;
        }
        for(auto it =  um.begin(); it != um.end(); it++){
            count += it->second % 2;
        }
        return (count == 0) ? s.length() : (s.length() - count + 1);
    }
};