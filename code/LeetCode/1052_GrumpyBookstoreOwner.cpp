class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int X) {
        if(g.size()==0)
            return 0;
        
        vector<int> happyc;
        vector<int> unhappyc;
        int gcorrection=0;
        int bestgcorrection=0;
        int ccorrection=0;
        int bestccorrection=0;
        int cuncorrected=0;
        for(int i=0;i<c.size();i++){
            cuncorrected+=(g[i]==0)*c[i];
            if(g[i]==1){
                unhappyc.push_back(c[i]*g[i]);
                ++gcorrection;
                ccorrection+=g[i]*c[i];
            }
            else
                happyc.push_back(c[i]*g[i]);
            if(i-X>=0){
                if(g[i-X]==1){
                    --gcorrection;
                    ccorrection-=g[i-X]*c[i-X];
                }
            }
            bestgcorrection=max(bestgcorrection,gcorrection);
            bestccorrection=max(bestccorrection,ccorrection);
        }
        return cuncorrected+bestccorrection;
    }
};
