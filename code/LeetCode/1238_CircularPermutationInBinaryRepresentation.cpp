class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        unordered_map<int,int> m;
        for(int i=0;i<(1<<n);i++)
            m[i]=i^(i>>1);
        auto it=m.begin();
        while(it->second!=start)
            it++;
        vector<int> ans;
        int a=it->first;
        
        for(int i=0;i<(1<<n);i++){
            ans.push_back(m[a]);
            a=(a+1)%(1<<n);
        }
        return ans;
    }
};
