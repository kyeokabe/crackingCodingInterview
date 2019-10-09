class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size()<4)
            return ans;
        
        sort(nums.begin(),nums.end());

        unordered_map<int,int> m;
        map<vector<int>,int> m2;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]=i;
        
        
        for(int i=0;i<nums.size()-3;i++)
            for(int j=i+1;j<nums.size()-2;j++)
                for(int k=j+1;k<nums.size()-1;k++){
                    auto it=m.find(target-nums[i]-nums[j]-nums[k]);
                    if(it!=m.end()&&it->second>k){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(nums[it->second]);
                        auto it2=m2.find(temp);
                        if(it2==m2.end()){
                            ans.push_back(temp);
                            m2[temp]++;
                        }
                    }
                }
        
        return ans;
    }
};
