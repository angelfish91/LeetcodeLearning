11 盛最多水的容器


//超时
//有大量的重复运算，基本思想是，用两层从第一个开始挨个遍历比较当前位置能存水的最大量
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        if(n < 2) return 0;
        //dp[i]表示到第i个线为止，最大的容量
        //也可以用一个变量保存最大的值，实时更新即可
        //int dp[n] = {0};
        int dp = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                dp = max(dp, min(height[i], height[j]) * (j - i));
            }
        }
        return dp;
    }
};

//双指针解法（【滑动窗口】）
从左右两边开始，往里面缩小加入左边的矮，就L++，否则R--。官方有证明，指向矮的指针移动后才有可能容积变大
如果移动高的那个指针，容积肯定不会增加
这个题可以理解为，这两个指针是容器的边界，里面其他的都不管，指针在变容积在变！
【note里收录了一个精选题解，讲的很有道理】
（实际上消去了暴力法中一些对结果无用的状态（比目前容积小的就不用算了））
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        if(n < 2) return 0;
        int maxV = 0;
        int L = 0;
        int R = n - 1;
        while(L < R){
            maxV = max(maxV, min(height[L], height[R]) * (R - L));
            if(height[L] <= height[R]) L ++;
            else R --;
        }
        return maxV;
    }
};