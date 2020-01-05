class Solution {
    vector<vector<int>> result;
public:
    vector<vector<int>> permute(vector<int>& nums) {
       vector<int> track;
       backtrack(nums,track); 
       return result;
    }
    void backtrack(vector<int> nums,vector<int> track) {
        if(nums.size() == track.size()){
            result.push_back(track);
            return;
        }
        for(int i = 0;i<nums.size();i++) {
            vector<int>::iterator it = find(track.begin(),track.end(),nums[i]);
            if(it != track.end()){
                continue;
            }
            track.push_back(nums[i]);
            backtrack(nums,track);
            track.pop_back();
        }
    }
};