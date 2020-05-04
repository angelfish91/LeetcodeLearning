45 跳跃游戏II

贪心算法，每次找局部最优，最后达到全局最优

class Solution {
public:
    int jump(vector<int>& nums) {
        int rightMax = 0, step = 0, end = 0;
        for(int i = 0; i < nums.size() - 1; i++){  //最后一个就不需要跳了
            rightMax = max(rightMax, nums[i] + i); //能到达的最右边
            if(i == end){   //遇到边界就更新边界，步数加一
            //每次找到局部最优，直到达到全局最优
                end = rightMax;
                step ++;
            }      
        }
        return step;
    }
};