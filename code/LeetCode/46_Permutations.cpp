class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        
        help(nums,v,ans);
        return ans;
    }
    
    void help(vector<int>& nums, vector<int> &v, vector<vector<int>> &ans){
        if(0==nums.size())
            ans.push_back(v);
        
        for(int i=0;i<nums.size();i++){
            v.push_back(nums[i]);
            int a=nums[i];
            nums[i]=nums[nums.size()-1];
            nums.pop_back();
            help(nums,v,ans);
            nums.push_back(a);
            swap(nums[i],nums[nums.size()-1]);
            v.pop_back();
        }
    }
};

/*
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        do{
            ans.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));     
        return ans;
    }
};
*/
