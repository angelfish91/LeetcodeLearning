class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() == 0)
            return true;
        stack<int> tmp;
        int j=0;
        for(int i=0;i<pushed.size();i++){
            tmp.push(pushed[i]);
            while(!tmp.empty() && tmp.top() == popped[j]){
                tmp.pop();
                j++;
            }
        }
        if(!tmp.empty() && j<popped.size()){
            return false;
        }
        return true;
    }
};
