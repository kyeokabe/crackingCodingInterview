class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans={0,0};
        int k=0;
        for (int i=0;i<nums.size();i++)
            k=k^nums[i];
        int mindigit=k&(-k);
        for (int i=0;i<nums.size();i++){
            if (nums[i]&mindigit)
                ans[0]=ans[0]^nums[i];
            else
                ans[1]=ans[1]^nums[i];
        }
        return ans;
    }
};
