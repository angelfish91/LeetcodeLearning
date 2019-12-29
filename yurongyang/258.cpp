class Solution {
public:
    int addDigits(int num) {
    int result = 0;
        if(num/10==0)
            return num;
        while(num){  
            result+=num%10;
            num = num/10;
        }
    return addDigits(result);
    }
};
