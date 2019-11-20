class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<int> foo(workers.size(),0);
        vector<vector<int>> v(bikes.size(),foo);
        //v[i][j] ... distance between bike i and worker j
        
        for(int i=0;i<bikes.size();i++)
            for(int j=0;j<workers.size();j++)
                v[i][j]=abs(workers[j][0]-bikes[i][0])+abs(workers[j][1]-bikes[i][1]);
        
        int ans=INT_MAX;
        vector<int> temp;
        //temp[i] represents the bike ID corresponding to worker ID i.
        int count=0;
        vector<int> BIKE(bikes.size(),0);
        for(int i=0;i<bikes.size();i++)
            BIKE[i]=i;
        
        vector<int> WORK(workers.size(),0);
        for(int i=0;i<workers.size();i++)
            WORK[i]=i;
        help(ans,v,temp,count,BIKE,WORK);
        return ans;
    }
    
    void help(int &ans,vector<vector<int>> &v,vector<int> &temp,int &count,vector<int> &BIKE,vector<int> &WORK){
        if(count>ans)
            return;
        if(temp.size()==WORK.size()){
            if(count<ans)
                ans=count;
            return;
        }
        
        for(int i=0;i<BIKE.size();i++){
            temp.push_back(BIKE[i]);
            count+=v[BIKE[i]][temp.size()-1];
            int bar=BIKE[i];
            swap(BIKE[i],BIKE[BIKE.size()-1]);
            BIKE.pop_back();
            help(ans,v,temp,count,BIKE,WORK);
            BIKE.push_back(bar);
            swap(BIKE[i],BIKE[BIKE.size()-1]);
            count-=v[BIKE[i]][temp.size()-1];
            temp.pop_back();
        }
    }
};

/*

right 5
up    3

right 3
up 1

*/
