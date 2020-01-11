class Solution {
public:
    static bool allZero(vector<int> nums){
        for (auto a : nums){
            if(a != 0) return false;
        }
        return true;
    }
    string largestNumber(vector<int>& nums) {
        if(allZero(nums)) return "0";
        sort(nums.begin(), nums.end(), [](const int x, const int y) {
		string first = to_string(x) + to_string(y);
		string second = to_string(y) + to_string(x);
		return first > second;
	    });
        string res;
        for (auto a : nums) {
            res += to_string(a);
        }
        return res;
    }
};