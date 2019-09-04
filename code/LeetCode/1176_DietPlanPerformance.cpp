class Solution {
public:
    int dietPlanPerformance(vector<int>& c, int k, int lower, int upper) {
        if(c.size()==0||k>c.size())
            return 0;
        int ptr1=0;
        int ptr2=0;
        int sum=0;
        int ans=0;
        for(int i=0;i<=k-1;i++)
            sum+=c[ptr2++];
        
        if(sum>upper)
            ans+=1;
        if(sum<lower)
            ans-=1;
        
        while(ptr2<=c.size()-1){
            sum-=c[ptr1++];
            sum+=c[ptr2++];
            if(sum>upper)
                ans+=1;
            if(sum<lower)
                ans-=1;
        }
        return ans;
    }
};
