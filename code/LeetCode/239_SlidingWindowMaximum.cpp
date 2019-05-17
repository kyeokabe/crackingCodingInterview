class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size()==0)
            return {};
        vector<int> ans;
        for (int i=0; i<=nums.size()-k;i++){
            int temp=INT_MIN;
            for(int j=i;j<i+k;j++){
                temp=max(temp,nums[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
