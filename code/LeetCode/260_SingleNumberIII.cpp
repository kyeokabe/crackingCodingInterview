class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //https://leetcode.com/problems/single-number-iii/discuss/68924/3-lines-Ruby-4-lines-C%2B%2B
        //solution adapted from Stefan Pochmann
        int k=0;
        vector<int> ans={0,0};
        for (int i=0;i<nums.size();i++)
            k=k^nums[i];
        int LBit=k&(-k);//this is a trick to get least "1" bit. Ref 2's compliment
        for (int i=0;i<nums.size();i++){
            if(nums[i]&LBit)//note that this behaves as bool. if any bits shared, true
                ans[0]=ans[0]^nums[i];
            else
                ans[1]=ans[1]^nums[i];
        }
        return ans;
    }
};
