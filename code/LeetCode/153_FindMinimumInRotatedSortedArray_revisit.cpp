class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()<2)
            return nums[0];
        
        if(nums[0]<nums[nums.size()-1])
            return nums[0];
        int min=0;
        int max=nums.size()-1;
        while(min<max){
            int half=(min+max)/2;
            if(nums[min]<nums[half])
                min=half;
            else
                max=half;
        }
        return nums[min+1];
    }
};
