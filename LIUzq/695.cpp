695.岛屿的最大面积

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    ans = max(ans, searchIsland(grid, i, j));
                }
            }
        }
        return ans;
    }
private:
    int searchIsland(vector<vector<int> > & grid, int i, int j){
        int cur_i = i;
        int cur_j = j;
        if(cur_i == grid.size() || cur_i < 0) return 0;
        if(cur_j == grid[0].size() || cur_j < 0) return 0;
        if(grid[cur_i][cur_j] == 1){		//访问过的地方就置为1
            grid[cur_i][cur_j] = 0;
			//每到一个地方就探索四个方向上有没有1，有就加上
            return 1 + searchIsland(grid, cur_i, cur_j+1) + searchIsland(grid, cur_i, cur_j-1) + searchIsland(grid, cur_i+1, cur_j) + searchIsland(grid, cur_i-1, cur_j);
        }
        return 0;
    }
};