class Solution {
public:
    
    
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int globalmax=nums[0];
        int globalmin=nums[0];
        
        for(int i=1, localmax=nums[0], localmin=nums[0];i<nums.size();i++){
            if(nums[i]<0){
                int temp=localmax;
                localmax=localmin;
                localmin=temp;
            }
            localmax=max(nums[i]*localmax,nums[i]);
            localmin=min(nums[i]*localmin,nums[i]);
            
            globalmax=max(globalmax,localmax);
        }
        return globalmax;
    }
};
