class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int ans=0;
        int sum=0;
        int j=0;
        help(nums,j,sum,S,ans);
        return ans;
    }
    
    void help(vector<int>& nums, int j, int &sum,int S,int &ans){
        if(j==nums.size()&&sum==S){
            ans++;
            return;
        }
        if(j<nums.size()){
            sum+=nums[j];
            help(nums,j+1,sum,S,ans);
            sum-=(2*nums[j]);
            help(nums,j+1,sum,S,ans);
            sum+=nums[j];
        }
    }
};
