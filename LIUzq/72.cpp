编辑距离【困难】

//暴力解法（递归）
class Solution {
public:
	//通过更改函数名，但是会影响调用。不可行
    int minDistance(string word1, string word2, int x, int y) {
        if(x == 0)  return y;
        if(y == 0)  return x;

        int size1 = word1.length();
        int size2 = word2.length();
        //int dp[size1][size2];
        int i = size1-1;
        int j = size2-1;
        if(word1[i] == word2[j]){
            return minDistance(word1, word2, i-1, j-1);
        }else{
            return min(minDistance(word1, word2, i, j-1)+1, min(minDistance(word1,word2, i-1, j)+1, minDistance(word1, word2, i-1,j-1)+1));
        }
        return 0;
    }
};

//通过测试但是递归耗时巨大，这种方法不可取
双指针，分别从字符串末尾开始向前遍历，挨个比较
class Solution {
public:
    int minDistance(string word1, string word2) {
        return dp(word1, word2, word1.length()-1, word2.length()-1);
    }
private:
    int dp(string& word1, string& word2, int x, int y) {
        if(x == -1)  return y+1;    //这里用0作为判断条件的话答案是错的，少了一次操作，
        if(y == -1)  return x+1;

        // int size1 = word1.length();
        // int size2 = word2.length();
        // //int dp[size1][size2];
        // int i = size1-1;
        // int j = size2-1;
        if(word1[x] == word2[y]){
            return dp(word1, word2, x-1, y-1);
        }else{
            return 1+min(dp(word1, word2, x, y-1), min(dp(word1,word2, x-1, y), dp(word1, word2, x-1,y-1)));
        }
    }
};

//备忘录
//编译不通过，堆栈溢出，（未找到问题）
class Solution {
public:
    int mem[10000][10000];
    int minDistance(string word1, string word2) {
        return dp(word1, word2, word1.length()-1, word2.length()-1);
    }
private:
    int dp(string& word1, string& word2, int x, int y) {
        if(x == -1)  return y+1;    //这里用0作为判断条件的话答案是错的，少了一次操作
        if(y == -1)  return x+1;
        if(x>=0 && y>=0 && mem[x][y] != 0) return mem[x][y];
        if(word1[x] == word2[y]){
            mem[x][y] = dp(word1, word2, x-1, y-1);
            //return mem[x][y]; 
        }else{
            mem[x][y] = 1+min(dp(word1, word2, x, y-1), min(dp(word1,word2, x-1, y), dp(word1, word2, x-1,y-1)));
            //return mem[x][y];
        }
        return mem[x][y];
    }
};


//动态规划
class Solution {
public:
    int minDistance(string word1, string word2) {
        //动态规划
        int m = word1.length();
        int n = word2.length();
        int dp[m+1][n+1];   //要预留[0,0]空位置
        for(int i = 0; i < m+1; i++)  dp[i][0] = i;   //保存word1的，如果只有一个字母最少要转换多少次
        for(int i = 0; i < n+1; i++)  dp[0][i] = i;
        //自底向上求解
        for(int i = 1; i < m+1; i++){     //空位置不管
            for(int j = 1; j < n+1; j++){
                if(word1[i-1] == word2[j-1]){   //word是从0开始计数的
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] =1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                }
            }
        }
        return dp[m][n];
    }
};

//在内外循环结果都一样，即s1转为s2和s2转为s1结果是一样的
//只是dp数组对称一下
class Solution {
public:
    int minDistance(string word1, string word2) {
        //动态规划
        int m = word1.length();
        int n = word2.length();
        int dp[n+1][m+1];   //要预留[0,0]空位置
        for(int i = 0; i < n+1; i++)  dp[i][0] = i;   //保存word1的，如果只有一个字母最少要转换多少次
        for(int i = 0; i < m+1; i++)  dp[0][i] = i;
        //自底向上求解
        for(int i = 1; i < n+1; i++){     //空位置不管
            for(int j = 1; j < m+1; j++){
                if(word1[j-1] == word2[i-1]){   //word是从0开始计数的
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] =1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};