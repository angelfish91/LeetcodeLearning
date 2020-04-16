合并区间


【注意对vector的新用法】
1.二维或者多维数组，可以用sort只对每行第一个元素排序，并且不打乱原来的组合
2.vector也可以用back()取最后一位元素，  vec.back()[1]可以这样使用
3.多维数组vector的push_back，例如n行2列的数组，vec.push_back({1,2});可以这样复制，
  类似于一位数组的push一个数
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0)  return {};
        vector<vector<int>> merge;
        //新用法，只对每一行第一个元素排序
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < intervals.size(); i++){
            int L = intervals[i][0];
            int R = intervals[i][1];
            if(!merge.size() || merge.back()[1] < L){   //说明不能合并
                merge.push_back({L, R});    //这里不能用emplace_back
            }else{
                merge.back()[1] = max(merge.back()[1], R);
            }
        }
        return merge;
    }
};