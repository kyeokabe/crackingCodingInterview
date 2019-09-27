class RandomizedSet {
private:
    unordered_map<int,int> m;
    vector<int> v;
    int size;
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        size=0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto it=m.find(val);
        if(it==m.end()){
            v.push_back(val);
            m[val]=size;
            size++;
            return true;
        }
        else
            return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it=m.find(val);
        if(it!=m.end()){
            v[it->second]=v[size-1];
            v.pop_back();
            auto it2=m.find(v[it->second]);
            it2->second=it->second;
            m.erase(val);
            size--;
            return true;
        }
        else
            return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return v[rand()%(size)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
