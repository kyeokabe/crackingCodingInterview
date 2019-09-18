class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        if(days.size()==0)
            return 0;
        int i=0;
        //v[i] stores the minimum cost for days[i]
        vector<int> v(days.size(),INT_MIN);
        return mincost(i,days,costs,v);
    }
    
    int mincost(int i, vector<int>& days, vector<int>& costs, vector<int> &v){
        if(i>=days.size())
            return 0;
        
        if(v[i]!=INT_MIN)
            return v[i];
        
        else{
        
            //calculate cost of buying 1 day pass
            //starting on day i
            int cost1=costs[0]+mincost(i+1,days,costs,v);
       
            //calculate cost of buying 7 day pass
            //starting on day i
            int day7=days[i]+7-1;
            int i7=i;
            for(int j=i;j<days.size();j++){
                if(days[j]<=day7)
                    i7++;
            }
            int cost7=costs[1]+mincost(i7,days,costs,v);
        
            //calculate cost of buying 30 day pass
            //starting on day i
            int day30=days[i]+30-1;
            int i30=i;
            for(int j=i;j<days.size();j++){
                if(days[j]<=day30)
                    i30++;
            }
            int cost30=costs[2]+mincost(i30,days,costs,v);
            
            //store minimum cost for day i in vector v
            v[i]=min(min(cost1,cost7),cost30);
            return v[i];
        }
    }
    
};

/*

************************************************
* timeout solution without DP (pure recursive) *
************************************************

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        if(days.size()==0)
            return 0;
        int i=0;
        return mincost(i,days,costs);
    }
    
    int mincost(int i, vector<int>& days, vector<int>& costs){
        if(i>=days.size())
            return 0;
        
        //calculate cost of buying 1 day pass
        //starting on day i
        int cost1=costs[0]+mincost(i+1,days,costs);
       
        //calculate cost of buying 7 day pass
        //starting on day i
        int day7=days[i]+7-1;
        int i7=i;
        for(int j=i;j<days.size();j++){
            if(days[j]<=day7)
                i7++;
        }
        int cost7=costs[1]+mincost(i7,days,costs);
        
        //calculate cost of buying 30 day pass
        //starting on day i
        int day30=days[i]+30-1;
        int i30=i;
        for(int j=i;j<days.size();j++){
            if(days[j]<=day30)
                i30++;
        }
        int cost30=costs[2]+mincost(i30,days,costs);
        
        //return the minimum cost of the three options
        return min(min(cost1,cost7),cost30);
    }
    
};

*/
