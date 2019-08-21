class Solution {
public:
    int nthUglyNumber(int n) {
        if (n<=0)
            return 0;
        
        int ptr2=1;
        int ptr3=1;
        int ptr5=0;

        vector <int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        
        while(v.size()<n){
            int temp=min(5*v[ptr5],3*v[ptr3]);
            temp=min(temp,2*v[ptr2]);
            
            v.push_back(temp);
            if(5*v[ptr5]<=temp)
                ptr5=ptr5+1;
            if(3*v[ptr3]<=temp)
                ptr3=ptr3+1;
            if(2*v[ptr2]<=temp)
                ptr2=ptr2+1;
        }
        return v[n-1];
    }
};
