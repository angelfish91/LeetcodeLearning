01矩阵

//BFS广度优先遍历，甜姨讲的很明白，见note截图
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        //和地图分析那道题基本类似
        int m = matrix.size();
        int n = matrix[0].size();
        queue<pair<int,int>> que;
        vector<vector<int>> ans(m, vector<int>(n));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    que.push({i, j});
                }
            }
        }
        
        while(que.size() != 0){
            //一次性遍历完一层
            int size = que.size();
            while(size--){
                auto cur = que.front();
                que.pop();

                for(auto& d : directions){
                    int x = cur.first + d[0];
                    int y = cur.second + d[1];
                    if(x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] != 1)  continue;
                    //搜过的设为-1
                    matrix[x][y] = -1;
                    //可以直接修改matrix，省内存
                    ans[x][y] = ans[cur.first][cur.second] + 1;
                    que.push({x, y});
                }
            }
        }
        return ans;
    }
private:
    vector<vector<int>> directions{
        {1,0}, {-1,0}, {0,1}, {0,-1}
    };
};


//官方解答

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // 初始化动态规划的数组，所有的距离值都设置为一个很大的数
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX / 2));
        // 如果 (i, j) 的元素为 0，那么距离为 0
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                }
            }
        }
        // 只有 水平向左移动 和 竖直向上移动，注意动态规划的计算顺序
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i - 1 >= 0) {
                    dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                }
                if (j - 1 >= 0) {
                    dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                }
            }
        }
        // 只有 水平向右移动 和 竖直向下移动，注意动态规划的计算顺序
		//这里不是递归，而是从底向上的，如果i，j从0开始那么成了从上到下，下面的还未知
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i + 1 < m) {
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                }
                if (j + 1 < n) {
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
                }
            }
        }
        return dist;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/01-matrix/solution/01ju-zhen-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。