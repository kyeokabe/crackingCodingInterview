class MyCalendarThree {
private:
    map<int,int> m;
    
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        auto it=m.begin();
        int ans=0;
        int book=0;
        while(it!=m.end()){
            book+=it->second;
            if(ans<book)
                ans=book;
            it++;
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
