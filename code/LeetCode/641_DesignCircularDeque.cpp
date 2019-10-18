class MyCircularDeque {
private:
    int K;
    list<int> l;
    
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        K=k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(l.size()==K)
            return false;
        l.push_front(value);
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(l.size()==K)
            return false;
        l.push_back(value);
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(l.size()==0)
            return false;
        l.pop_front();
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(l.size()==0)
            return false;
        l.pop_back();
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(l.empty())
            return -1;
        return l.front();
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(l.empty())
            return -1;
        return l.back();
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return l.empty();
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (l.size()==K);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
