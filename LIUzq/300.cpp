//300 最长上升子序列


//动态规划方法：复杂度很高，运算慢》
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //dp[i] 表示从0到i时最长上升子序列的长度。
        if(nums.empty()) return 0;
        int ans = 1;    //ans初始值应该为1而不是0！！！
        int dp[nums.size()] = {0};      //
        for(int i=0; i<nums.size(); i++){
            dp[i] = 1;
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
                ans = max(dp[i], ans);
            }
        }
        //sort(dp, dp+nums.size()-1);       //这里有问题，为什么换成ans就可以通过测试用例[1 3 6 7 9 4 10 5 6]答案是6却输出5.
        //应该是sort(dp, dp+nums.size())   偏移量是数组的长度！！
        //return dp[nums.size()-1];
        return ans;
    }
};

//还有一种方法，二分查找，时间复杂度O(nlogn);

