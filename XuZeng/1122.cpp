class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
		map<int, int> temp;
        for(int i = 0;i < arr1.size();i++) {
            temp[arr1[i]]++;
        }
        for(int i = 0;i < arr2.size();i++) {
            while(temp[arr2[i]]){
                result.push_back(arr2[i]);
                temp[arr2[i]]--;
            }
            temp.erase(arr2[i]);
        }

		for (map<int, int>::iterator it = temp.begin(); it != temp.end(); ++it) {
			while ((it->second)--) result.push_back(it->first);
		}
		return result;
    }
};