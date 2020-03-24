按摩师的最长预约时间

class Solution {
public:
    int massage(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        //if(nums.size() == 2) return max(nums[0], nums[1]);  //dp【1】已经去了最值了
        //int dp[nums.size()+1] = {0};        //数组不能这么申请空间，必须是确切的数字？
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        //dp[1] = nums[1];      //dp是保存第i个接的情况下最长时间，这里应该去最值
        dp[1] = max(nums[0], nums[1]);
        
        for(int i=2; i<nums.size(); i++){
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[nums.size()-1];
    }
};