class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        vector<int> sub;
        
        for(int i=0;i<arr2.size();i++)
            m2[arr2[i]]++;
        
        for(int i=0;i<arr1.size();i++){
            auto it=m2.find(arr1[i]);
            if(it==m2.end())
                sub.push_back(arr1[i]);
            m1[arr1[i]]++;
        }
        
        sort(sub.begin(),sub.end());
        int ptr1=0;
        vector<int> ans;
        for(int i=0;i<arr2.size();i++)
            for(int j=0;j<m1[arr2[i]];j++)
                ans.push_back(arr2[i]);
        for(int i=0;i<sub.size();i++)
            ans.push_back(sub[i]);
        
        return ans;
    }
};
