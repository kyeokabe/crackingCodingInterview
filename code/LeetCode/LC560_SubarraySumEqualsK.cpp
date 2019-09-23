class Solution {
public:
    int subarraySum(vector<int>& nums, int k) { 
        
        unordered_map<int,set<int>> m;
        int sum=0;
        int ans=0;
        set<int> s;
        s.insert(-1);
        m[0]=s;
        
        for(int i=0;i<nums.size();i++){
                        
            sum+=nums[i];
            auto it1=m.find(sum);
            if(it1==m.end()){
                set<int> s;
                s.insert(i);
                m[sum]=s;
            }
            else
                it1->second.insert(i);  
            
            auto it2=m.find(sum-k);
            if(it2!=m.end()){
                auto it3=it2->second.begin();
                while(it3!=it2->second.end()&&*it3<i){
                    ans++;
                    it3++;
                }
            }
            
        }
        return ans;
        
    }
};
