class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<int> foo(nums.size(),0);
        vector<vector<int>> v(nums.size(),foo);
        return help(v,nums,0,nums.size()-1)>=0;
    }
    
    int help(vector<vector<int>> &v, vector<int>& nums, int s, int e){
        if(s==e){
            v[s][e]=nums[s];
            return v[s][e];
        }
        if(v[s][e]!=0)
            return v[s][e];
        else{
            int a=nums[s]-help(v,nums,s+1,e);
            int b=nums[e]-help(v,nums,s,e-1);
            v[s][e]=max(a,b);
            return v[s][e];
        }
    }
    
};
