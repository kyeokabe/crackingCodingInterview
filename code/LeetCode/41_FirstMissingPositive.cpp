class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {    
        
        //deal with trivial cases first
        if(nums.size()==0)
            return 1;
        if(nums.size()==1){
            if(nums[0]==1)
                return 2;
            else
                return 1;
        }

        //this part of the code deals with the edge case
        //when all pos numbers from 1 to nums.size() are
        //present
        bool hasnumssize=false;
        for(int i=0;i<nums.size();i++)
            if(nums[i]==nums.size())
                hasnumssize=true;
        
        //use the element as an index when valid and
        //mark it as visited (=INT_NUM)
        //do this recursively
        for(int i=0;i<nums.size();i++)
            if(nums[i]>=0&&nums[i]<nums.size()){
                int j=nums[i];
                help(j,nums);
            }
        
        for(int i=1;i<nums.size();i++)
            if(nums[i]!=INT_MIN)
                return i;

        return nums.size()+hasnumssize;
    }
    
    void help(int j, vector<int>& nums){
        int temp=nums[j];
        nums[j]=INT_MIN;
        if(temp>=0&&temp<nums.size())
            help(temp,nums);
    }
    
};
