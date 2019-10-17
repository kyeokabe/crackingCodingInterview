class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int>> ans;
        vector<int> v2(1000,0);
        priority_queue<int, vector<int>, greater<int>> q;
        vector<priority_queue<int, vector<int>, greater<int>>> v;
        for(int i=0;i<1000;i++)
            v.push_back(q);
        
        for(int i=0;i<items.size();i++){
            v[items[i][0]-1].push(items[i][1]);
            v2[items[i][0]-1]+=items[i][1];
            if(v[items[i][0]-1].size()>5){
                v2[items[i][0]-1]-=v[items[i][0]-1].top();
                v[items[i][0]-1].pop();
            }
        }
        
        for(int i=0;i<1000;i++){
            if(v2[i]!=0){
                vector<int> v3;
                v3.push_back(i+1);
                v3.push_back(v2[i]/5);
                ans.push_back(v3);
            }
        }
        return ans;
    }
};
