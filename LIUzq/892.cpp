三维形体的表面积


//主要是理解题意，找到一个通用合适的规律：
//先把每个方阵上对应的数字看成独立的一个柱体（不与其他柱体重合）则表面积为 num*4+2，然后再减去重合的部分。
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] != 0){
                    ans += grid[i][j] * 4 + 2;
                }
                if(i > 0){
                    ans -= min(grid[i-1][j], grid[i][j]) * 2;
                }
                if(j > 0){
                    ans -= min(grid[i][j-1], grid[i][j]) * 2;
                }
            }
        }
        return ans;
    }
};