class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        if (A.size()<=1)
            return 0;
        //iterate once through A, j=1~A.size()-1;
        //first, calculate maximum A[i]+i using prev index
        //then, calculate A[j]-j as well. Find max sum.
        
        int ans=-pow(2,31);
        int isum=A[0];
        for (int j=1;j<A.size();j++){
            if((j-1)+A[j-1]>isum)
                isum=(j-1)+A[j-1];
            if(isum-j+A[j]>ans)
                ans=isum-j+A[j];
        }
        return ans;
    }
};
