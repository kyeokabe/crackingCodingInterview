class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        if(matrix.size()==0)
            return 0;
        if(matrix[0].size()==0)
            return 0;
        
        vector<vector<int>> m;
        vector<int> temp(matrix[0].size(),0);
        for(int i=0;i<matrix.size();i++)
            m.push_back(temp);
        
        bool has1=false;
        
        for(int i=0;i<m.size();i++)
            for(int j=0;j<m[0].size();j++)
                if(matrix[i][j]=='1'){
                    m[i][j]=1;
                    has1=true;
                }
    
        if(has1==false)
            return 0;
        
        int num_max=1;
        for(int i=0;i<m.size();i++)
            for(int j=0;j<m[0].size();j++){
                if(i>0&&j>0&&m[i][j]!=0){
                    m[i][j]=min(m[i-1][j-1],min(m[i-1][j],m[i][j-1]))+1;
                    if(m[i][j]>num_max)
                        num_max=m[i][j];
                }
            }
        return num_max*num_max;
    }
};
