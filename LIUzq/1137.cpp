//第 N 个泰波那契数

class Solution {
public:
	//定义数组的方式：
	//int * temp = new int[38];
	//这里要给temp数组附初值，（用for循环）
    int temp[38];
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 1;
		//需要建立缓存区保存已经计算过的数据，不然会运行超时！！！！
        if(n > 2 && temp[n] != 0)
            return temp[n];
        while(n <= 37){
            temp[n] = tribonacci(n-3) + tribonacci(n-2) + tribonacci(n-1);
            return temp[n];
        }
        return 0;
    }
};