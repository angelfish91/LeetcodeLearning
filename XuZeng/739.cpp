class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n=T.size();
        vector<int> res(n,0);
        res[n-1]=0;
        for(int i=n-2;i>=0;i--){
            int temp=i+1;
            while(1){
                if(T[i]>=T[temp]){
                    if(res[temp]==0){
                        res[i]=0;
                        break;
                    }
                    else
                        temp+=res[temp];
                }
                else{
                    res[i]=temp-i;
                    break;
                }
            }
        }
        return res;
    }
};