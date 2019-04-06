class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size()==0)
            return false;
        map<int,int> foo;
        for (int i=0;i<nums.size();i++){
            auto it = foo.find(nums[i]);
            if (it!=foo.end())
                return true;
            foo.insert({nums[i],nums[i]});
        }
        return false;
    }
};
