class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> ans;
        
        int foo=0;
        for(int i=0;i<A.size();i++)
            if(A[i]%2==0)
                foo+=A[i];
                
        for(int i=0;i<queries.size();i++){
            int temp1=A[queries[i][1]];
            int temp2=queries[i][0];
            A[queries[i][1]]+=queries[i][0];
                 
            if(temp1%2==0&&temp2%2==0)
                foo+=temp2;
            if(temp1%2==0&&abs(temp2)%2==1)
                foo-=temp1;
            if(abs(temp1)%2==1&&temp2%2==0)
                foo+=0;
            if(abs(temp1)%2==1&&abs(temp2)%2==1)
                foo+=(temp1+temp2);

            ans.push_back(foo);
        }
        return ans;
    }
};
