class FreqStack {
private:
    unordered_map<int,int> m1; //element to highest frequency
    map<int,vector<int>> m2; //frequency to element
    
public:
    FreqStack() {
        
    }
    
    void push(int x) {
        m1[x]++;
        auto it2=m2.find(m1[x]);
        if(it2==m2.end()){
            vector<int> v={x};
            m2[m1[x]]=v;
        }
        else
            m2[m1[x]].push_back(x);
    }
    
    int pop() {
        auto it=m2.rbegin();
        int ans=it->second.back();
        it->second.pop_back();
        if(it->second.size()==0)
            m2.erase(it->first);
        m1[ans]--;
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
