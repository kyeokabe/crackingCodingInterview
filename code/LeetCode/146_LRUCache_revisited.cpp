class LRUCache {
private:
    list<int> lst;//contains values
    unordered_map<int,pair<int,list<int>::iterator>> m;
    int cap;
    
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(m.find(key)==m.end())
            return -1;
        int val=m[key].first;
        lst.erase(m[key].second);
        lst.push_front(key);
        auto it=lst.begin();
        pair<int,list<int>::iterator> p={val,it};
        m[key]=p;
        return m[key].first;
    }
    
    void put(int key, int value) {
        if(m.find(key)==m.end()){
            if(lst.size()==cap){
                int key2=lst.back();
                m.erase(key2);
                lst.pop_back();
            }
            lst.push_front(key);
            auto it=lst.begin();
            pair<int,list<int>::iterator> p={value,it};
            m[key]=p;
        }
        else if(m.find(key)!=m.end()){
            auto it3=m[key].second;
            pair<int,list<int>::iterator> p={value,it3};
            m[key]=p;
            get(key);
        }
    }
};
