class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        int i=0;
        int j=0;
        vector<vector<int>> ans;
        
        while(i<A.size()&&j<B.size()){
            if(A[i][1]>=B[j][0]&&A[i][0]<=B[j][1]){
                vector<int> temp={max(A[i][0],B[j][0]),min(A[i][1],B[j][1])};
                ans.push_back(temp);
            }
            if(A[i][1]<B[j][1])
                i++;
            else if(A[i][1]>B[j][1])
                j++;
            else{
                i++;
                j++;
            }
        }
        return ans;
    }
};
