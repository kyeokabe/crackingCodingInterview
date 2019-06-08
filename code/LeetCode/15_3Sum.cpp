class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //adapted from shpolsky
        //https://leetcode.com/problems/3sum/discuss/7380/Concise-O(N2)-Java-solution
        vector<vector<int>> ans;
        if(nums.size()<3)
            return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i==0||i>0&&(nums[i-1]!=nums[i])){
                int LO=i+1;
                int HI=nums.size()-1;
                while(LO<HI){
                    if(nums[i]+nums[LO]+nums[HI]==0){
                        vector<int> foo={nums[i],nums[LO],nums[HI]};
                        ans.push_back(foo);
                        while(LO<HI&&nums[LO]==nums[LO+1])
                            ++LO;
                        while(LO<HI&&nums[HI]==nums[HI-1])
                            --HI;
                        ++LO;
                        --HI;
                    }
                    else if(nums[LO]+nums[HI]<-nums[i])
                        ++LO;
                    else
                        --HI;
                }
            }
        }
        return ans;
    }
};
