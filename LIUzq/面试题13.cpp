机器人的运动范围【中等】


//思路错了，题目理解有误
//有些格子压根就到不了，怎么还能继续往下走呢，这种扫描式的前进方式本来就和题目不符，上下左右四个方向
class Solution {
public:
    int movingCount(int m, int n, int k) {
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(sumPos(i) + sumPos(j) <= k){
                    cnt ++;
                }
            }
        }
        return cnt;
    }
private:
	//位数求和函数是正确的，循环里可以用另一种方法,不需要新建变量
	
    int sumPos(const int& x){
        int sum = 0;
        int y = x;
        while(y / 10 != 0 || y % 10 != 0){
            sum += y % 10;
            y = y / 10;
        }
        return sum;
		//for(; x; x /= 10){
			//sum += x % 10;
		//}
};

class Solution {
public:
    int movingCount(int m, int n, int k) {
        int cnt = 0;
        int tmp[m][n];
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(sumPos(i) + sumPos(j) <= k){     
                    for(int l = 0; l < 4; l++){     //这种方法是象棋那个题用的，那个只需要在四个方向走一次就好了
					//本题不适用，仍然需要递归（老方法）
                        int x = i;
                        int y = j;
                        x += dx[l];
                        y += dy[l];
                        if(x < 0 || x >= m || y < 0 || y >= n || sumPos(x) + sumPos(y) > k ){
                            break;
                        }
                        if(tmp[x][y] != 1){
                            tmp[x][y] = 1;
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
    }
private:
    int sumPos(const int& x){
        int sum = 0;
        int y = x;
        while(y / 10 != 0 || y % 10 != 0){
            sum += y % 10;
            y = y / 10;
        }
        return sum;
    }
};

//正确解答：
//用递归 DFS（深度优先遍历）
//BFS（广度优先遍历）用队列
class Solution {
public:
    int tmp[101][101];
    int movingCount(int m, int n, int k) {
        
        return searchNum(m,n,k,0,0);
    }
private:
    int sumPos(const int& x){
        int sum = 0;
        int y = x;
        while(y / 10 != 0 || y % 10 != 0){
            sum += y % 10;
            y = y / 10;
        }
        return sum;
    }
    int searchNum(int m, int n, int k, int x, int y ){
        if(x < 0 || x >= m || y < 0 || y >= n || sumPos(x) + sumPos(y) > k ){
            return 0;
        }
        if(tmp[x][y] != 1){
            tmp[x][y] = 1;
            return 1 + searchNum(m, n, k, x, y-1)+searchNum(m,n,k,x-1,y)+searchNum(m,n,k,x,y+1)+searchNum(m,n,k,x+1,y);
        }
        return 0;
    }
};

//官方解答：学习新方法

class Solution {
    int get(int x){
        int res = 0;
        for(; x; x /= 10){
            res += x % 10;
        }
        return res;
    }
public:
    int movingCount(int m, int n, int k) {
        if(!k) return 1;
        vector<vector<int> > vis(m, vector<int>(n, 0));
        queue<pair<int, int> >  Q;
        //Q 要先初始化
        Q.push(make_pair(0, 0));
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        vis[0][0] = 1;
        int ans = 1;
		//用队列的形式扫描
        while(!Q.empty()){
            auto [x,y] = Q.front();
            Q.pop();
			//这里我用了四个方向扫描，官方经推导，使用向右和向下方向的扫描即可，故dx可初始化为{0,1}，dy初始化为{1,0}
            for(int i = 0; i < 4; i++){
                int tx = x + dx[i];
                int ty = y + dy[i];
                if(tx < 0 || tx >= m || ty < 0 || ty >= n|| vis[tx][ty] || get(tx) + get(ty) > k) continue;
                vis[tx][ty] = 1;
                ans ++;
                Q.push(make_pair(tx,ty));
            }
        }
        return ans;
    }
};