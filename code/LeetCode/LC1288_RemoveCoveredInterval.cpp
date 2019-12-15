class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()<=1)
            return intervals.size();
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size()-1;i++)
            if(intervals[i][0]==intervals[i+1][0])
                if(intervals[i][1]<intervals[i+1][1]){
                    swap(intervals[i],intervals[i+1]);
                    while(i>=0&&intervals[i][0]==intervals[i+1][0])
                        i--;
                }
        int ans=1;
        int Rmax=intervals[0][1];
        
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][1]<=Rmax){
                //do nothing
            }
            else{
                Rmax=max(intervals[i][1],Rmax);
                ans++;
            }
        }
        return ans;
    }
};
