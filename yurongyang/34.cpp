class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        if(nums.size()==0)
            return {-1,-1};
        int left = 0;
        int right = nums.size()-1;
        int mid_f = 0;
        //查找目标位置，决定搜索范围
        while(left<=right){
            mid_f = (left+right)/2;
            if(nums[mid_f]>target){
                right = mid_f-1;
            }else if(nums[mid_f]<target){
                left = mid_f +1;
            }else
                break;
        }
        if(nums[mid_f] != target) return{-1,-1};
 
        //寻找左边界
        left = 0;
        right = mid_f;
        while(left<right){
            int mid= (left+right)/2; 
            if(nums[mid]!=target){
                left = mid+1;
            }else
                right=mid;
        }
        res.push_back(right);
        //寻找右边界
        left = mid_f;
        right = nums.size()-1;
        while(left<right){
            int mid= (left+right)/2+1;
            cout<<mid<<endl;
            if(nums[mid]!=target){
                right = mid-1;
            }else
                left=mid;
        }
        res.push_back(left);
        return res;
    }
};
