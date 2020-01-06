class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int Z=0;
        int Q=0;
        while(Q<nums.size()&&Z<nums.size()){
            while(Z<nums.size()&&nums[Z]!=0)
                Z++;
            Q=Z+1;
            while(Q<nums.size()&&nums[Q]==0)
                Q++;
            
            if(Q>=nums.size()||Z>=nums.size())
                break;
            swap(nums[Q],nums[Z]);
            Z=Z+1;
        }
    }
};
