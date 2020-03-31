排序数组

一、用冒泡排序
【冒泡排序】是一种稳定排序，值相等的元素并不会打乱原本的顺序。
由于该算法的每一轮都要遍历所有元素，总共遍历（元素数量-1）轮，所以平均时间复杂度为O（n2）；空间复杂度为O（1）
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //冒泡排序(超时)   （-50000~50000）10000个数，数目较多
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = 0; j < nums.size()-i-1; j++){
                if(nums[j] > nums[j+1]){
                    int tmp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = tmp;
                }
            }
        }
        return nums;
    }
};


class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //（第二次升级版）冒泡排序， 判断出序列已经有序，并作出标记，剩下的几轮就不需要执行了
        //超时！
        for(int i = 0; i < nums.size() - 1; i++){
            bool isSorted = true;
            for(int j = 0; j < nums.size()-i-1; j++){
                if(nums[j] > nums[j+1]){
                    int tmp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = tmp;
                    isSorted = false;
                }
            }
            if(isSorted)    break;
        }
        return nums;
    }
};

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //（第三次升级版）冒泡排序， 判断前面已经有序的序列，不需要每次都从头开始判断(这句话错误！！，每次都是从头开始判断的，不一样的是后面已经有序的位置)，所以应该记录最后一次交换元素的位置，该位置即为无序数列的边界，再往后就是有序区域了
        //超时！
        int lastChangePos = 0;
        //int sortUpdate = 0;
        int sortBorder = nums.size() - 1;
        for(int i = 0; i < nums.size() - 1; i++){
            bool isSorted = true;
            //for(int j = sortUpdate; j < nums.size()-i-1; j++){
            for(int j = 0; j < sortBorder; j++){    //不需要再减一了，下面if语句会判断j 和j + 1的
                if(nums[j] > nums[j+1]){
                    int tmp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = tmp;
                    lastChangePos = j;
                    isSorted = false;
                }
                //sortBorder = lastChangePos;
            }
            sortBorder = lastChangePos;
            if(isSorted)    break;
        }
        return nums;
    }
};

二、用快速排序（分治法）
同冒泡排序一样，也属于交换排序，通过元素之间的比较和交换位置来达到排序的目的
   不同的是，冒泡排序在每一轮中只把一个元素冒泡到数列的一端（末端），而快排则在每一轮挑选一个基准元素（pivot）并让
比他大的和小的分别位于左右两边（根据升序和降序选择），把数列拆成两个部分——————这种思路就是分治法！
  每一轮的比较和交换，需要把数组所有元素都遍历一遍，时间复杂度O(n),一共需要遍历（平均情况下）logn轮，因此快排总体
时间复杂度O(nlogn)，但最坏为O(N2)(由完全逆序变为顺序)

//双边循环法:	【通过】
class Solution {
public:
    //利用递归的方式
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0 ,nums.size() - 1);
        return nums;
    }
private:
    void quickSort(vector<int> & nums, int startIndex, int endIndex){
        if(startIndex >= endIndex)  return;
        //得到基准元素的位置
        int pivotIndex = partition(nums, startIndex, endIndex);
        quickSort(nums, startIndex, pivotIndex - 1);
        quickSort(nums, pivotIndex + 1, endIndex);
    }

    int partition(vector<int>& nums, int startIndex, int endIndex){
        //快速排序（双边循环法）
        //取第一个位置为基准元素
        int pivot = nums[startIndex];
        int left = startIndex;
        int right = endIndex;
        // int left = 0;
        // int right = nums.size() - 1;
        while(left != right){
            while(left < right && nums[right] > pivot){
                right --;
            }
            //while(left < right && nums[left] < pivot){
            while(left < right && nums[left] <= pivot){     //少了一个=，很简单的测试用例就超时了
                left ++;
            }
            if(left < right){
                int tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
            }
        }
        //pivot和指针重合点交换
        nums[startIndex] = nums[left];
        nums[left] = pivot;

        return left;
    }
};

//单边循环法：

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //单边循环法  （快排）
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
private:
    void quickSort(vector<int>& nums, int startIndex, int endIndex){
        if(startIndex >= endIndex){
            return;
        }
        int pivotIndex = partition(nums, startIndex, endIndex);
        //分治法：
        quickSort(nums, startIndex, pivotIndex - 1);
        quickSort(nums, pivotIndex + 1, endIndex);
    }

    int partition(vector<int>& nums, int startIndex, int endIndex){
        int pivot = nums[startIndex];
        int mark = startIndex;
        for(int i = startIndex + 1; i <= endIndex; i++){
            //if(nums[mark] > nums[i]){
            if(pivot > nums[i]){    //是和基准元素比较
                mark ++;
                int tmp = nums[mark];
                nums[mark] = nums[i];
                nums[i] = tmp;
            }
        }
        nums[startIndex] = nums[mark];
        nums[mark] = pivot;
        return mark;
    }
};

