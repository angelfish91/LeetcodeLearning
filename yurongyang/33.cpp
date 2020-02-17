class Solution {
public:
    
    int search(vector<int>& nums, int target) {
       
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while(left<=right){
            mid = (left+right)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid]<nums[right]){ //右边有序
                if(target>nums[mid]&&target<=nums[right]){
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }else{//左边有序
                if(target>=nums[left]&&target<nums[mid]){
                    right = mid - 1;
                }else{
                    left = mid+1;
                }
            }
        }
        return -1;
    }
};
