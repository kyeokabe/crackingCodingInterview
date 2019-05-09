class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int max=0;
        int sum=0;
        unordered_map<int,int> m; //<key,val> = <sum,index>
        m[0]=0;//need this so [0,1] will sum as 0, -1, 0
               //                           ind2 - ind0 = len2
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
                sum-=1;
            else
                sum+=1;
            auto it=m.find(sum);
            if(it!=m.end()){
                int length=i+1-(it->second);
                if(length>max)
                    max=length;
            }
            else
                m[sum]=i+1;
        }
        return max;
    }
};

//[0,0,1,1,1,1,0,1,0,1]
//[0,1]
//[0,0,1,1,1,1,0,1,0,1,1,1,1,0,0,0,1,0,0,1,1,0,1,0,0,1]
