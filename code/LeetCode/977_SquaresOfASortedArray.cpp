class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int L=0;
        int R=A.size()-1;
        vector<int> temp;
        vector<int> ans;

        while(L!=R){
            if(abs(A[L])<abs(A[R])){
                temp.push_back(A[R]*A[R]);
                --R;
            }
            else{
                temp.push_back(A[L]*A[L]);
                ++L;   
            }
        }
        temp.push_back(A[L]*A[L]);
        
        for(int i=0;i<temp.size();i++){
            ans.push_back(temp[temp.size()-1-i]);
        }
        return ans;
    }
};
