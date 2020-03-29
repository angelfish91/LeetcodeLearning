地图分析


//BFS 广度优先遍历【不会做，抄的答案】【需要再次研究】
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        const int M = grid.size();
        const int N = grid[0].size();

        //使用deque或queue
        queue<pair<int, int> > que;
        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                if(grid[i][j] == 1){
                    //将所有陆地放入队列
                    que.push({i, j});
                }
            }
        }
        //如果没有陆地或海洋 ，返回-1；
        if(que.size() == 0 || que.size() == M*N){
            return -1;
        }
        //由于BFS的第一层遍历是从陆地开始的，因此遍历完第一层滞后distance应该是0
        int distance = -1;
        while(que.size() != 0){
            //新遍历的一层
            distance ++;
            //当前层的元素有多少，在该轮中一次性遍历完当前层
            int size = que.size();
            while(size --){
                //BFS遍历的当前元素永远是队列的开头元素
                //【队列的作用】
                auto cur = que.front();     //这里返回的应该是迭代器
                que.pop();  //出对头元素


                //对当前元素的各个方向进行搜索
                for(auto& d : directions){
                    int x = cur.first + d[0];
                    int y = cur.second + d[1];
                    //如果搜索到的新坐标超出范围/陆地/已经遍历过了，则停止搜索
                    if(x < 0 || x >= M || y < 0 || y >= N || grid[x][y] != 0){		//【注意=的添加】！！！
                        continue;
                    }
                    //把搜过的设为2
                    grid[x][y] = 2;
                    que.push({x, y});
                }
            }
        }
        return distance;
        //最终走了多少层才把海洋遍历完
    }
private:
    vector<vector<int>> directions = {
        {-1, 0}, 
        {1,  0},
        {0,  1},
        {0, -1}
    };
};