class Solution {
public:
    bool canJump(vector<int>& nums) {
    
        vector<int> zeroindex;
        for(int i=0;i<nums.size()-1;i++)
            if(nums[i]==0)
                zeroindex.push_back(i);
        
        for(int i=0;i<zeroindex.size();i++){
            int j=zeroindex[i];
            int count=0;
            while(nums[j]<=count){
                j--;
                count++;
                if(j==-1)
                    return false;
            }
        }
        return true;
    }
};
