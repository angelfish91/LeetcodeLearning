class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp_str);
        string res = "";
        for(auto num:nums){
            res+= to_string(num);
        }
        if(res[0]=='0') return "0";
        return res;
    }
    static bool cmp_str(int a,int b){
        string str1 = to_string(a);
        string str2 = to_string(b);
        string tmp = str1;
        str1 += str2;
        str2 += tmp;
        return str1>str2;
    }
    
};
