class Solution {
private:
    vector<int> n;
    
public:
    Solution(vector<int>& nums) {
        n=nums;
    }
    
    int pick(int target) {
        unordered_map<int,vector<int>> m;
        for(int i=0;i<n.size();i++)
            if(n[i]==target){
                auto it=m.find(target);
                if(it==m.end()){
                    vector<int> v={i};
                    m[target]=v;
                }
                else
                    m[target].push_back(i);
            }

        return m[target][rand()%m[target].size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
