/*
"kind of" cheating since I'm using STL Algorithms, but results are good.
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> foo;
                
        for (int i=0;i<m;i++)
            foo.push_back(nums1[i]);
        for (int i=0;i<n;i++)
            foo.push_back(nums2[i]);
        
        sort(foo.begin(),foo.end());
        
        for (int i=0;i<m+n;i++)
            nums1[i]=foo[i];
    }
};
