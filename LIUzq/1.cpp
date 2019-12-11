public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        int[] sign = new int[2];
        for(int i=0; i<nums.Length; i++){
            for(int j=i+1; j<nums.Length; j++){
                if(target == nums[i]+nums[j]){
                    sign[0] = i;
                    sign[1] = j;
                }
            }
        }
        return sign;
    }
}