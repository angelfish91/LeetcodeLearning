class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> temp;
        vector<int> results;
        for(int i=0; i<nums1.size();i++){
            if(find(nums2.begin(),nums2.end(),nums1[i]) != nums2.end()){
                temp.insert(nums1[i]);
            }
        }
        results.assign(temp.begin(),temp.end());
        return results;
    }
};
