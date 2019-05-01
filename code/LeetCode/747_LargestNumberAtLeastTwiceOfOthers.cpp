class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        vector<int> nums2=nums;
        sort(nums2.begin(),nums2.end());
        if(nums2[nums2.size()-1]>=2*nums2[nums2.size()-2]){
            for (int i=0;i<nums.size();i++)
                if (nums[i]==nums2[nums2.size()-1])
                    return i;
        }
        return -1;
    }
};
