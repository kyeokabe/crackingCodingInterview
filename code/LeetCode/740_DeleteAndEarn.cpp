//https://leetcode.com/problems/delete-and-earn/discuss/109895/JavaC%2B%2B-Clean-Code-with-Explanation
//adapted from kvmial
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> v(10001,0);
        for(int i=0;i<nums.size();i++)
            v[nums[i]]+=nums[i];
        vector<int> DP(10001,0);
        DP[1]=v[1];
        //DP[2]=v[2];
        for(int i=2;i<10001;i++)
            DP[i]=max(DP[i-2]+v[i],DP[i-1]);
        
        return DP[10000];
    }
};
