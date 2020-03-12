//1013.将数组分成和相等的三部分

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        if(A.size() < 3) return false;
        int sum = 0;
        for(int i=0; i<A.size(); i++){
            sum += A[i];
        }
        int sum13 = 0;
        int sum23 = 0;
        //int sum33 = 0;      //不需要求第三部分的和了，总的都求出来了
        for(int i=0; i < A.size(); i++){          
            if(3*sum13 == sum && i>0){     //而是这里的错，和为0的sum，一进来还没加就判断相等了。。。
                sum23 += A[i];
                if(i == A.size()-1) return false;   //并不是这里的错
                if(sum23 == sum13 && i < A.size()-1){     //对于[1,-1,1,-1]这种情况，到这里不能直接返回true的，因为没有了第三部分，需要添加限制条件,也不是这里的错
                    return true;
                }
                continue;
            }
            sum13 += A[i];
            if(i > A.size()-3) return false;
        }
        return false;
    }
};