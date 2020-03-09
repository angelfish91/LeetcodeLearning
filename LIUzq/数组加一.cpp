//LeetCode探索里面的题目
//关于数组和字符串
//《加1》:
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        bool rise = false;
        for(int i=digits.size()-1; i>=0; i--){       //考虑不周全，i>0;没考虑输入为
            if(digits[i] < 9){
                digits[i] ++;
                //尾数小于9，加完1就直接终止
                break;
            }
            else{
                digits[i] = 0;
                if(i == 0)
                    rise = true;
                continue;
            }
        }
        for(int i=0; i<digits.size(); i++){
            if(rise){   //这里rise只用一次，应该马上复位
                res.push_back(1);
                rise = false;
            }
                
            res.push_back(digits[i]);
        }
        return res;
    }
};