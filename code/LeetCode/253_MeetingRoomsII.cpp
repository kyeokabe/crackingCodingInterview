//Ot ... nlog(n)
//Om ... nlog(n) //comment on 10/11/2019 ... is this right? seems like O(n) at first glance

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


/*
//New solution added 10/11/2019
//O(nlog(n)) time
//O(n) memory
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        //sort(intervals.begin(),intervals.end(),[](const &vector<int> v1, const &vector<int> v2){return (v1[0]<v2[0]);});
        sort(intervals.begin(),intervals.end());
        int UsedRoom=0;
        int MaxRoom=0;
        priority_queue<int,vector<int>, greater<int>> q;
        for(int i=0;i<intervals.size();i++){
            if(q.empty()){
                UsedRoom++;
                if(MaxRoom<UsedRoom)
                    MaxRoom=UsedRoom;
                q.push(intervals[i][1]);
            }
            else{
                if(q.top()<=intervals[i][0]){
                    while(!q.empty()&&q.top()<=intervals[i][0]){
                        q.pop();
                        UsedRoom--;
                    }
                    q.push(intervals[i][1]);
                    UsedRoom++;
                }
                else{
                    UsedRoom++;
                    if(MaxRoom<UsedRoom)
                        MaxRoom=UsedRoom;
                    q.push(intervals[i][1]);
                }
            }  
        }
        return MaxRoom;
    }
};
*/
