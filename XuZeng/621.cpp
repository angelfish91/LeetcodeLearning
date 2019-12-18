class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> task_counts(26,0);
        int tasks_len = tasks.size();
        for(int i = 0;i<tasks_len;i++){
            task_counts[tasks[i]-'A']++;
        }
        sort(task_counts.begin(),task_counts.end(),greater<int>());
        int max_task_counts = task_counts[0];
        int index = 0;
        while(index < 26 && task_counts[index] == max_task_counts){
            index++;
        }
        int result = (max_task_counts - 1) * (n+1) + index;
        return max(result,tasks_len);
    }
};