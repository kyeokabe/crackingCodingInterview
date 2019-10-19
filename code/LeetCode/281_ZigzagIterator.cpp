class ZigzagIterator {
private:
    int ptr1;
    int ptr2;
    int count;
    int v1size;
    int v2size;
    vector<int> V1;
    vector<int> V2;
    
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {

        V1=v1;
        V2=v2;
        ptr1=0;
        ptr2=0;
        count=0;
        v1size=v1.size();
        v2size=v2.size();
    }

    int next() {
        
        if(count%2==0){
            if(ptr1<v1size){
                int temp=V1[ptr1];
                ptr1++;
                count++;
                return temp;
            }
            else{
                int temp=V2[ptr2];
                ptr2++;
                count++;
                return temp;
            }
        }
        else{
            if(ptr2<v2size){
                int temp=V2[ptr2];
                ptr2++;
                count++;
                return temp;
            }
            else{
                int temp=V1[ptr1];
                ptr1++;
                count++;
                return temp;
            }
        }
        return 0;
    }

    bool hasNext() {
        if(ptr1>=v1size&&ptr2>=v2size)
            return false;
        return true;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
