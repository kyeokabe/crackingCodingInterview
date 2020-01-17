class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<=2)
            return 0;
        sort(nums.begin(),nums.end());
        int R=nums.size()-1;
        int L=0;
        int M=nums.size()-2;
        int ans=0;
        
        while(R>=2){
            M=R-1;
            L=0;
            while(M>L){
                if(nums[L]+nums[M]>nums[R]){
                    ans+=(M-L);
                    M--;
                }
                else{
                    L++;
                }
            }
            R--;
        }
        return ans;
    }
};
