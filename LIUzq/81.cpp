//81. 搜索旋转排序数组 II 
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0) return false;
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right)/2;
            if(nums[mid] == target){
                return true;
            }
            //if(nums[mid] == nums[left]) left ++;   //这里没有考虑边界，数组会溢出
            if(nums[mid] == nums[left]){
                left ++;
                continue;
            }
            if(nums[mid] <= nums[left]){
                if(target > nums[mid] && target <= nums[right]){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
            else{
                if(target >= nums[left] && target <= nums[mid]){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
        }
        return false;
    }
};