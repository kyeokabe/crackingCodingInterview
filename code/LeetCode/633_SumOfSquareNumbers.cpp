class Solution {
public:
    bool judgeSquareSum(int c) {
        double d=sqrt(INT_MAX);
        //cout<<d<<endl;
        
        unordered_map<int,int> m;
        
        for(int i=0;i<=int(d);i++)
            m[i*i]++;
        
        for(int i=0;i<=int(d);i++){
            auto it=m.find(c-i*i);
            if(it!=m.end())
                return true;
        }
        return false;
    }
};
