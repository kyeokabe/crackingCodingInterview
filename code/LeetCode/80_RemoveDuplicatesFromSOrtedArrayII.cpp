//adapted from Stefan Pochmann solution
//https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/discuss/27976/3-6-easy-lines-C%2B%2B-Java-Python-Ruby

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2)
            return nums.size();
        int i=2;
        for(int j=2;j<nums.size();j++){
            if(nums[j]>nums[i-2]){
                nums[i]=nums[j];
                i++;
            }
        }
        return i;
    }
};
