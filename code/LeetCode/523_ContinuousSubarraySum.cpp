class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(k<0)
            k=abs(k);
        if(k==0){
            for(int i=1;i<nums.size();i++)
                if(nums[i]==0&&nums[i-1]==0)
                    return true;
            return false;
        }
        
        unordered_map<int,int> m;
        vector<int> v(nums.size(),0);
        v[0]=nums[0]%k;
        m[v[0]]=0;
        for(int i=1;i<nums.size();i++){
            if((nums[i]+nums[i-1])%k==0)
                return true;
            v[i]=(v[i-1]+nums[i])%k;
            if(v[i]==0)
                return true;
            auto it=m.find(v[i]);
            if(it==m.end())
                m[v[i]]=i;
            else
                if(i-it->second>1)
                    return true;
        }
        return false;
    }
};
