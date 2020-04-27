//33. 搜索旋转排序数组

//正确答案
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() -1;
        
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (target == nums[mid]) return mid;

            if (nums[l] <= nums[mid])
            {
                if (target >= nums[l] && target < nums[mid])	//这里和mid的比较不用加=因为上面一旦相等就返回了
                    r = mid-1;
                else
                    l = mid+1;
            }
            else
            {
                if (target > nums[mid] && target <= nums[r])
                    l = mid +1;
                else
                    r = mid -1;
            }
        }
        return -1;
    }
};

//我的答案  参考上面的解答
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(target == nums[mid]) return mid;
            if(nums[left] <= nums[mid]){        //说明旋转点靠前，即较多数量较大的数字位于旋转后顺序的前面，例如 456701
                if(target <= nums[mid] && target >= nums[left]){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            else{
                if(target <= nums[right] && target >= nums[mid]){   //要考虑边界值 如[5 1 3] 找3
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};


//最强解答
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))   //注意这里的思路，仔细研究
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo == hi && nums[lo] == target ? lo : -1;
    }
};

作者：LukeLee
链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/ji-jian-solution-by-lukelee/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//错误解答
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        int left = 0;
        int right = nums.size() - 1;
        while(left < right){
            int mid = (left + right) / 2;
            if(target < nums[0]){  //说明在左半部分
                if((nums[0] > nums[mid] && target > nums[mid]) || (nums[0] > nums[mid] && target > nums[mid])){    //在左半部分的左半部分   
                    left = mid + 1;                  
                }
                else{
                    right = mid;
                }
            }
            else{                  //在右半部分
                if((nums[0] < nums[mid] && target > nums[mid]) || (nums[0] < nums[mid] && target > nums[mid])){         //右半部分的左半部分
                    left = mid + 1;
                }
                else{
                    right = mid;
                }
            }
        }
        return (left == right && nums[left] == target) ? left: -1;
    }
};

//错误代码，通过大部分测试用例，[1,3]查找3时这个测试用例未通过
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(target == nums[mid]) return mid;
            if(target <= nums[0]){
                if(target < nums[right] && nums[mid] > nums[0]){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
            else{
                if(target > nums[mid] && nums[mid] < nums[0]){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};