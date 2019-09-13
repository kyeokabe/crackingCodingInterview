//5 step process adapted from heros3001
//https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems.

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        
        vector<int> v1(nums.size(),INT_MIN);
        vector<int> v2(nums.size()+1,INT_MIN);        
        
        cout<<rob2(nums,0,v2)<<endl;
        
        return max(rob1(nums,0,v1),rob2(nums,1,v2));
    }
        
    int rob1(vector<int>& nums, int i,vector<int> &v1){
        if(i>=nums.size()-1)
            return 0;
        if(v1[i]==INT_MIN)
            v1[i]=max(nums[i]+rob1(nums,i+2,v1),rob1(nums,i+1,v1));
        return v1[i];
    }
        
    int rob2(vector<int>& nums, int i,vector<int> &v2){
        if(i>=nums.size())
            return 0;
        if(v2[i]==INT_MIN)
            v2[i]=max(nums[i]+rob2(nums,i+2,v2),rob2(nums,i+1,v2));
        return v2[i];
    }    
};

/*
********************************
**Step 2. Recursive (top-down)**
********************************
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        
        return max(rob1(nums,0),rob2(nums,1));
    }
        
    int rob1(vector<int>& nums, int i){
            if(i>=nums.size()-1)
                return 0;
            return max(nums[i]+rob1(nums,i+2),rob1(nums,i+1));
        }
        
    int rob2(vector<int>& nums, int i){
            if(i>=nums.size())
                return 0;
            return max(nums[i]+rob2(nums,i+2),rob2(nums,i+1));
    }    
};

*******************************************************
**Step 3. Recursive (Memoization ... i.e., top-down).**
*******************************************************

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        
        vector<int> v1(nums.size(),INT_MIN);
        vector<int> v2(nums.size()+1,INT_MIN);        
        
        cout<<rob2(nums,0,v2)<<endl;
        
        return max(rob1(nums,0,v1),rob2(nums,1,v2));
    }
        
    int rob1(vector<int>& nums, int i,vector<int> &v1){
        if(i>=nums.size()-1)
            return 0;
        if(v1[i]==INT_MIN)
            v1[i]=max(nums[i]+rob1(nums,i+2,v1),rob1(nums,i+1,v1));
        return v1[i];
    }
        
    int rob2(vector<int>& nums, int i,vector<int> &v2){
        if(i>=nums.size())
            return 0;
        if(v2[i]==INT_MIN)
            v2[i]=max(nums[i]+rob2(nums,i+2,v2),rob2(nums,i+1,v2));
        return v2[i];
    }    
};

*/
