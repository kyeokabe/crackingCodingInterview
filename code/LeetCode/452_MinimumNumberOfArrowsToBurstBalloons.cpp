class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        if(points.size()<=1)
            return points.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        int ans=0;
        sort(points.begin(),points.end(),[](const vector<int> &v1,const vector<int> &v2){return v1[0]==v2[0]?v1[1]<v2[1]:v1[0]<v2[0];});
        
        //for(int i=0;i<points.size();i++){
        //    cout<<points[i][0]<<","<<points[i][1]<<endl;
        //}
        
        for(int i=0;i<points.size();i++){
            if(pq.empty())
                pq.push(points[i][1]);
            else{
                //cout<<pq.top()<<endl;
                if(pq.top()>=points[i][0])
                    pq.push(points[i][1]);
                else{
                    while(!pq.empty())
                        pq.pop();
                    ans++;
                    pq.push(points[i][1]);
                }
            }
        }
        return ans+1;
    }
};
