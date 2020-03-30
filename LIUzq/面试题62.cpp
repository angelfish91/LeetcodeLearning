圆圈中最后剩下的数字

//【不能用处理约瑟夫问题的循环队列来处理本题，会超时，因为数组的删除操作会占用大量时间vector是不行的，
//java里的有些貌似可以，题解里有人做过尝试
class Solution {
public:
    int lastRemaining(int n, int m) {
        int ans = 0;
        //从剩余两个数字开始倒退，编号即为数字
        for(int i = 2; i <= n; i++){
            ans = (ans + m) % i;
        }
        return ans;
    }
};