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
				sumSet.insert(0); //�ڱ�ֵ, ���lower_bound�鵽�����ֵ, ˵������һ���ӵ�һ�е���ǰ�еľ���Ԫ�غ���������
				for (int r = 0; r < rows; ++r) {
					preSum += prerowSum[r];
					auto it = sumSet.lower_bound(preSum - k);  //���ҵ�һ��>=curSum-k���±�, ע��: sumSet�Ǹ����������set
					if (it != sumSet.end())
					{
						if (preSum - *it == k) return k;   //ֱ�ӷ���k
						else res = max(res, preSum - *it);
					}
					sumSet.insert(preSum);
				}
			}
		}

		return res;
	}
};