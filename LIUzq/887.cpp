高楼扔鸡蛋【困难】

【搞不定，最后抄答案打卡了。。。】
//按教程写的，不知道为什么不通过
【学习点】
		unordered_map中结合pair使用，需要加入hash函数  https://blog.csdn.net/missshirly/article/details/51231836
		但queue却不用，        
		//机器人运动范围这个题就使用了这种方法
		queue<pair<int, int> >  Q;
        //Q 要先初始化
        Q.push(make_pair(0, 0));
		
class Solution {
public:

    int ans = 20005;
    int superEggDrop(int K, int N) {
        //二分法找楼层扔鸡蛋不可行，因为鸡蛋有数量限制
        
       return dp(K, N);

    }
private:
    struct pair_hash
    {
        template<class T1, class T2>
        std::size_t operator() (const std::pair<T1, T2>& p) const
        {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return h1 ^ h2;
        }
    };
    unordered_map<pair<int,int>, int, pair_hash> um;
    //动态规划往往给一个底部的初始值，每次加1（一般）逐渐往上走，就解决了问题
    //找到【状态】和【选择】，再找到状态转移方程，基本就完成了
    //int ans = 20005;  //ans初始化为无穷大，选一个很大的数就可以了
    int dp(int K, int N){
        if(K == 1) return N;
        if(N == 0) return 0;
        //不应该在这里初始化！！！
        //int ans = N + 5;  //ans初始化为无穷大，选一个很大的数就可以了
        //穷举所有可能的选择
        for(int i= 1; i <= N; i++){     //i从1开始  做选择
            // if(um.find(make_pair(K,N)) != um.end()){    //注意这里的用法
            //     return um[make_pair(K,N)];
            // }
            //"至少"和“最坏情况”
            ans = min(ans, max(dp(K, N - i), dp(K - 1, i - 1)) + 1);
            //um[make_pair(K, N)] = ans;
            return ans;
        }
        return 0;
    }
};

//官方解答，结合二分搜索
class Solution {
    unordered_map<int, int> memo;
    int dp(int K, int N) {
        if (memo.find(N * 100 + K) == memo.end()) {
            int ans;
            if (N == 0) ans = 0;
            else if (K == 1) ans = N;
            else {
                int lo = 1, hi = N;
                while (lo + 1 < hi) {
                    int x = (lo + hi) / 2;
                    int t1 = dp(K-1, x-1);
                    int t2 = dp(K, N-x);

                    if (t1 < t2) lo = x;
                    else if (t1 > t2) hi = x;
                    else lo = hi = x;
                }

                ans = 1 + min(max(dp(K-1, lo-1), dp(K, N-lo)),
                                   max(dp(K-1, hi-1), dp(K, N-hi)));
            }

            memo[N * 100 + K] = ans;
        }

        return memo[N * 100 + K];
    }
public:
    int superEggDrop(int K, int N) {
        return dp(K, N);
    }
};