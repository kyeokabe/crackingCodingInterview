class MedianFinder {
private:
    multiset<int> s;
    multiset<int>::iterator it;
    
    
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(s.size()==0){
            s.insert(num);
            it=s.begin();
        }
        else{
            s.insert(num);
            if(s.size()%2==1&&num>=*it){
                it++;
            }
            else if(s.size()%2==1&&num<*it){
                //do nothing
            }
            else if(s.size()%2==0&&num>=*it){
                //do nothing
            }
            else{
                it--;
            }
        }
        
    }
    
    double findMedian() {
        if(s.size()%2==1)
            return double(*it);
        else{
            return double(*it+*next(it))/2;
        }
    }
};

