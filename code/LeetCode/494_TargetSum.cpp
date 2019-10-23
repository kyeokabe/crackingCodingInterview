//adapred from
//https://leetcode.com/problems/target-sum/discuss/97335/Short-Java-DP-Solution-with-Explanation
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        if(sum<S||-sum>S)
            return 0;
        
        vector<int> v1(nums.size(),0);
        vector<vector<int>> v(2*sum+1,v1);
        
        v[+nums[0]+sum][0]++;
        v[-nums[0]+sum][0]++;
        
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<2*sum+1;j++){
                if(j+nums[i]<2*sum+1)
                    v[j+nums[i]][i]+=v[j][i-1];
                if(j-nums[i]>=0)
                    v[j-nums[i]][i]+=v[j][i-1];
        
            }
        }
        return int(v[S+sum][nums.size()-1]);
    }
};

/*
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
*/
