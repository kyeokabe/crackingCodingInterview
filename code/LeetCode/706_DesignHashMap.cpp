class MyHashMap {
private:
    vector<int> v;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        vector<int> v2(pow(10,6)+1,-1);
        v=v2;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        v[key]=value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        if(v[key]==-1)
            return -1;
        else
            return v[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        if(v[key]!=-1)
            v[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