//快排的非递归实现（java版本）c++ 编译未通过，函数的使用不同
//仅供学习

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //快排的非递归实现
        //代码中一层一层的方法调用，本身就使用了一个方法调用栈。每次进入一个新方法，就相当于入栈；每次有方法返回，就相当于出栈
        //所以，可以把原本的递归实现转化成一个栈的实现，在占中存储每一次方法调用的参数
        quickSort(nums, 0, nums.size() - 1);
        return nums;

    }
private:
    void quickSort(vector<int>& nums, int startIndex, int endIndex){
        //用一个集合栈来代替递归的函数栈
        stack<map<string, int> > quickSortStack;
        //整个数列的起止下标，以哈希的形式入栈
        map<string, int> rootParam;
        rootParam.insert(pair<string, int> ("startIndex", startIndex));
        rootParam.insert(pair<string, int> ("endIndex", endIndex));
        quickSortStack.push(rootParam);
        //栈为空时循环结束
        while(!quickSortStack.empty()){
            //栈顶元素出栈，得到起止下标（得到rootParam）
            map<string, int> param = quickSortStack.top();
            //得到基准元素位置
            int pivotIndex = partition(nums, param.find("startIndex")->sencond, param.find("endIndex")->second);
            //根据基准元素分成两部分，把每一部分的起止下标入栈
            if(param.find("startIndex")->sencond < pivotIndex - 1){
                map<string, int> leftParam;
                leftParam.insert(pair<string, int> ("startIndex", param.find("startIndex")->sencond));
                leftParam.insert(pair<string, int> ("endIndex", pivotIndex - 1));
                quickSortStack.push(leftParam);
            }
            if(pivotIndex + 1 < param.find("endIndex")->sencond){
                map<string, int> rightParam;
                rightParam.insert(pair<string, int> ("startIndex", pivotIndex + 1));
                rightParam.insert(pair<string, int> ("endIndex", param.find("endIndex")->sencond));
                quickSortStack.push(rightParam);
            }
        }
    }
    //分治法，单边循环
    int partition(vector<int>& nums, int startIndex, int endIndex){
        int pivot = nums[startIndex];
        int mark = startIndex;

        for(int i = startIndex + 1; i <= endIndex; i++){
            if(pivot > nums[i]){
                mark ++;
                int tmp = nums[mark];
                nums[mark] = nums[i];
                nums[i] = tmp;
            }
        }

        nums[startIndex] = nums[mark];
        nums[mark] = pivot;
        return mark;
    }
};

//堆排序

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //堆排序
        //因为要升序排列，所以建立大根堆
        heapSort(nums);
        return nums;
    }
private:
    void heapSort(vector<int>& nums){
        //构建大根堆
        for(int i = (nums.size()-2)/2; i >= 0; i--){
            downAdjust(nums, i, nums.size());
        }
        //删除堆顶元素（实际为移到末尾）
        for(int i = nums.size()-1; i >= 0 ;i--){
            int tp = nums[0];
            nums[0] = nums[i];
            nums[i] = tp;
            downAdjust(nums, 0, i);
        }
    }

    void downAdjust(vector<int>& nums, int parentIndex, int size){
        //tmp用于保存父节点的值，用于最后的赋值
        int tmp = nums[parentIndex];
        int childIndex = 2 * parentIndex + 1;
        // if(childIndex + 1 < size && nums[childIndex] < nums[childIndex + 1]){
        //     childIndex ++;
        // }
        //if(nums[parentIndex] >= nums[childIndex])   break;
        while(childIndex < size){
            //如果有右孩子，且大于左孩子的值，则定位到右孩子
            if(childIndex + 1 < size && nums[childIndex] < nums[childIndex + 1]){
                childIndex ++;
            }
            //if(nums[parentIndex] >= nums[childIndex])   break;
            //如果父节点大于任何一个子节点的值，直接跳出
            if(tmp >= nums[childIndex])     break;            
            nums[parentIndex] = nums[childIndex];
            parentIndex = childIndex;
            childIndex = 2 * childIndex + 1;
        }
        nums[parentIndex] = tmp;
    }
};