//任务调度器
bool cmp(int &a, int &b){
    return a > b;
}

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(!n) return tasks.size();
        vector<int> nums(26,0);
        for(auto ch: tasks){
            nums[ch - 'A'] += 1;
        }
        sort(nums.begin(), nums.end(), cmp);

        int count = (nums[0] - 1) * (n + 1);
        for(int i=0; i < nums.size(); i++){ //不是 tasks.size()！
            if(nums[i] == nums[0])
            count ++;
        }
        return count < tasks.size() ? tasks.size() : count; 
    }
};