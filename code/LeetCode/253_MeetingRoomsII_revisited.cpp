class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int,int> m;
        for(int i=0;i<intervals.size();i++){
            m[intervals[i][0]]++;
            m[intervals[i][1]]--;
        }
        int count=0;
        int ans=0;
        auto it=m.begin();
        while(it!=m.end()){
            count+=it->second;
            if(ans<count)
                ans=count;
            it++;
        }
        return ans;
    }
};
