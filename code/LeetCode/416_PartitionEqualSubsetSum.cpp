class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target=0;
        for(auto n:nums)
            target+=n;
        if(target%2==1)
            return false;
        target/=2;
        
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            vector<int> v={nums[i]};
            auto it=m.begin();
            while(it!=m.end()){
                v.push_back(it->first+nums[i]);
                it++;
            }
            for(int j=0;j<v.size();j++)
                m[v[j]]++;
        }
        auto it=m.find(target);
        if(it==m.end())
            return false;
        return true;
    }
};
