class LRUCache {
private:

    unordered_map<int,list<int>::iterator> m;
    unordered_map<int,list<int>::iterator> m_keys;

    list<int> list_vals;
    list<int> list_keys;
    int CAP;
    
    
public:
    LRUCache(int capacity) {
        CAP=capacity;
    }
    
    int get(int key) {
        auto it=m.find(key);
        if(it==m.end())
            return -1;
        else{
            //bring both lists to front
            //remap for both
            //return val;
            int temp_val = *(it->second);
            list_vals.erase(it->second);
            list_vals.push_front(temp_val);
            auto it2=list_vals.begin();
            m[key]=it2;
            
            auto it3=m_keys.find(key);
            list_keys.erase(it3->second);
            list_keys.push_front(key);
            auto it4=list_keys.begin();
            m_keys[key]=it4;
            
            return temp_val;
        }
    }
    
    void put(int key, int value) {
        auto it=m.find(key);
        if(it==m.end()){
            if(list_keys.size()==CAP){
                //erase last element in both lists
                //erase both mappings
                list_vals.pop_back();
                m.erase(list_keys.back());
                m_keys.erase(list_keys.back());
                list_keys.pop_back();
            }
            list_vals.push_front(value);
            list_keys.push_front(key);
            auto it2=list_vals.begin();
            m[key]=it2;
            auto it3=list_keys.begin();
            m_keys[key]=it3;
        }
        else{
            //erase from list_keys
            //m_keys[key] will be overwritten
            auto it2=m_keys.find(key);
            list_keys.erase(it2->second);
            
            //erase from list_vals
            //m[key] will be overwritten
            auto it3=m.find(key);
            list_vals.erase(it3->second);
            
            //push_front into list_vals
            //link to hashmap
            list_vals.push_front(value);
            auto it4=list_vals.begin();
            m[key]=it4;
      
            //push_front into list_keys
            //link to hashmap
            list_keys.push_front(key);
            auto it5=list_keys.begin();
            m_keys[key]=it5;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
