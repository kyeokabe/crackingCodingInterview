class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()<=2){
            for(int i=0;i<nums.size();i++)
                if(nums[i]==target)
                    return i;
            return -1;
        }

        //first, do binary search to get pivot point
        int ptrl=0,ptrr=nums.size()-1;
        while(nums[ptrl]>nums[ptrr]&&(ptrr-ptrl>1)){
            int mid=(ptrr-ptrl)/2+ptrl;//prevent overflow
            if(nums[mid]<nums[ptrr])
                ptrr=mid;
            else
                ptrl=mid;
        }
        
        //case 1: no rotation
        if(ptrl==0&&ptrr==nums.size()-1)
            return binarysearch(nums,target,ptrl,ptrr);
        //case 2: target left of pivot
        if(target>=nums[0])
            return binarysearch(nums,target,0,ptrl);
        else //case 3: target right of pivot
            return binarysearch(nums,target,ptrr,nums.size()-1);
        
    }
    
    int binarysearch(vector<int>& nums, int target, int L, int R){
        if(nums[L]==target)
            return L;
        if(nums[R]==target)
            return R;
        while(L<R){
            
            int mid=(R-L)/2+L;
            
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                L=mid;
            else
                R=mid;
            
            if(R-L==1){
                if(nums[R]==target)
                    return R;
                else if(nums[L]==target)
                    return L;
                else
                    return -1;
            }
            
        }
        return -1; //will never execute
    }
    
};
