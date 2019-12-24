class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==0||triangle[0].size()==0)
            return 0;
        if(triangle.size()==1)
            return triangle[0][0];
        
        for(int i=1;i<triangle.size();i++){
            for(int j=0;j<triangle[i].size();j++){
                if(j!=0&&j!=triangle[i].size()-1)
                    triangle[i][j]+=min(triangle[i-1][j-1],triangle[i-1][j]);
                else if(j==0)
                    triangle[i][j]+=triangle[i-1][j];
                else if(j==triangle[i].size()-1)
                    triangle[i][j]+=triangle[i-1][j-1];
            }
        }
        int ans=triangle[triangle.size()-1][0];
        for(int i=1;i<triangle[triangle.size()-1].size();i++)
            if(ans>triangle[triangle.size()-1][i])
                ans=triangle[triangle.size()-1][i];
        return ans;
    }
};
