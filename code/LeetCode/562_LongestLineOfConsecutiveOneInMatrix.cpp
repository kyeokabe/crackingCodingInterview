class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if(M.size()==0||M[0].size()==0)
            return 0;
        int ans=0;
        
        for(int i=0;i<M.size();i++){
            int count=0;
            for(int j=0;j<M[0].size();j++){
                if(M[i][j]==1)
                    count++;
                else
                    count=0;
                if(count>ans)
                    ans=count;
            }
        }
        
         for(int j=0;j<M[0].size();j++){
            int count=0;
            for(int i=0;i<M.size();i++){
                if(M[i][j]==1)
                    count++;
                else
                    count=0;
                if(count>ans)
                    ans=count;
            }
        }
                
        for(int i=0;i<M.size();i++){
            int k=i;
            int j=0;
            int count=0;
            while(k>=0&&j<M[0].size()){
                if(M[k][j]==1)
                    count++;
                else
                    count=0;
                if(count>ans)
                    ans=count;
                k--;
                j++;
            }
        }
         
        for(int j=1;j<M[0].size();j++){
            int k=j;
            int i=M.size()-1;
            int count=0;
            while(i>=0&&k<M[0].size()){       
                if(M[i][k]==1)
                    count++;
                else
                    count=0;
                if(count>ans)
                    ans=count;
                k++;
                i--; 
            }
        }
                        
        for(int i=0;i<M.size();i++){
            int k=i;
            int j=M[0].size()-1;
            int count=0;
            while(k>=0&&j>=0){
                if(M[k][j]==1)
                    count++;
                else
                    count=0;
                if(count>ans)
                    ans=count;
                k--;
                j--;
            }
        }
         
        for(int j=M[0].size()-2;j>=0;j--){
            int k=j;
            int i=M.size()-1;
            int count=0;
            while(i>=0&&k<M[0].size()){       
                if(M[i][k]==1)
                    count++;
                else
                    count=0;
                if(count>ans)
                    ans=count;
                k--;
                i--; 
            }
        }
        return ans;
    }
};
