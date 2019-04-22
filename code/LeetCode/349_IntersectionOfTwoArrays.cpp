class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m1,m2;
        for (int i=0;i<nums1.size();i++){
            m1[nums1[i]]=nums1[i];
        }
        for (int i=0;i<nums2.size();i++){
            auto it=m1.find(nums2[i]);
            if (it!=m1.end()){
                m2[nums2[i]]=nums2[i];
            }
        }
        vector<int> ans;
        for (auto it=m2.begin();it!=m2.end();it++){
            ans.push_back(it->first);
        }
        return ans;
    }
};
