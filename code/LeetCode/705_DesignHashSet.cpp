class MyHashSet {
private:
    vector<int> v;
    
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        vector<int> temp(1000001,0);
        v=temp;
    }
    
    void add(int key) {
        v[key]=1;
    }
    
    void remove(int key) {
        v[key]=0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        if(v[key]==1)
            return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
