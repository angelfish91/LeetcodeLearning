使数组唯一的最小增量


//计数法：
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int temp[A.size() + 40000] = {0};
        int ans = 0;
        int count = 0;          //记录一共有多少个数重复，
        for(auto x : A){
            temp[x] ++;
        }
        for(int i=0; i<A.size() +  40000; i++){ //  遍历整个temp
            if(temp[i] > 1){
                count += temp[i] - 1;
                ans -= (temp[i] - 1) * i;   //  先把ans减去temp[i] - 1个 i，再在后面加上需要执行的操作次数
            }
            else if(count > 0 && temp[i] == 0){
                count --;       //一直到count == 0，即所有数都不重复为止
                ans += i;       //前面ans已经减去了那么多个i，变成了初始值（可以理解为变成了1），这里加上i*1；
            }
        }
        return ans;
    }
};



//既然已经排好序了就直接改变A数组即可，让后面的每个数变为前面的数+1，
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        int ans = 0;
        //int count = 0;
        // for(int i=1; i<A.size(); i++){       //欠考虑，没有考虑 [1 1 2 2 3 7] -> [1 2 3 2 3 7],如果只是判断前后两个不同的话是不行的
        //     if(A[i] == A[i-1]){
        //         //count ++;
        //         A[i] = A[i-1] + 1;
        //         ans ++;
        //     }
        // }
        for(int i=1; i<A.size(); i++){
            if(A[i] == A[i-1]){
                A[i] = A[i-1] + 1;
                ans ++;
            }
            if(A[i] < A[i-1]){
                ans += A[i-1] - A[i] + 1;
                A[i] = A[i-1] + 1;               
            }
        }
        return ans;
    }
};
