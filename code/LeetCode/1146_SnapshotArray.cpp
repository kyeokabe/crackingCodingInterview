class SnapshotArray {
private:
    unordered_map<int,map<int,int>> m;
    int snap_id;
    
public:
    SnapshotArray(int length) {
        snap_id=0;
        map<int,int> m2;
        m2[snap_id]=0;

        for(int i=0;i<length;i++)
            m[i]=m2;
    }
    
    void set(int index, int val) {
        auto it=m.find(index);
        auto it2=it->second.find(snap_id);
        if(it2!=it->second.end()){
            it2->second=val;
        }
        else{
            m[index][snap_id]=val;
        }
    }
    
    int snap() {
        snap_id++;
        return snap_id-1;
    }
    
    int get(int index, int snap_id) {
        auto it=m.find(index);
        auto it2=it->second.find(snap_id);
        if(it2!=it->second.end())
            return it2->second;
        else{
            auto it3=it->second.begin();
            while(it3!=it->second.end()&&it3->first<snap_id)
                it3++;
            it3--;
            return it3->second;
        }
    }
};
