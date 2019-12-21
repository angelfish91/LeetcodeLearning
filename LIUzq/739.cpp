//执行效率不高，击败5%的人，需要优化
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> day;
        for(int i=0; i < T.size(); i++){
            for(int j=i; j < T.size(); j++){
                if(T[i] < T[j]){
                    day.push_back(j-i);
                    break;
                }
                if(j == T.size()-1 ) {
                    day.push_back(0);
                    break;
                }
            }
        }
        return day;
        
    }
};

//优化代码：
