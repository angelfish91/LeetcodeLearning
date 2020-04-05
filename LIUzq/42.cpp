接雨水【困难】

【暴力解法】
class Solution {
public:
    int trap(vector<int>& height) {
        //直观想法：每个储水量为左右两边最大值中较小的那个减去当前高度
        int ans = 0;
        int size = height.size();	//必须要用size，在height为空的情况下，size为int型，值为0.
        for(int i = 1; i < size-1; i++){	//这里不能用height.size(),如果height为空的话，height.size()是0 吗？？好像不是，
            int max_left = 0;
            int max_right = 0;
            for(int j = i; j >= 0; j--){
                max_left = max(max_left, height[j]);
            }
            for(int j = i; j < size; j++){
                max_right = max(max_right, height[j]);
            }
            ans += min(max_left, max_right) - height[i];
        }
        return ans;
    }
};

【动态规划】：加入dp数组

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int size = height.size();
        if(size < 1) return 0;
        //这里要申请空间，所有size必须要有值
        int dp_left[size], dp_right[size];  //保存i左右两边的最大值，相比方法1省掉一层循环
        //漏了这步初始化
        dp_left[0] = height[0];
        for(int i = 1; i < size - 1; i++){
            dp_left[i] = max(dp_left[i-1], height[i]);
        }
        dp_right[size-1] = height[size-1];
        for(int i = size - 2; i > 0; i--){
            dp_right[i] = max(dp_right[i+1],height[i]);
        }
        for(int i = 1; i < size-1; i++){
            ans += min(dp_right[i], dp_left[i]) - height[i];
        }
        return ans;
    }
};