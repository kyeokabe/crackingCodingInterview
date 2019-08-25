class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size()-1;
        int min=0;
        int max=nums.size()-1;
        int ans=0;
        
        while(min<max){
            int ave=(max+min)/2;
            int count=0;
            for(int i=0;i<=n;i++){
                if(nums[i]<=ave)
                    count++;
            }

            if(count>ave)
                max=ave;
            else
                min=ave;
            
            if (max-min==1){
                int count2=0;
                for(int i=0;i<n;i++){
                    if(nums[i]==min){
                        count2++;
                        if (count2==2){
                            return min;
                        }
                    }
                }

                return max;
            }
        }
        return 0;
    }
};
