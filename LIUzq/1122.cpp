//1122. 数组的相对排序


//sort排序函数默认升序排序，这里不需要加comp！
// int comp(int a, int b){
//     return a < b;
// }
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        if(arr1.size() == 0 || arr2.size() == 0)
            return vector<int>();
		
		/*注意vector怎么定义*/
        vector<int> arr(1001,0);            // int arr[1001] = {0};
        vector<int> ans;                    // int ans[1001] = {0};
        //先给arr1升序排序
        sort(arr1.begin(), arr1.end());
        //在对应arr位置记录arr1的数据，下标为arr1的数字，数字为arr1出现的次数
        for(int i=0; i < arr1.size(); i++){
            arr[arr1[i]] ++;
        }
        //遍历arr2，
        for(int i=0; i < arr2.size(); i++){
            while(arr[arr2[i]] > 0){
                ans.push_back(arr2[i]);
                arr[arr2[i]] --;
            }
        }
        //遍历arr，找到arr2中没有的元素，升序排序（之前已对arr1排好序，这里直接push_back即可）
        for(int i=0; i < arr.size(); i++){
            while(arr[i] > 0){
                ans.push_back(i);           //这里应该push的是i！！！
                arr[i] --;
            }
        }
        return ans;

    }
};