class MyQueue {
public:
    stack<int>instack;
    stack<int>outstack;
    int top;
    MyQueue() {
        
    }
    
    void push(int x) {
        instack.push(x);
    }
    
    int pop() {
        if(!outstack.empty()){
            top = outstack.top();
            outstack.pop();
        }
        else{
            while(!instack.empty()){
                top = instack.top();
                outstack.push(top);
                instack.pop();
            }
            top = outstack.top();
            outstack.pop();
        }
        return top;
    }
    
    int peek() {
        if(!outstack.empty()){
            top = outstack.top();
        }else{
            while(!instack.empty()){
                top = instack.top();
                outstack.push(top);
                instack.pop();
            }
        }
        top = outstack.top();
        return top;
    }
    
    bool empty() {
        if(instack.empty() && outstack.empty())return true;
        else return false;
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