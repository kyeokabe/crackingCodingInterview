class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int K) {
        int temp_num=nums[0];
        int temp_dup=1;
        int dup=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==temp_num){
                temp_dup++;
                if(temp_dup>dup)
                    dup=temp_dup;
            }
            else{
                temp_num=nums[i];
                temp_dup=1;
            }
        }
        
        if(K<=nums.size()/dup)
            return true;
        return false;
    }
};
