class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        for(int i=0;i<A.size();i++)
            if(A[i][0]==0)
                for(int j=0;j<A[i].size();j++){
                    if(A[i][j]==1)
                        A[i][j]=0;
                    else
                        A[i][j]=1;
                }
        
        for(int j=1;j<A[0].size();j++){
            int count=0;
            for(int i=0;i<A.size();i++)
                count+=A[i][j];
            if((A.size()%2==1&&A.size()/2+1>count)||(A.size()%2==0&&A.size()/2>count)){
                for(int i=0;i<A.size();i++){
                    if(A[i][j]==1)
                        A[i][j]=0;
                    else
                        A[i][j]=1;
                }
            }
        }
        //count score
        int ans=0;
        for(int i=0;i<A.size();i++){
            int count=0;
            for(int j=A[0].size()-1;j>=0;j--){
                if(A[i][j]==1){
                    ans+=(1<<count);
                }
                count++;
            }
        }
        return ans;
    }
};
