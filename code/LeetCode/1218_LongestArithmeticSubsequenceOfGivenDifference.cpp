class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        if(arr.size()<=1)
            return arr.size();
        unordered_map<int,int> m;
        m[arr[0]]++;
        
        for(int i=1;i<arr.size();i++){
            auto it=m.find(arr[i]-difference);
            if (it!=m.end())
                m[arr[i]]=(it->second+1);
            else
               m[arr[i]]=1;
        }
        
        auto it=m.begin();
        int ans=it->second;
        
        while(it!=m.end()){
            if(it->second>ans)
                ans=it->second;
            it++;
        }
        return ans;
    }
};
