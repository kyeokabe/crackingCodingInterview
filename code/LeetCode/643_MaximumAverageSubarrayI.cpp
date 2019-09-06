class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int sum=0;
        int ptr1=0;
        int ptr2=0;
        int ans=0;
        for(int i=0;i<k;i++){
            sum+=nums[ptr2];
            ptr2++;
        }
        ans=sum;
        ptr2--;
        while(ptr2+1<=nums.size()-1){
            sum+=nums[++ptr2];
            sum-=nums[ptr1++];
            if(ans<sum)
                ans=sum;
        }
        return double(ans)/double(k);
    }
};
