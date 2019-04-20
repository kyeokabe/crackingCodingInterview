class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        map <int,int> m;
        int ans=helper(nums,target,m);
        return ans;
    }
    
    int helper(vector<int>& nums, int target, map <int,int> &m){
        auto it=m.find(target);
        if(it!=m.end())
            return it->second;
        if (target==0)
            return 1;
        if (target<0)
            return 0;
        int count=0;
        for (int i=0;i<nums.size();i++){
            count+=helper(nums,target-nums[i],m);
        }
        m[target]=count;
        return count;
    }
    
};
