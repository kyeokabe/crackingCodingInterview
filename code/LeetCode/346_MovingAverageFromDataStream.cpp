class MovingAverage {
private:
    queue<int> q;
    int SIZE;
    double sum;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        SIZE=size;
    }
    
    double next(int val) {
        if(q.size()>=SIZE){
            sum-=q.front();
            q.pop();
        }
        sum+=val;
        q.push(val);
        return sum/q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
