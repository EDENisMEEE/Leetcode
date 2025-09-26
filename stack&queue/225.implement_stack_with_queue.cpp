class MyStack {
public:
    queue<int>q0;
    queue<int>q1;
    int cnt = 0;
    int peeked = 0;
    MyStack() {
        
    }
    
    void push(int x) {
        if (cnt%2 == 0){
            q0.push(x);
        }
        else if(cnt %2 == 1){
            q1.push(x);
        }
    }
    
    int pop() {
        int ans;
        if (cnt%2 == 0){
            if(peeked){
                ans = q0.front();
                q0.pop();   
            }
            else{
                while(q0.size()>1){
                    int num = q0.front();
                    q0.pop();
                    q1.push(num);
                }
                ans = q0.front();
                q0.pop();
            }

        }
        else if(cnt %2 == 1){
            if(peeked){
                ans = q1.front();
                q1.pop();
            }
            else{
                 while(q1.size()>1){
                    int num = q1.front();
                    q1.pop();
                    q0.push(num);
                }
                ans = q1.front();
                q1.pop();
            }
        }
        peeked = 0;
        cnt++;
        return ans;

    }
    
    int top() {
        int ans;
        if (cnt%2 == 0){
            if(peeked){
                ans = q0.front();
            }
            else{
                if(q0.size() == 1) ans = q0.front();
                while(q0.size()>1){
                    int num = q0.front();
                    q0.pop();
                    q1.push(num);
                }
                ans = q0.front();
                
            }
        }
        else if(cnt %2 == 1){
            if(peeked){
                ans = q1.front(); 
            }
            else{
                 if(q1.size() == 1) ans = q1.front();
                 while(q1.size()>1){
                    int num = q1.front();
                    q1.pop();
                    q0.push(num);
                }
                ans = q1.front();
               
            }
        }
        return ans;
    }
    
    bool empty() {
        if(q0.empty() && q1.empty()) return true;
        else return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */