//https://leetcode.com/problems/product-of-array-except-self/discuss/65622/Simple-Java-solution-in-O(n)-without-extra-space
//adapted rom lycjava3
//basic idea is that each element of answer is a product of every element from left and right
//make two arrays that represent the product of everything left and right
//one of these arrays can be compacted as an int and computed on the fly
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
            ans.push_back(1);
        for(int i=1;i<nums.size();i++)
            ans[i]*=nums[i-1]*ans[i-1];
        int R=1;
        for(int i=nums.size()-1;i>=0;i--){
            ans[i]*=R;
            R*=nums[i];
        }
        return ans;
    }
};
