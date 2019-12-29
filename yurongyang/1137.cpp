class Solution {
public:
    int tmp[38]={0};
    int tribonacci(int n) {
        if(n==0 || n==1 || n==2){
            return n==0?0:1;
        }
        if(n>2 && tmp[n] !=0){
            return tmp[n];
        }
        if(n<=37){
            tmp[n] = tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
            return tmp[n];
        }
        return 0;
    }
};
