class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        sort(A.begin(),A.end());
        int ans=-1;
        int R=A.size()-1;
        int L=0;
        
        while(R>L){
            if(A[R]+A[L]<K&&A[R]+A[L]>ans){
                ans=A[R]+A[L];
                L++;
            }
            else if(A[R]+A[L]<K)
                L++;
            else
                R--;
        }
        return ans;
    }
};

/*

1 4 5 6 9 /10

*/
