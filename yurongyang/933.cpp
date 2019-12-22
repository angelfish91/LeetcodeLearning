class RecentCounter {
public:
    RecentCounter() {
        
    }
    queue<int> q;

    int ping(int t) {
        int min=t-3000;
        while(!q.empty() && q.front()<min){
            q.pop();
        }
        q.push(t);
        return q.size();
    }
};
