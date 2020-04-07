旋转矩阵

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //利用辅助矩阵
        int n = matrix.size();
        //vector<vector<int> > ans(n, vector<int>(n));
        vector<vector<int> > ans(n);
        for(int i = 0; i < ans.size(); i++){
            ans[i].resize(n);
        }
        //这里可以不用初始化一个新矩阵，直接利用赋值 = 就可以
        //auto ans = matrix;    //这里利用c++的=拷贝（值拷贝），会得到一个新的数组
        for(int j = 0; j < n; j++){
            for(int i = n-1; i >= 0; i--){
                ans[j][n-1-i] = matrix[i][j];   //找规律，这里和题解的不一样，i，j开始的位置不一样
            }
        }
        //这里也不需要用循环赋值，直接利用 = 进行值拷贝
        //matirx = ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                matrix[i][j] = ans[i][j];
            }
        }
    }
};

//原地旋转（利用翻转代替旋转）
//主要是找规律，先上下翻转，再对角线翻转（也可以左右翻转，再副对角线翻转）
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //水平翻转
        for(int i = 0; i < n/2; i ++){
            for(int j = 0; j < n; j++){
                //两种翻转方法
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-i][j];
                matrix[n-1-i][j] = tmp;
            }
        }
        //主对角线翻转
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){     //j不是<n, 等于i（在对角线上的不需要翻转）
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};