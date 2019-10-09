//optimized answer
//O(n) time, O(1) space

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int ans=0;
        if(A.size()<3)
            return ans;
        int temp=0;
        for(int i=2;i<A.size();i++){
            if(A[i]-A[i-1]==A[i-1]-A[i-2]){
                temp+=1;
                ans+=temp;
            }
            else{
                temp=0;
            }
        }
        return ans;
    }
};

/*
//a bit unoptimized O(n) time, O(n) space

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int ans=0;
        if(A.size()<3)
            return ans;
        vector<int> v(A.size(),0);
        
        for(int i=2;i<A.size();i++){
            if(A[i]-A[i-1]==A[i-1]-A[i-2]){
                v[i]=v[i-1]+1;
                ans+=v[i];
            }
        }
        
        return ans;
    }
};
*/
