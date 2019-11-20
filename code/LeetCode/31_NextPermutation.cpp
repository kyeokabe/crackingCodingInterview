class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1)
            return;
        int ptr1=nums.size()-2;
        while(ptr1>=0&&nums[ptr1]>=nums[ptr1+1]){
            ptr1--;
        }
        if(ptr1==-1){
            sort(nums.begin(),nums.end());
            return;
        }
        int nums2=INT_MAX;
        int ptr3=0;
        int ptr2=nums.size()-1;

        while(ptr2>ptr1){
            if(nums[ptr2]>nums[ptr1]&&nums[ptr2]<nums2){
                nums2=nums[ptr2];
                ptr3=ptr2;
            }
            ptr2--;
        }
        
        swap(nums[ptr1],nums[ptr3]);

        for(int i=ptr1+1;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]>nums[j])
                    swap(nums[i],nums[j]);
            }
        }    
        //sort(nums.begin()+ptr1+1,nums.end());
        return;
    }
};
