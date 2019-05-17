class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> m1;
        for(int i=0;i<nums1.size();i++)
            m1[nums1[i]]++;
        for(int i=0;i<nums2.size();i++){
            auto it=m1.find(nums2[i]);
            if(it!=m1.end()){
                if(it->second>=1){
                    ans.push_back(it->first);
                    it->second--;
                }
            }
        }
        return ans;
    }
};
