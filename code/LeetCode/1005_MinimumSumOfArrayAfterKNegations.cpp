class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        if(A.size()==0)
            return 0;
        sort(A.begin(),A.end());
        int temp=0;
        for(int i=0;i<A.size();i++)
            if(abs(A[i])<abs(A[temp]))
                temp=i;
        for(int i=0;i<K;i++){
            if(A[i]<=0)
                A[i]=-A[i];
            else
                A[temp]=-A[temp];
        }
        int ans=0;
        for(int i=0;i<A.size();i++)
            ans+=A[i];
        return ans;
    }
};
