//面试题59 --II 队列的最大值

//思路：
用一个queue和一个deque实现

queue就是正常的que，负责push和pop

deque用来存放最大值

如果新的value大于deque尾端的值，那么deque一直进行pop_back操作，直到尾端的值大于等于value 或者为空

再将value压入deque的尾部

每次取max_value，返回deque首部的值

当que进行pop操作时，如果que首部的值等于deque首部的值，那么deque同样需要进行pop_front操作

class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        return que.empty() ? -1 : dq.front();
    }
    
    void push_back(int value) {
        que.push(value);
        while(!dq.empty() && dq.back() < value){
            dq.pop_back();
        }
        dq.push_back(value);
    }
    
    int pop_front() {
        if(que.empty())
            return -1;
        int num = que.front();
        que.pop();
        if(num == dq.front())
            dq.pop_front();
        return num;
    }
private:
    queue<int> que;
    deque<int> dq;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */