class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        unordered_map<int,int> m;
        
        for(int i=0;i<nums.size();i++){
            auto it=m.find(nums[i]);
            if(it!=m.end()){
                nums[i]=nums[nums.size()-1];
                nums.pop_back();
                i--;
            }
            else{
                m[nums[i]]++;
            }
        }
        
        if(nums.size()==1)
            return nums[0];
        
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        
        int max=INT_MIN;
        //find max value
        for(int i=0;i<nums.size();i++)
            if(nums[i]>max){
                max=nums[i];
                nums[i]=nums[nums.size()-1];
                nums[nums.size()-1]=max;
                i--;
            }
        
        max=INT_MIN;
        //find second max value
        for(int i=0;i<nums.size()-1;i++)
            if(nums[i]>max){
                max=nums[i];
                nums[i]=nums[nums.size()-2];
                nums[nums.size()-2]=max;
                i--;
            }
        
        max=INT_MIN;
        //find third max value
        for(int i=0;i<nums.size()-2;i++)
            if(nums[i]>max){
                max=nums[i];
                nums[i]=nums[nums.size()-3];
                nums[nums.size()-3]=max;
                i--;
            }
        return nums[nums.size()-3];
    }
};
