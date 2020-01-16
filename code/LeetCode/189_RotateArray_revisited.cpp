class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        for(int i=0;i<(nums.size()-k)/2;i++)
            swap(nums[i],nums[nums.size()-1-k-i]);
        for(int i=0;i<k/2;i++)
            swap(nums[nums.size()-k+i],nums[nums.size()-1-i]);
        for(int i=0;i<nums.size()/2;i++)
            swap(nums[i],nums[nums.size()-1-i]);  
    }
};
