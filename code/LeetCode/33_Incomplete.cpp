class Solution {
public:
    int search(vector<int>& nums, int target) {
        int SIZE=nums.size();
        if (SIZE==0)
            return -1;
        if (SIZE==1)
            if (target==nums[0])
                return target;
            else
                return -1;
        
        //gets index of end of 1st half
        int end=binarySearch(nums);
        
        cout <<end<<endl;
        
        return 0;
    }
    
    int regularBinary(vector<int> &nums, target){
        int i=0;
        
    }
    
    int binarySearch(vector<int> &nums){
        int k=nums.size()-1;    
        if (nums[k]<nums[k-1]) 
            return k-1;
        
        int count=-1;
        while(nums[k]>nums[k-1]){
            if (nums[0]>nums[k]){
                k=k-nums.size()*pow(2,count);
                count--;
            }
            else{
                k=k+nums.size()*pow(2,count);
            }
        }
        return k;
    }
};
