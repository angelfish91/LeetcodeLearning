生命游戏（中等难度）


//和题解一样，为什么答案都是0？
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int neighbors[3] = {0, 1, -1};

        int row = board.size();
        int col = board[0].size();

        //创建副本数组
        vector<vector<int> > temp(row, vector<int>(col, 0));

        //复制一份过去,用副本作遍历，找到要改的数据位置，在原数组上改
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                temp[r][c] = board[r][c];
            }
        }
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                //统计每个细胞八个相邻位置的活细胞数量
				//【注意学习这里八个方向是怎么遍历到的】！！！
                int liveNeighbor = 0;
                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        if(!(neighbors[i] == 0 && neighbors[j] == 0)){
                            int r1 = r + neighbors[i];
                            int c1 = c + neighbors[j];
                            //if((r1 < r && r1 >= 0) && (c1 < c && c1 >= 0) && temp[r1][c1] == 1){	//问题在这：r1 < row c1 < col;
							if((r1 < row && r1 >= 0) && (c1 < col && c1 >= 0) && temp[r1][c1] == 1){
                                liveNeighbor ++;
                            }
                        }
                    }
                }
                //规则1或规则3
                if(temp[r][c] == 1 && (liveNeighbor < 2 || liveNeighbor > 3)){
                    board[r][c] = 0;
                }
                //规则4
                if(temp[r][c] == 0 && liveNeighbor == 3){
                    board[r][c] = 1;
                }
            }
        }
    }
};