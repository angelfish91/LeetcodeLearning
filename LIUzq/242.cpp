//242 有效的字母异位词
//方法一： 简单粗暴，一次成型
//缺点：显而易见 耗内存耗时。
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> ss;
        vector<int> tt;
        for(char s1 : s){
            ss.push_back(s1 - 'a');
        }
        for(char t1 : t){
            tt.push_back(t1 - 'a');
        }
        sort(ss.begin(), ss.end());
        sort(tt.begin(), tt.end());
        for(int i=0; i< ss.size(); i++){
            if(ss[i] != tt[i])  return false;
        }
        return true;
    }
};

//方法二：
//解题方案
// 思路
// 标签：哈希映射
// 		首先判断两个字符串长度是否相等，不相等则直接返回 false
// 		若相等，则初始化 26 个字母哈希表，遍历字符串 s 和 t
// 		s 负责在对应位置增加，t 负责在对应位置减少
// 		如果哈希表的值都为 0，则二者是字母异位词
// 作者：guanpengchn
// 链接：https://leetcode-cn.com/problems/valid-anagram/solution/hua-jie-suan-fa-242-you-xiao-de-zi-mu-yi-wei-ci-by/
// 来源：力扣（LeetCode）
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        //int *temp = new int[26];   //数组不可以，
        vector<int> temp(26);   //初始化vector 26个
        for(char s1 : s){
            temp[s1 - 'a'] ++;
        }
        for(char t1 : t){
            temp[t1 - 'a'] --;
            if(temp[t1 - 'a'] < 0)  
                return false;
        }
        //  for(int i=0; i<temp.size(); i++){
        //      if(temp[i] != 0) return false;
        //  }    //多余
        return true;
    }
};


//其他方法：
//排序：
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

//哈希表（最优解）
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<int, int> umap;
        for (char ch : s) {
            ++umap[ch];
        }
        for (char ch : t) {
            if (umap[ch] > 0) {
                --umap[ch];
            } else {
                return false;
            }
        }
        return true;
    }
};
//另一种解法：
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> umap;
        for (int i = 0; i < s.size(); ++i) {
            ++umap[s[i]];
            --umap[t[i]];
        }
        for (auto c : umap) {
            if (c.second != 0) {
                return false;
            }
        }
        return true;
    }
};
//vector模拟哈希表
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        vector<int> hash(26);
        int size = s.size();
        for (int i = 0; i < size; ++i) {
            ++hash[s[i] - 'a'];
            --hash[t[i] - 'a'];
        }
        for (int n : hash) {
            if (n != 0) {
                return false;
            }
        }
        return true;
    }
};

作者：guohaoding
链接：https://leetcode-cn.com/problems/valid-anagram/solution/242-you-xiao-de-zi-mu-yi-wei-ci-liang-chong-fang-f/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

