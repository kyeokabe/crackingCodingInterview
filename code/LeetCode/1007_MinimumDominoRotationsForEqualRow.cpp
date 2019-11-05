class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int option1=help(A,B);
        int option2=help(B,A);
        if(option1==-1&&option2==-1)
            return -1;
        if(option1!=-1&&option2!=-1)
            return min(option1,option2);
        return max(option1,option2);
    }
    
    
    int help(vector<int>& A, vector<int>& B){
        vector<int> count_i_A(6,0);
        vector<int> count_i_B(6,0);
        
        for(int i=0;i<A.size();i++){
            count_i_A[A[i]-1]++;
            if(A[i]!=B[i])
               count_i_B[B[i]-1]++; 
        }
        int ans=INT_MAX;
        for(int i=0;i<6;i++){
            if(count_i_A[i]+count_i_B[i]>=A.size()&&count_i_B[i]<ans)
                ans=count_i_B[i];
        }
        
        return ans==INT_MAX?-1:ans;
    }
};
