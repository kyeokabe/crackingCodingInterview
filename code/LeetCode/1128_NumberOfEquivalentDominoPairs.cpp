class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        for(int i=0;i<dominoes.size();i++)
            if(dominoes[i][0]>dominoes[i][1])
                swap(dominoes[i][0],dominoes[i][1]);
        map<vector<int>,int> m;
        
        for(int i=0;i<dominoes.size();i++)
            m[dominoes[i]]++;
        auto it=m.begin();
        int ans=0;
        while(it!=m.end()){
            while(it->second>1){
                ans+=(it->second-1);
                it->second=it->second-1;
            }
                it++;
        }
        return ans;
    }
};
