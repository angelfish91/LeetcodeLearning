3 无重复长度的最长子串

//想法有点跑偏，不应该是clear（），没有想到滑动窗口这个思路
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt = 0;
        unordered_set<char> us;
        us.insert(s[0]);
        for(int i = 1; i < s.length(); i ++){
            if(!us.count(s[i])){    //没找到，说明不重复
                us.insert(s[i]);
                cnt ++;
            }else{
                us.clear();
            }
        }
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt = 0;
        unordered_set<char> us;
        int length = s.length();
        //右指针初始化为-1，表示还没开始移动，在左指针之前
        int r = -1, ans = 0;

        //隐式表示左指针的移动
        for(int i = 0; i < length; i ++){
            if(i != 0){
                us.erase(s[i - 1]);
            }
            while(!us.count(s[r + 1]) && r + 1 < length){	//注意这里r的判断条件
                us.insert(s[r + 1]);
                r ++;
            }
            ans = max(ans, r - i + 1);
        }
        return ans;
    }
};