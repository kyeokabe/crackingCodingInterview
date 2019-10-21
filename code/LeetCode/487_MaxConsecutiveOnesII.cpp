class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.size()<=1)
            return nums.size();
        int count=0;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)
                count++;
            else{
                if(i!=0)
                    v.push_back(count);
                count=0;
                v.push_back(count);
            }
        }
        if(nums[nums.size()-1]==1)
            v.push_back(count);
        
        bool has1=false;
        for(int i=0;i<v.size();i++){
            if(v[i]!=0)
                has1=true;
        }
        
        if(has1==false)
            return 1;
        int ans=0;
        if(v.size()==1)
            return v[0];
        for(int i=1;i<v.size();i++)
            if(v[i]+v[i-1]+1>ans)
                ans=v[i]+v[i-1]+1;
        for(int i=2;i<v.size();i++)
            if(v[i]+v[i-1]+v[i-2]+1>ans)
                ans=v[i]+v[i-1]+v[i-2]+1;
        return ans;
    }
};

//1 0 2 0 1
