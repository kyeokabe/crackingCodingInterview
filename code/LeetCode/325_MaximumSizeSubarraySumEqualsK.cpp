class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if(nums.size()<=0)
            return 0;
        
        unordered_map<int,int> m;
        
        vector<int> v(nums.size(),0);
        v[0]=nums[0];
        m[nums[0]]=0;
        m[0]=-1;
        for(int i=1;i<nums.size();i++){
            v[i]=v[i-1]+nums[i];
            auto it=m.find(v[i]);
            if(it==m.end())
                m[v[i]]=i;
        }
        
        int res=0;
        vector<int> ans(nums.size(),0);
        for(int i=nums.size()-1;i>=0;i--){
            auto it=m.find(v[i]-k);
            if(it!=m.end()&&it->second<i){
                ans[i]=i-it->second;
                if(ans[i]>res)
                    res=ans[i];
            }
        }
        return res;
    }
};
