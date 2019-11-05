//adapted from votrubac
//https://leetcode.com/problems/time-based-key-value-store/discuss/226664/C%2B%2B-3-lines-hash-map-%2B-map

//assume m[1]=7,m[4]=8,m[6]=13;
//learned auto it=m.upper_bound(5);
//it points to m[6]
//learded auto it2 = prev(it);

class TimeMap {
private:
    unordered_map<string,map<int,string>> m;
    
public:
    /** Initialize your data structure here. */
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        auto it=m.find(key);
        if(it==m.end()){
            map<int,string> m2;
            m2[timestamp]=value;
            m[key]=m2;
        }
        else{
            m[key][timestamp]=value;
        }
    }
    
    string get(string key, int timestamp) {
        auto it=m.find(key);
        if(it==m.end())
            return "";
        auto it2=(it->second).upper_bound(timestamp);
        if(it2==it->second.begin())
            return "";
        return prev(it2)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
