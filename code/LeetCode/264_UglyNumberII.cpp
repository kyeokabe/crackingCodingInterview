class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);//10
        v.push_back(3);//6
        v.push_back(4);
        v.push_back(5);
        
        if(n+1<v.size())
            return v[n-1];
        int ptr2=2;
        int ptr3=1;
        int ptr5=1;
        
        int count=5;
        
        while(count<n){
            int temp=min(v[ptr5]*5,min(v[ptr2]*2,v[ptr3]*3));
            v.push_back(temp);
            while(v[ptr2]*2<=temp)
                ++ptr2;
            while(v[ptr3]*3<=temp)
                ++ptr3;
            while(v[ptr5]*5<=temp)
                ++ptr5;
            ++count;
        }
        return v[n-1];
    }
};
