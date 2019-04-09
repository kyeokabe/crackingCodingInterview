class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> num2ind;
        
        for(int i=0;i<nums2.size();i++){
            num2ind[nums2[i]]=i;
        }
        
        vector<int> ans;
        
        for (int i=0;i<nums1.size();i++){
            auto it=num2ind.find(nums1[i]);
            if (it==num2ind.end())
                ans.push_back(-1);
            else
            {
                int index=it->second;
                bool found=false;
                for(int j=index;j<nums2.size();j++){
                    if (nums2[j]>nums1[i]){
                        ans.push_back(nums2[j]);
                        found=true;
                        break;
                    }
                }
                if (!found)
                    ans.push_back(-1);
            }
        }
        return ans;
    }
};
