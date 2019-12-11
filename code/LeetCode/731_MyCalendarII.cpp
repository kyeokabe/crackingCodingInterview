//adapted from otoc
//https://leetcode.com/problems/my-calendar-ii/discuss/323479/Simple-C%2B%2B-Solution-using-built-in-map-(Same-as-253.-Meeting-Rooms-II)

class MyCalendarTwo {

private:
    map<int,int> m;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        m[start]++;
        m[end]--;
        auto it=m.begin();
        int booked=0;
        while(it!=m.end()){
            booked+=it->second;
            if(booked==3){
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
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
