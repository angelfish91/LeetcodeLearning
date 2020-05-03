53 最大子序和


//动态规划问题（并没有想出程序该怎么写...） 还是不熟练，记忆不深刻
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int sum = 0;
        for(int &num : nums){
            sum = max(sum + num, num);
            ans = max(ans, sum);
        }
        return ans;
    }
};