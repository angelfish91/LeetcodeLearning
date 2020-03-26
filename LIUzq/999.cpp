//车的可用捕获量


//错误解答，思路不清晰
//四个方向上的移动可以用数组表示
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                if(board[i][j] == 'R'){
                    return searchPawn(board, i, j);
                }
            }
        }
        return 0;
    }

private:
    int searchPawn(vector<vector<char>>& board, int x, int y){
        int cur_x = x;
        int cur_y = y;
        int ans = 0;
        if(cur_x > 7 || cur_x < 0 || cur_y > 7 || cur_y < 0 || board[cur_x][cur_y] == 'B'){
            return 0;
        }
        //显然不会进这个判断直接返回0了，当前是 R ，和前面求岛屿最大面积那个题目不一样
        if(board[cur_x][cur_y] == 'p'){
            return 1 + searchPawn(board, cur_x, cur_y-1) + searchPawn(board, cur_x, cur_y+1) + searchPawn(board,                        cur_x-1, cur_y) + searchPawn(board,cur_x+1, cur_y);
        }

        return 0;
        //思路不清晰，不是在这里return
        //return searchPawn(board, cur_x, cur_y-1) + searchPawn(board, cur_x, cur_y+1) + searchPawn(board, cur_x-1, cur_y) + searchPawn(board,cur_x+1, cur_y);
    }
};


//在每个方向上只探索一次就结束，视为一次行动


//局部和全局变量搞错
//位置错误
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {

        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                if(board[i][j] == 'R'){
                    return searchPawn(board, i, j);
                }
            }
        }
        return 0;
    }

private:
    int searchPawn(vector<vector<char>>& board, int x, int y){
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        int ans = 0;
        for(int i=0; i<4; i++){     //在四个方向上都走一次
            while(true){
                x += dx[i];
                y += dy[i];
                if(x < 0 || x > 7 || y < 0 || y > 7 || board[x][y] == 'B'){
                    break;
                }
                if(board[x][y] == 'p'){
                    ans ++;
                    break;
                }
            }
        }
        return ans;
    }
};

//正确解答：

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                if(board[i][j] == 'R'){
                    int ans = 0;
                    // int x = i;
                    // int y = j;
                    for(int k=0; k<4; k++){     //在四个方向上都走一次
                        int x = i;      //x的位置为什么不能放在上面
                        int y = j;          //x,y 的作用域应该是在这个小的for循环里，跳出外面就类似成了全局变量
                        while(true){
                            x += dx[k];     //如果是全局变量的话这里的x和y就没办法复位
                            y += dy[k];
                            if(x < 0 || x > 7 || y < 0 || y > 7 || board[x][y] == 'B'){
                                break;
                            }
                            if(board[x][y] == 'p'){
                                ans ++;
                                break;
                            }
                        }
                    }
                    return ans;
                }
            }
        }
        return 0;
    }
// private:
//     int searchPawn(vector<vector<char>>& board, int x, int y){
//         int dx[] = {-1,1,0,0};
//         int dy[] = {0,0,-1,1};
//         int ans = 0;
//         for(int i=0; i<4; i++){     //在四个方向上都走一次
//             while(true){
//                 x += dx[i];
//                 y += dy[i];
//                 if(x < 0 || x > 7 || y < 0 || y > 7 || board[x][y] == 'B'){
//                     break;
//                 }
//                 if(board[x][y] == 'p'){
//                     ans ++;
//                     break;
//                 }
//             }
//         }
//         return ans;
//     }
};

//另一种解法：
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                if(board[i][j] == 'R'){
                    return searchPawn(board,i,j,0,1) + searchPawn(board,i,j,0,-1) + searchPawn(board,i,j,1,0) + 
					searchPawn(board,i,j,-1,0);         //在这里单独探索四个方向
                }
            }
        }
        return 0;
    }
private:
    int searchPawn(vector<vector<char>>& board, int x, int y, int dx, int dy){
        while(x >= 0 && x < 8 && y >= 0 && y < 8 && board[x][y] != 'B'){
            if(board[x][y] == 'p'){
                return 1;
            }
            x += dx;
            y += dy;
        }
        return 0;
    }
};