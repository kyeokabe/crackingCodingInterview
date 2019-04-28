class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k>nums.size())
            k=k%nums.size();
        vector<int> a;
        a=nums;
        
        for(int i=0;i<k;i++)
            nums[i]=a[nums.size()-k+i];
        
        for(int i=k;i<nums.size();i++)
            nums[i]=a[i-k];
    }
};
