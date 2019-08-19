class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int num_z=0;
        int ind=0;
        for (int i=0;i<nums.size();i++){
            if(nums[i]==0)
                num_z++;
            else{
                nums[ind]=nums[i];
                ind++;
            }
        }
        int j=0;
        while (num_z!=0){
            nums[nums.size()-1-j]=0;
            j++;
            num_z--;
        }
    }
};
