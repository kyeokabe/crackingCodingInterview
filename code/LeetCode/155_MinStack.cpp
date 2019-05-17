class MinStack {
    
private:
    stack<int> s1;
    stack<int> s2;
    
public:
    /** initialize your data structure here. */
    MinStack() {
        while(!s1.empty())
            s1.pop();
        while(!s2.empty())
            s2.pop();

    }
    
    void push(int x) {
        s1.push(x);
        if(s2.empty())
            s2.push(x);
        else
            if(s2.top()>=x){
                s2.push(x);
            }
        //8 7 5 3 5 2
        //8 7 5 3   2
    }
    
    void pop() {
        if(s1.empty())
            return;
        else{
            int temp=s1.top();
            s1.pop();
            if(s2.top()==temp)
                s2.pop();
        }
        
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
