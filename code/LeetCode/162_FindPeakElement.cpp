class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return 0;
        int LOW=0;
        int HI=nums.size()-1;
        while(LOW<HI){
            int MID=(HI+LOW)/2;
            if(nums[MID]>nums[MID+1]){
                HI=MID;
            }
            else
                LOW=MID+1;
        }
        return LOW;
    }
};

//1 3 5 4
//L     H
//    L H
//    M  
