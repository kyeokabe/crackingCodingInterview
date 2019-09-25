class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size()<=1)
            return true;
        sort(intervals.begin(),intervals.end());
        int endtime=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<endtime)
                return false;
            endtime=intervals[i][1];
        }
        return true;
    }
};
