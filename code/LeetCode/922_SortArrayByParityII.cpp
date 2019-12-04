//adapted from wangzi6147
//https://leetcode.com/problems/sort-array-by-parity-ii/discuss/181160/Java-two-pointer-one-pass-inplace
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i=0;
        int j=1;
        while(i<A.size()&&j<A.size()){
            while(i<A.size()&&A[i]%2==0)
                i+=2;
            
            while(j<A.size()&&A[j]%2==1)
                j+=2;
            
            if(i<A.size()||j<A.size())
                swap(A[i],A[j]);
        }
        return A;
    }
};
