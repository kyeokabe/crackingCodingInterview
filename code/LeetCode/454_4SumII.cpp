//adapted from freeprogrammer
//https://leetcode.com/problems/4sum-ii/discuss/93925/Concise-C%2B%2B-11-code-beat-99.5

/*
/Only realized the N^3 solution when solving. 
Interesting idea to break up for loops into 2 separate segments

*/

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        if(A.size()==0)
            return 0;
        int ans=0;
        unordered_map<int,int> m;
        for(int i=0;i<A.size();i++)
            for(int j=0;j<B.size();j++)
                m[A[i]+B[j]]++;
        
        for(int i=0;i<C.size();i++)
            for(int j=0;j<D.size();j++){
                auto it=m.find(0-(C[i]+D[j]));
                if(it!=m.end())
                    ans+=it->second;
                }
        return ans;
    }
};
