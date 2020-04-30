202 快乐数


利用unordered_map 记录出现过的数字
c++不像java里的hashset，那么智能
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> us;
        us[n] ++;
        while(n != 1){
            n = sumNum(n);
            us[n] ++;
            if(us[n] > 1){    //再次出现说明开始循环，返回false
                return false;
            }
        }
        return true;
    }
private:
    int sumNum(int x){
        int sum = 0, cur = 0;
        while(x > 0){
            cur = x % 10;
            sum += cur * cur ; //取个位
            x = x / 10; //去个位
        }
        return sum;
    }
};

方法：使用【“快慢指针”】思想找出循环：
【“快指针”每次走两步，“慢指针”每次走一步，当二者相等时，即为一个循环周期】。
此时，判断是不是因为1引起的循环，是的话就是快乐数，否则不是快乐数。

注意：此题不建议用集合记录每次的计算结果来判断是否进入循环，因为这个集合可能大到无法存储；
另外，也不建议使用递归，同理，如果递归层次较深，会直接导致调用栈崩溃。
【】不要因为这个题目给出的整数是int型而投机取巧。
class Solution {
public:
    int bitSquareSum(int n) {
        int sum = 0;
        while(n > 0)
        {
            int bit = n % 10;
            sum += bit * bit;
            n = n / 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        int slow = n, fast = n;
        do{
            slow = bitSquareSum(slow);
            fast = bitSquareSum(fast);
            fast = bitSquareSum(fast);
        }while(slow != fast);
        
        return slow == 1;
    }
};
作者：linux-man
链接：https://leetcode-cn.com/problems/happy-number/solution/shi-yong-kuai-man-zhi-zhen-si-xiang-zhao-chu-xun-h/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。