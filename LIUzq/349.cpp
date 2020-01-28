//349 两个数组的交集

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        if(nums1.size() == 0 || nums2.size() == 0) return result; 
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        //int i = 0;
        for (int num1 : nums1){
            for(int num2 : nums2){
                if(num1 == num2){
                    result.push_back(num1);
                }
            }
        }
        vector<int>::iterator it = unique(result.begin(),result.end()); //删除重复的元素
        result.erase(it, result.end());
        return result;
    }
};
            // while(i < nums2.size()){  //这个为什么不行
            //     if(num == nums2[i]) {
            //     result.push_back(num);
            //     i++;
            //     }
            // i++;
            // }