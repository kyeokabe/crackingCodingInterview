/*
Very nice problem. Good practice for learning DP. Revisit if time permits!
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==0)
            return 0;
        if (nums.size()==1)
            return nums[0];
        if (nums.size()==2)
            return max(nums[1],nums[0]);
        int money=0;
        int n=nums.size();
        vector<int> doe;
        for (int i=0;i<n;i++){
            doe.push_back(-1);
        }
        money=helper(nums,n,doe);
        return money;
    }
    
    int helper(vector<int> &nums, int n, vector<int> &doe){
        if (n==0)
            return 0;
        
        if (doe[n-1]!=-1)
            return doe[n-1];
        
        if (n==1){
            doe[0]=nums[0];
            return doe[0];
            }
        
        if (n==2){
            doe[1]=max(nums[0],nums[1]);
            return doe[1];
        }
        doe[n-1]=max(nums[n-1]+helper(nums,n-2,doe),helper(nums,n-1,doe));
        return doe[n-1];
    }
    
};
