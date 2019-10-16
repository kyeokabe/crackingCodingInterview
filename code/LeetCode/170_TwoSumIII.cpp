class TwoSum {
    
private:
    unordered_map<int,set<int>> m;
    int count;
    
public:
    /** Initialize your data structure here. */
    TwoSum() {
        count=0;
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        auto it=m.find(number);
        if(it!=m.end()){
            it->second.insert(count);
        }
        else{
            set<int> s;
            s.insert(count);
            m[number]=s;
        }
        count++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        auto it=m.begin();
        while(it!=m.end()){
            auto it2=m.find(value-it->first);
            if(it2!=m.end()&&(it2!=it||it2->second.size()>1))
                return true;
            it++;
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
