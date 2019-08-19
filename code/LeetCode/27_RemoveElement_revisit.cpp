class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index=0;
        int num_val=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val)
                num_val++;
            else{
                nums[index]=nums[i];
                index++;
            }
        }
        return nums.size()-num_val;
    }
};
