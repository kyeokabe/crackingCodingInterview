class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size()<=2)
            return {};
        sort(nums.begin(),nums.end());
        map<int,int> foo;
        vector<vector<int>> ans;
        
        map<vector<int>,vector<int>> ansmap;
        
        for(int i=0;i<nums.size();i++){
            foo[nums[i]]=i;
        }
        bool samenum;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                auto it=foo.find(-(nums[i]+nums[j]));
            
                if(-(nums[i]+nums[j])==nums[i]||-(nums[i]+nums[j])==nums[j])
                    samenum=true;
                else
                    samenum=false;
                if(it!=foo.end()){
                    if(!samenum||samenum&&(adjacent(nums,i)||(adjacent(nums,j)))){
                        vector<int> temp={nums[i],nums[j],-(nums[i]+nums[j])};
                
                        sort(temp.begin(),temp.end());
                        auto it2=ansmap.find(temp);
                        if(it2==ansmap.end()){
                            ans.push_back(temp);
                            ansmap[temp]=temp;
                        }
                    }
                }
            }
        }
        return ans;
    }
    
    bool adjacent(vector<int> &n, int i){
        if(i>0)
            if (n[i-1]==n[i])
                return true;
        if(i<n.size()-1)
            if (n[i]==n[i+1])
                return true;
        return false;
    }
    
};
