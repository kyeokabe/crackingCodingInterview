class MyCircularQueue {
private:
    int K;
    list<int> l;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        K=k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(l.size()==K)
            return false;
        else
            l.push_back(value);
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(l.size()!=0){
            l.pop_front();
            return true;
        }
        else
            return false;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(l.empty())
            return -1;
        return l.front();
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(l.empty())
            return -1;
        return l.back();
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return l.empty();
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if(l.size()==K)
            return true;
        return false;
    }
    
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
