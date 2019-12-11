class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        if(position.size()<=1)
            return position.size();
        
        vector<vector<int>> v;

        for(int i=0;i<position.size();i++){
            vector<int> temp={position[i],speed[i]};
            v.push_back(temp);
        }
        
        sort(v.begin(),v.end());
        int i=v.size()-2;
        int ans=1;
        double time=double(target-v[i+1][0])/double(v[i+1][1]);
        while(i>=0){
            double temp_time=double(target-v[i][0])/double(v[i][1]);
            if(temp_time>time){
                time=temp_time;
                ans++;
            }
            i--;
        }
        return ans;
    }
};

//0     3     5     8     9     10
//1     3     1     4     4     2
//12    3     7     1    0.75   1
