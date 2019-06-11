class Solution {
public:
    int singleNumber(vector<int>& n) {
        unordered_map<int,int> m1;
        for(int i=0;i<n.size();i++){
            auto it=m1.find(n[i]);
            if(it==m1.end())
                m1[n[i]]=1;
            else
                m1[n[i]]++;
        }
        auto it=m1.begin();
        for (it;it!=m1.end();it++)
            if (it->second==1)
                return it->first;
        return 0;
    }
};
