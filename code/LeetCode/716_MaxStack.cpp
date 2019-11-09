class MaxStack {
private:
    map<int,vector<list<int>::iterator>> m;
    list<int> lst;
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        lst.push_back(x);
        auto it=prev(lst.end());
        auto it2=m.find(x);
        if(it2!=m.end()){
            it2->second.push_back(it);
        }
        else{
            vector<list<int>::iterator> v={it};
            m[x]=v;
        }
        return;
    }
    
    int pop() {
        auto it=prev(lst.end());
        int ans=*it;
        auto it2=m.find(*it);
        it2->second.pop_back();
        if(it2->second.size()==0)
            m.erase(it2->first);
        lst.erase(it);
        return ans;
    }
    
    int top() {
        return lst.back();
    }
    
    int peekMax() {
        auto it=m.rbegin();
        return it->first;
    }
    
    int popMax() {
        auto it=m.rbegin();
        int ans=it->first;
        
        auto it3=it->second.back();
        lst.erase(it3);
        it->second.pop_back();
        if(it->second.size()==0)
            m.erase(it->first);
        return ans;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
