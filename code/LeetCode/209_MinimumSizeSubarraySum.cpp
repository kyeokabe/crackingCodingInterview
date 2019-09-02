class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l=0;
        int r=0;
        int sum=0;
        int ans=INT_MAX;
        
        while(r<=nums.size()){
            //cout<<"r = "<<r<<", l = "<<l<<endl;
            if(sum<s){
                if(r==nums.size())
                    break;
                sum+=nums[r];
                r++;
            }
            else if(sum>=s){
                if(r-l<ans)
                    ans=r-l;
                sum-=nums[l];
                l++;
            }
        }
        
        return (ans==INT_MAX? 0:ans);
        
    }
};
