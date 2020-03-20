最小的k的个数

//利用了库函数sort

//时间复杂度：O(nlogn)，其中 n 是数组 arr 的长度。算法的时间复杂度即排序的时间复杂度。

//空间复杂度：O(logn)，排序所需额外的空间复杂度为 O(logn)。
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans;
        sort(arr.begin(), arr.end());
        for(int i=0; i<k; i++){
            ans.push_back(arr[i]);      //如果ans初始化为vector<int> ans（k,0）;已经有了初始值就可以用=赋值了，不需要push_back
        }
        return ans;
    }
};

//自己写一个排序函数：利用最大堆/最小堆

//我们用一个大根堆实时维护数组的前 kk 小值。首先将前 kk 个数插入大根堆中，随后从第k+1 个数开始遍历，
//如果当前遍历到的数比大根堆的堆顶的数要小，就把堆顶的数弹出，再插入当前遍历到的数。
//最后将大根堆里的数存入数组返回即可。在下面的代码中，由于 C++ 语言中的堆（即优先队列）为大根堆，我们可以这么做。
//而 Python 语言中的对为小根堆，因此我们要对数组中所有的数取其相反数，才能使用小根堆维护前 k小值。

//时间复杂度：O(nlogk)，其中 n 是数组 arr 的长度。由于大根堆实时维护前 k 小值，
//所以插入删除都是 O(logk) 的时间复杂度，最坏情况下数组里 n 个数都会插入，所以一共需要 O(nlogk) 的时间复杂度。

//空间复杂度：O(k)，因为大根堆里最多 k 个数。
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans(k, 0);
        if(k == 0) return ans;		//需要判断k== 0的情况
        priority_queue<int> que;        //利用优先队列(默认大根堆）
        
        for(int i=0; i<k; i++){
            que.push(arr[i]);
        }
        for(int i=k; i<arr.size(); i++){
            if(arr[i] < que.top()){
                que.pop();
                que.push(arr[i]);
            }
        }
        for(int i=0; i<k; i++){
            //ans[i] = que[i];
            ans[i] = que.top();
            que.pop();
        }
        return ans;
    }
};

//快排思想：
我们可以借鉴快速排序的思想。我们知道快排的划分函数每次执行完后都能将数组分成两个部分，
小于等于分界值 pivot 的元素的都会被放到数组的左边，大于的都会被放到数组的右边，然后返回分界值的下标。
与快速排序不同的是，快速排序会根据分界值的下标递归处理划分的两侧，而这里我们只处理划分的一边。
