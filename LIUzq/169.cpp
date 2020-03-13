//169.多数元素
//给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 [n/2]的元素。



//  通过率42/44，在[1,1....,2,2....]时运行时间超时，算法太复杂，需要优化
//***************还有缺陷，这里dp[i]++ ，算的是除了自己其他和自己一样的个数，最终出现次数应该加1.
//【注意题目】【出现次数大于n/2】
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int dp[nums.size()] = {0};
        int maxN = 0;
        int index = 0;
		//遍历nums，用dp保存每个数出现的次数，i为对应位置，存在多次比较，重复运算的情况
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] == nums[j]){
                    dp[i] ++;
                    //maxN = max(maxN, dp[i]);
                }
            }
        }
		//遍历dp，找到最大值，返回索引，即为nums中出现次数最多的元素
        for(int i = 0; i < nums.size(); i++){
            if(maxN < dp[i]){
                maxN = dp[i];
                index = i;
            }
        }
        return nums[index];
    }
};

//另一种想法：
//用dp[nums[i]]来保存nums[i]出现的次数，dp下标数为nums[i]元素的值，dp值为该元素出现的次数，
//有一个问题:如果nums[i]为负数就不行了，数组下标是从0开始的。
//所以这里就可以想到哈希表 unordered_map

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //哈希表！！
        unordered_map<int,int> umap;  //元素  --- 次数
        for(int i = 0; i < nums.size(); i++){
            umap[nums[i]] ++;
            if(umap[nums[i]] > (nums.size()/2))  return nums[i];           
        }
        return -1;
    }
};

//Boyer-Moore投票算法
//快捷高效
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Boyer-Moore 投票算法
        //从第一个数开始，遇到和自己一样的count+1，不一样就-1，如果变为0，就换下一个数，那么出现次数最多的count一定大于0,
        //即k不会更换，最终返回k即可。
        int k = nums[0];
        int count = 0;
        for(int i = 1; i < nums.size(); i++){
            if(k == nums[i]){
                count ++;
            }
            else{
                if(count == 0){
                    k = nums[i];
                }
                else{
                    count --;
                }
            }
        }
        return k;
    }
};