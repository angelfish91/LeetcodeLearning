class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        float middle_count = (m+n)%2==0 ? (m+n)/2+1 : (m+n+1)/2;
        bool flag =  (m+n)%2==0 ? true:false;
        vector<int> tmp;
        int i = 0;
        int j = 0;
        for(int k=1;k<=middle_count;k++){
            if(i<m && j<n){
                
                if(nums1[i]<nums2[j]) {
                    tmp.push_back(nums1[i]);
                    i++;
                }
                else{
                    tmp.push_back(nums2[j]);
                    j++;
                }
            }
            else if(i>=m && j<n){
                tmp.push_back(nums2[j]);
                j++;
            }
            else if(j>=n && i<m){
                tmp.push_back(nums1[i]);
                i++;
            }
        }
        return flag ? (tmp[tmp.size()-2] + tmp[tmp.size()-1])/2.0 : tmp[tmp.size()-1];
    }
};
