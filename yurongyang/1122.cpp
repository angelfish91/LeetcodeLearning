class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
       int* book = new int[1001]();
       vector<int> result;
       for(int i=0;i<arr1.size();i++){
           book[arr1[i]]++;
       }

       for(int j=0;j<arr2.size();j++){
           int count = book[arr2[j]];
           for(int k=0;k<count;k++){
               result.push_back(arr2[j]);
           }
       }
       
       for(int i=0;i<=1000;i++){
            if(book[i]>0){
                if(find(arr2.begin(),arr2.end(),i) == arr2.end()){
                    int count = book[i];
                    for(int j=0;j<count;j++){
                        result.push_back(i);
                    }
                }
           }
       }
     return result;  

    }
};
