class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> ind;
        vector<int> ans;

        for (int i=0;i<S.length();i++)
            if(C==S[i])
                ind.push_back(i);
        for (int i=0;i<S.length();i++){
            int min=pow(2,31)-1;
            for (int j=0;j<ind.size();j++){
                if(abs(ind[j]-i)<min)
                    min=abs(ind[j]-i);
            }
            ans.push_back(min);
        }
        return ans;
    }
};
