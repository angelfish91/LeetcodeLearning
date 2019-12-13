class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int len = pushed.size();
        stack<int> tamp;
        int index = 0;
        for(int i=0;i<len;i++){
            tamp.push(pushed[i]);
            while(!tamp.empty() && index<len && tamp.top()==popped[index]){
                tamp.pop();
                index++;
            }
        }
        if(tamp.empty()){
            return true;
        }else{
            return false;
        }
    }
};