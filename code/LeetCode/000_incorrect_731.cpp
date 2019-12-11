class MyCalendarTwo {
    
private:
    map<int,int> m1;
    map<int,int> m2;
    
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        bool fit_m1=true;
        auto it1=m1.begin();
        while(it1!=m1.end()){
            if(end<=it1->first)
                break;//will fit m1
            if(start>=it1->first&&start<it1->second){
                fit_m1=false;
                break;//cannot fit m1
            }
            if(end>it1->first&&end<=it1->second){
                fit_m1=false;
                break;//cannot fit m1
            }
            it1++;
        }
        if(fit_m1){
            m1[start]=end;
            return true;
        }
        
        bool fit_m2=true;
        auto it2=m2.begin();
        while(it2!=m2.end()){
            if(end<=it2->first)
                break; //will fit m2
            if(start>=it2->first&&start<it2->second){
                fit_m2=false;
                break; //cannot fit m2
            }
            if(end>it2->first&&end<=it2->second){
                fit_m2=false;
                break; //cannot fit m2
            }
            it2++;
        }
        if(fit_m2){
            m2[start]=end;
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
