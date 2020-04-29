1095 山脉数组中查找目标值

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */


//参考官方题解，用了三次二分查找，
//一次用来找到峰值下标，两次用来在峰值左右分别查找
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        //二分查找,保证调用次数内
        //【先找到峰值，再在两边找，先找左边】
        int l = 0, r = mountainArr.length() - 1;
        while(l < r){   //这里为什么没有 = ？
            int m = l + (r - l) / 2;
            if(mountainArr.get(m) < mountainArr.get(m + 1)){
                l = m + 1;
            }else{
                r = m;  //不是 m - 1 是因为m的值可能等于m+1的值
            }
        }
        int highIndex = l;
        int searchIndex = searchHalf(target, mountainArr, 0, highIndex, 1); //位于左边（升序）
        if(searchIndex != -1)
            return searchIndex;
        //在峰值的右边
		//【没有注意到右边是降序，导致错误】
        return searchHalf(target, mountainArr, highIndex + 1, mountainArr.length() - 1, -1);//右边为降序
    }
private:
    int searchHalf(int target, MountainArray &mountainArr, int l, int r, int reverse){
        int left = l, right = r;
		//这里reverse代表左右，为-1时把右边的降序变为升序，同时target也要变为负数
        target *= reverse;
        while(left <= right){	//注意二分查找的循环条件和左右指针的移动方法	【OneNote里有表格，对照查一下】
            int mid = left + (right - left) / 2;
            int res = reverse * mountainArr.get(mid);
            if(target == res) return mid;
            if(target > res){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return -1; 
    }
};