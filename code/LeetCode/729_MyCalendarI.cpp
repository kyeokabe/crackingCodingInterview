class MyCalendar {
    
private:
    map<int,int> m;
    
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        m[start]++;
        m[end]--;
        auto it=m.begin();
        int book=0;
        while(it!=m.end()){
            book+=it->second;
            if(book==2){
                m[start]--;
                m[end]++;
                return false;
            }
            it++;
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
