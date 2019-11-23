class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<vector<int>,int> m;
        vector<int> v;
        help(m,nums,v);
        
        vector<vector<int>> ans;
        auto it=m.begin();
        while(it!=m.end()){
            ans.push_back(it->first);
            it++;
        }
        return ans;
    }
    
    void help(map<vector<int>,int> &m, vector<int> &nums, vector<int> v){
        //use this if condition if you need
        //all subsets of length n
        //if(nums.size()==0){
        //    m[v]++;
        //    return;
        //}
        //sort(v.begin(),v.end());
        if(v.size()>=2&&v[v.size()-1]<v[v.size()-2])
            return;
        m[v]++;
        for(int i=0;i<nums.size();i++){
            v.push_back(nums[i]);
            int temp=nums[i];
            swap(nums[i],nums[nums.size()-1]);
            nums.pop_back();
            help(m,nums,v);
            v.pop_back();
            nums.push_back(temp);
            swap(nums[i],nums[nums.size()-1]);    
        }
    }
};
