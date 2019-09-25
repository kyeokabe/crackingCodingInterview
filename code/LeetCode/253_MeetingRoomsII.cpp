//Ot ... nlog(n)
//Om ... nlog(n)

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int maxrooms=0;
        
        int vacant=0;
        int occupied=0;
        int totalroom=0;
        vector<int> endtime;
        
        for(int i=0;i<intervals.size();i++){
            
            while (endtime.size()>0&&endtime[0]<=intervals[i][0]){
                endtime[0]=endtime[endtime.size()-1];
                endtime.pop_back();
                sort(endtime.begin(),endtime.end());
                vacant+=1;
                occupied-=1;
            }
            
            if(vacant==0){
                totalroom+=1;
                occupied+=1;
                endtime.push_back(intervals[i][1]);
                sort(endtime.begin(),endtime.end());
            }
            
            else{
                vacant-=1;
                occupied+=1;
                endtime.push_back(intervals[i][1]);
                sort(endtime.begin(),endtime.end());
            }
            
        }
        return totalroom;
    }
};
