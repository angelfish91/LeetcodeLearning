//运行时间800+ms,算法不好，需要优化，换一种方法/思路
class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    vector<int> time;

    int ping(int t) {
        time.push_back(t);
        int count;
        for(int i=0; i < time.size(); i++){
            while((t-3000)<=time[i])
                return time.size()-i;
        }
       return 0;
    }
};
//方法二：要利用队列的先进先出特点，把不在t-3000到t之间的移出队列。而栈不行
class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push(t);
        while(q.front() < t-3000) q.pop();
        return q.size();
        
    }
private:
    queue<int> q;
};
