class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        
        int abs_distance=INT_MAX;
        int ans=0;
        for(int i=0;i<nums.size()-2;i++){
            int R=nums.size()-1;
            int L=i+1;
            while(R>L){
                int temp=nums[i]+nums[R]+nums[L];
                if(abs(target-temp)<abs_distance){
                    abs_distance=abs(target-temp);
                    ans=temp;
                }
                if(target==temp)
                    return ans;
                if(target>temp)
                    L++;
                else
                    R--;
            }
        }
        return ans;
    }
};
