class NumArray {
private:
    vector<int> v;
    
public:
    NumArray(vector<int>& nums) {
        v.reserve(nums.size());
        if(nums.size()>=1)
            v.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
            v.push_back(v[i-1]+nums[i]);
    }
    
    int sumRange(int i, int j) {
        int a;
        i==0?a=0:a=v[i-1];
        return v[j]-a;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
