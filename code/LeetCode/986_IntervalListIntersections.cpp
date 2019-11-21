//adapted from localhostghost
//https://leetcode.com/problems/interval-list-intersections/discuss/231532/Python3-Really-easy-concept%3A-Overlapping

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        int a=0;
        int b=0;
        vector<vector<int>> ans;
        
        while(a<A.size()&&b<B.size()){
            if(A[a][0]<=B[b][1]&&A[a][1]>=B[b][0]){
                vector<int> v={max(A[a][0],B[b][0]),min(A[a][1],B[b][1])};
                ans.push_back(v);
                if(A[a][1]<B[b][1])
                    a++;
                else if(A[a][1]>B[b][1])
                    b++;
                else{
                    a++;
                    b++;
                }
            }
            else if(A[a][1]>B[b][1])
                b++;
            else
                a++;
        }
        
        return ans;
    }
};
