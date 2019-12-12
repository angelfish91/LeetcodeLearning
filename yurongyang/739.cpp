class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int size = T.size();
        vector<int> res(size);
        stack<int> tmp;
        for(int i=size-1;i>=0;i--){
            while(!tmp.empty() && T[i]>=T[tmp.top()]){
                tmp.pop();
            }
            if(tmp.empty()){
                res[i] = 0;
            }else{
                res[i] = tmp.top()-i;
            }
            tmp.push(i);
        }
        return res;
    }
};
