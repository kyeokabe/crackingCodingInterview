class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count=0;
        
        vector<int> foo;
        for(int i=0;i<60;i++)
            foo.push_back(0);
        
        for (int i=0;i<time.size();i++)
            foo[time[i]%60]++;
        
        for(int i=1;i<=29;i++)
            count+=foo[i]*foo[60-i];
        
        if (foo[0]>0)
            count+=(foo[0]*(foo[0]-1))/2;
        
        if (foo[30]>0)
            count+=(foo[30]*(foo[30]-1))/2;
            
        return count;
    }
};
