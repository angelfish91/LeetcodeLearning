//34. 在排序数组中查找元素的第一个和最后一个位置

////超出内存限制：
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {        
        vector<int> temp;
        if(nums.size() == 0){
            temp.push_back(-1);
            temp.push_back(-1);
            return temp;
        }
        vector<int> result;
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right)/2;
            if(target < nums[mid]){
                right = mid - 1;
                continue;
            }
            if(target > nums[mid]){
                left = mid + 1;
                continue;
            }
            if(target != nums[mid]){
                 temp.push_back(-1);
                 temp.push_back(-1);
            return temp;
            }
            while(target == nums[mid]){
                if(target < nums[mid+1]){
                    temp.push_back(mid);
                }
                else{
                    temp.push_back(++mid);
                }
            }
            sort(temp.begin(), temp.end());
            result.push_back(temp.front());    //不能用begin（）和end（）
            result.push_back(temp.back());
            return result;
            //怎么对vector排序，怎么知道temp已经存好数据了
        }
        return temp;
    }
};

//正确解法：
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {        
        vector<int> temp = {-1,-1};
        if(nums.size() == 0){
            return temp;
        }
        temp[0] = low_bound(nums, target);
        temp[1] = high_bound(nums, target);
        return temp;
    }
private:
    int low_bound(vector<int>& nums, int target){       //寻找下边界
        int left = 0;
        int right = nums.size() - 1;
        int re = -1;
        while(left <= right){           //不加=会报错，[5 7 7 8 8 10]结果为[4,4]
            int mid = (left + right)/2;
            if(target < nums[mid]){
                right = mid - 1;
            }
            else if(target > nums[mid]){
                left = mid + 1;
            }
            else{
                re = mid;
                right = mid - 1;        //继续往下找
            }
        }
        return re;
    }

    int high_bound(vector<int>& nums, int target){       //寻找上边界
        int left = 0;
        int right = nums.size() - 1;
        int re = -1;
        while(left <= right){           //不加=会报错，[5 7 7 8 8 10]结果为[4,4]
            int mid = (left + right)/2;
            if(target < nums[mid]){
                right = mid - 1;
            }
            else if(target > nums[mid]){
                left = mid + 1;
            }
            else{
                re = mid;
                left = mid + 1;     ///继续往下找
            }
        }
        return re;
    }
};