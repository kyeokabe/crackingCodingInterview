class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        vector<int> v1(A.size(),1);
        vector<int> v2(A.size(),1);
        int ans=1;
        for(int i=1;i<A.size();i++){
            if(i%2==1){
                if(A[i]>A[i-1])
                    v1[i]=v1[i-1]+1;
                if(A[i]<A[i-1])
                    v2[i]=v2[i-1]+1;
                if(max(v1[i],v2[i])>ans)
                    ans=max(v1[i],v2[i]);
            }
            if(i%2==0){
                if(A[i]<A[i-1])
                    v1[i]=v1[i-1]+1;
                if(A[i]>A[i-1])
                    v2[i]=v2[i-1]+1;
                if(max(v1[i],v2[i])>ans)
                    ans=max(v1[i],v2[i]);
            }
        }
        return ans;
    }
};
