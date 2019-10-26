class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        if(nums.size()==0||k==0)
            return ans;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        
        vector<int> f;
        vector<vector<int>> v(nums.size()+1,f);
        auto it=m.begin();
        while(it!=m.end()){
            v[it->second].push_back(it->first);
            it++;
        }
        
        int i=nums.size();
        while(k>0){
            for(int j=0;j<v[i].size();j++){
                ans.push_back(v[i][j]);
                k--;
                if(k==0)
                    break;
            }
            i--;
        }
        return ans;
    }
};
