class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.empty()) return 0;
		int rows = matrix.size();

		int cols = matrix[0].size();


		int res = INT_MIN;
		for (int colstart = 0; colstart < cols; ++colstart)
		{
			vector<int> prerowSum(rows, 0);
			for (int colend = colstart; colend < cols; ++colend)
			{
				for (int row = 0; row < rows; ++row)
					prerowSum[row] += matrix[row][colend];
				int preSum = 0;

				set<int> sumSet;
				sumSet.insert(0); //哨兵值, 如果lower_bound查到了这个值, 说明存在一个从第一行到当前行的矩阵元素和满足条件
				for (int r = 0; r < rows; ++r) {
					preSum += prerowSum[r];
					auto it = sumSet.lower_bound(preSum - k);  //查找第一个>=curSum-k的下标, 注意: sumSet是个升序排序的set
					if (it != sumSet.end())
					{
						if (preSum - *it == k) return k;   //直接返回k
						else res = max(res, preSum - *it);
					}
					sumSet.insert(preSum);
				}
			}
		}

		return res;
	}
};