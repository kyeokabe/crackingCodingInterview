class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v=nums;
        sort(v.begin(),v.end());
        
        int i=0;
        while(i<v.size()&&v[i]==nums[i])
            i++;
        
        if(i==nums.size())
            return 0;
        int j=v.size()-1;
        while(j>=0&&v[j]==nums[j])
            j--;
        
        return j+1-i;
    }
};
