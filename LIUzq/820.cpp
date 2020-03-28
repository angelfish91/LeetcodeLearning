单词的压缩编码

//错误解答：对题目理解出错

class Solution {
public:
//这里的字符串不一定是前后两个比较，
//反而应该理解为一个字典里面，一个字符串是否包含其他字符串
该解答通过了部分测试用例23/30；

    int minimumLengthEncoding(vector<string>& words) {
        int count = 0;
        int ans = 0;
        //ans = words[0].length() + 1;
        for(int i = 1; i < words.size(); i++){
            //ans += words[i-1].length + 1;   // 这里每次都会加，错，去掉该语句

            if(words[i].length() > words[i-1].length()){    //对题目的理解有点问题，和前后的顺序没有关系
                ans += words[i].length() + 1;   
                continue;
            }
            tranverse(words[i]);
            tranverse(words[i-1]);
            if(!cmpSame(words[i-1], words[i])){     //如果从头开始比较，s2不在s1中，则执行下面语句。
                ans += words[i].length() + 1;
            }           
        }
        return ans;
    }
private:
    void tranverse(string &s){      //反转字符串 time -> emit , me -> em
        string tmp;
        for(int i = s.length() - 1; i >= 0; i--){
            tmp += s[i];
        }
        s = tmp;
    }
    bool cmpSame(string s1, string s2){ //比较s1和s2两个字符串，s2是否在s1中（如emit，em）s1，s2无长短之分
        bool isSame = true;
        // for(int i = 0; i < s1.length(); i++){
        //     for(int j = i; j < s2.length(); j++){
        //         if(s1[i] != s2[j]){
        //             isSame = false;
        //         }
        //     }
        // }
		【注意这里for循环的用法！！】
        for (int i = 0, j = 0; i < s1.length() && j < s2.length(); i++, j++) {
            if (s1[i] != s2[j]) {
                isSame = false;
                return isSame;
            }
        }
        return isSame;
    }
};

所以我们只要找到单词列表里，哪些单词被别的单词的后缀给包含了就可以了。
这题很明显是用字典树来做的。为什么很明显呢？后面我们来解释。

【字典树解法见题解】
需要学习




//不用字典树，用常规解法：
//反转+排序的解题方法
//其实这道题我们的思路很简单：如果有一对单词 s 和 t，使得 t 是 s 的后缀，
//例如 me 是 time 的后缀，我们就删掉单词 t。最后剩下来的单词，就是构成索引字符串的单词。

作者：nettee
链接：https://leetcode-cn.com/problems/short-encoding-of-words/solution/wu-xu-zi-dian-shu-qing-qing-yi-fan-zhuan-jie-guo-j/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        vector<string> reversed_word;
        for(string word : words){
            reverse(word.begin(), word.end());		【将每个单词反转】
            reversed_word.emplace_back(word);		【emplace_back的用法】
        }
        //字典序排序
		【注意这种新的用法】
        sort(reversed_word.begin(), reversed_word.end());

        int ans = 0;
        for(int i = 0; i < words.size(); i++){
            if(i+1 < words.size() && reversed_word[i+1].find(reversed_word[i]) == 0){	【find函数，找当前字符串是不是在下一个字符串的一部分】
                //当前单词是下一个单词的前缀（一部分），丢弃
            }
            else{
                ans += reversed_word[i].length() + 1;
            }
        }
        return ans;
    }
};