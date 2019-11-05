class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans=0;
        if(timeSeries.size()==0)
            return ans;
        if(timeSeries.size()>=2){
            for(int i=1;i<timeSeries.size();i++){
                ans+=min(timeSeries[i]-timeSeries[i-1],duration);
            }
        }
        ans+=duration;
        return ans;
    }
};
