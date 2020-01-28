//可选择排序后做判断，但是效率较低。此处利用字母最多26个的特点，用数组模拟map来判断每个字母的个数
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        int i;
        int x[26] = {0};
        int y[26] = {0};
        for(i=0;s[i] !='\0';i++)
            x[s[i] - 'a']++;
        for(i=0;t[i] !='\0';i++)
            y[t[i] - 'a']++;
        for(i=0;i<26;i++){
            if(x[i] != y[i])
                return false;
        }
        return true;
    }
};
