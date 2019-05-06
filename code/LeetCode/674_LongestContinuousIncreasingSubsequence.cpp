class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size()==0)
            return 0;
        int ans=0;
        stack<int> s;
        int k=0;
        while(k<nums.size()){
            int temp=0;
            if(s.empty()||s.top()<nums[k]){
                s.push(nums[k]);
            }
            
            else if(s.top()>=nums[k]){
                while(!s.empty()){
                    ++temp;
                    s.pop();
                }
                if(temp>ans)
                    ans=temp;
                s.push(nums[k]);
            }
            ++k;
        }
        int temp2=0;
        while(!s.empty()){
            ++temp2;
            s.pop();
        }
        if(temp2>ans)
            ans=temp2;
        return ans;
    }
};
