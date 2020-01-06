class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size()<=1)
            return true;
        sort(intervals.begin(),intervals.end());
        for(int i=1;i<intervals.size();i++)
            if(intervals[i][0]<intervals[i-1][1])
                if(intervals[i-1][0]<intervals[i][1])
                    return false;
        return true;
    }
};
