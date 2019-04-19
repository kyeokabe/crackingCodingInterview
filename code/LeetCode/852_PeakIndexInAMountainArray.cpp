class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int k=0;
        while (A[k+1]>A[k]&&k<A.size()-1){
            k+=1;
        }
        return k;
    }
};
