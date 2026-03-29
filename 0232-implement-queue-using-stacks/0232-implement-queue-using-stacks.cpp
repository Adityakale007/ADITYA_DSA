class MyQueue {
    private:
    stack<int> s1,s2;
public:
    MyQueue() {
    }
    
    void push(int x) {
        //first take all from s1 out in stack order and put it in s2
        //then puush required integer in s1
        //then move all s2 elements back to s1 in same stack order

        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        if(s1.size() == 0)return -1;
        int val = s1.top();
        s1.pop();
        return val;
    }
    
    int peek() {
        if(s1.size() == 0)return -1;
        return s1.top();
    }
    
    bool empty() {
        return s1.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */