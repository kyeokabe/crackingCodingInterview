class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> m;
        for(int i=0;i<A.size();i++)
            m[B[i]]=i;
        vector<int> v(A.size(),0);
        for(int i=0;i<B.size();i++)
            v[i]=m[A[i]];
        return v;
    }
};
