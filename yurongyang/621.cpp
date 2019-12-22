class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> counter;
        int count = 0;
        for(auto i:tasks){
            counter[i]++;
            count = max(count,counter[i]);
        }

        int time_cons = (count -1)*(n+1);
        for(auto i:counter){
            if(i.second == count)
                time_cons++;
        }
        return max(time_cons, int(tasks.size()));
    }
};
