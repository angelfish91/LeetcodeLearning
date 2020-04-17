55 跳跃游戏

//未通过
考虑不周到   [1,0,1,0]应该判断i和rightMax的大小关系，i和rightMax要同时更新
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty()) return false;
        int rightMax = 0;
        for(int i = 0; i < nums.size() - 1; i++){   //算到倒数第二位，最后一位不算，是终点
            rightMax = max(rightMax, nums[i] + i);
            if(rightMax >= nums.size() - 1)  return true;
            if(rightMax  == 0 && i != nums.size() - 1) return false;    //针对[0,2,3],在前面就走不动的情况
        }
        if(rightMax < nums.size() - 1)  return false;
        return true;
    }
};

//参考官方

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty()) return false;
        int rightMax = 0;
        for(int i = 0; i < nums.size(); i++){   //算到倒数第二位，最后一位不算，是终点（X）
//		不对，有i和rightMax限制条件，不应该是i只算到倒数第二位
            if(i <= rightMax){
                rightMax = max(rightMax, nums[i] + i);
                if(rightMax >= nums.size() - 1) return true;
            }
            else return false;
        }
        return false;
    }
};