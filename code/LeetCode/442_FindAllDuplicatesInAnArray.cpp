class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int,int> foo;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            auto it=foo.find(nums[i]);
            if (it!=foo.end())
                ans.push_back(nums[i]);
            foo[nums[i]]=nums[i];
        }
        return ans;
    }
};
