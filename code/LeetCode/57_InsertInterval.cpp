class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval2) {
        vector<vector<int>> ans;
        int i=0;
        int j=0;
        vector<vector<int>> newInterval={newInterval2};
        while(i<intervals.size()&&j<newInterval.size()){
            if(intervals[i][0]<=newInterval[j][1]&&intervals[i][1]>=newInterval[j][0]){
                intervals[i][0]=min(intervals[i][0],newInterval[j][0]);
                intervals[i][1]=max(intervals[i][1],newInterval[j][1]);
                j++;
            }
            else{
                if(intervals[i][0]<newInterval[j][0]){
                    ans.push_back(intervals[i]);
                    i++;
                }
                else{
                    ans.push_back(newInterval[j]);
                    j++;
                }
            }
        }
        while(i<intervals.size()){
            ans.push_back(intervals[i]);
            i++;
        }
        while(j<newInterval.size()){
            ans.push_back(newInterval[j]);
            j++;
        }
        
        
        //
        
        vector<vector<int>> ans2;
        if(ans.size()==0)
            return ans;

        for(int i=1;i<ans.size();i++){
            if(ans[i-1][1]>=ans[i][0]&&ans[i-1][0]<=ans[i][1]){
                ans[i][0]=min(ans[i-1][0],ans[i][0]);
                ans[i][1]=max(ans[i-1][1],ans[i][1]);
            }
            else
                ans2.push_back(ans[i-1]);
        }
        ans2.push_back(ans.back());
        return ans2; 
        
    }
};
