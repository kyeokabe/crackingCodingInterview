class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s1;
        unordered_set<int> s2;
        if(nums.size()<=1)
            return nums.size();
        
        int ans=0;
        
        for(int i=0;i<nums.size();i++)
            s1.insert(nums[i]);
        
        for(int i=0;i<nums.size();i++){
            if(s2.find(nums[i])==s2.end()){
                int temp=help(s1,s2,nums[i]);
                if(temp>ans)
                    ans=temp;
            }
            else{
                //do nothing
            }
        }
        return ans;
    }
    
    int help(unordered_set<int> &s1,unordered_set<int> &s2,int i){
        s2.insert(i);
        int pre=0;
        if(i-1>=INT_MIN&&s1.find(i-1)!=s1.end()&&s2.find(i-1)==s2.end()){
            pre=help(s1,s2,i-1);
        }
        int post=0;
        if(i+1<=INT_MAX&&s1.find(i+1)!=s1.end()&&s2.find(i+1)==s2.end()){
            post=help(s1,s2,i+1);
        }
        return 1+pre+post;
    }
};
