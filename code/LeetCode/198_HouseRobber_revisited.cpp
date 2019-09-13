class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size()==0)
            return 0;      
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        
        int a=nums[0];
        int b=max(nums[0],nums[1]);//closer to c
        int c;
        
        for(int i=2;i<nums.size();i++){
            c=max(nums[i]+a,b);
            a=b;
            b=c;
        }
        
        return c;
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
        int i=0;
        return max(nums[i]+rob2(nums,i+2),rob2(nums,i+1));
    }
    
    int rob2(vector<int>& nums, int i){
        if(i==nums.size()-1)
            return nums[nums.size()-1];
        if(i>nums.size()-1)
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
        int i=0;
        
        vector<int> v(nums.size()+1,INT_MIN);
        return max(nums[i]+rob2(nums,i+2,v),rob2(nums,i+1,v));
    }
    
    int rob2(vector<int>& nums, int i, vector<int> &v){
        if(i==nums.size()-1)
            return nums[nums.size()-1];
        if(i>nums.size()-1)
            return 0;
        if(v[i]==INT_MIN)
            v[i]=max(nums[i]+rob2(nums,i+2,v),rob2(nums,i+1,v));
        return v[i];
    }
};

***************************************************************
**Step 4. Iterative (Dynamic Programming ... i.e., bottom-up)**
***************************************************************

class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size()==0)
            return 0;      
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        
        vector<int> v(nums.size(),INT_MIN);
        v[0]=nums[0];
        v[1]=max(nums[0],nums[1]);
        
        for(int i=2;i<nums.size();i++)
            v[i]=max(nums[i]+v[i-2],v[i-1]);
        
        return v[nums.size()-1];
    }
};

*****************************************************
**Step 5. Iterative with constant space (bottom-up)**
*****************************************************

class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size()==0)
            return 0;      
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        
        int a=nums[0];
        int b=max(nums[0],nums[1]);//closer to c
        int c;
        
        for(int i=2;i<nums.size();i++){
            c=max(nums[i]+a,b);
            a=b;
            b=c;
        }
        
        return c;
    }
};


*/
