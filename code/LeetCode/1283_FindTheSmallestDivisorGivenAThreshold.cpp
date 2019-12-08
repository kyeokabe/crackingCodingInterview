class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int L=1;
        int R=pow(10,6);
        int M=(L+R)/2;
        
        while(R-1>L){
            M=(L+R)/2;
            int temp=getsum(nums,M);
            if(temp>threshold)
                L=M;
            else
                R=M;
        }
        if(getsum(nums,R)<=threshold){
            if(getsum(nums,L)<=threshold)
                return L;
            else
                return R;
        }
        return 0;//will never reach this line
    }
    
    int getsum(vector<int>& nums, int k){
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%k==0)
                ans+=nums[i]/k;
            else
                ans+=(nums[i]/k+1);
        }
        return ans;
    }
};
