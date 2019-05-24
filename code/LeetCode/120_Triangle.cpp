class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==1)
            return triangle[0][0];
        for(int i=1;i<triangle.size();i++){
            for(int j=0;j<triangle[i].size();j++){
                if(j==0)
                    triangle[i][0]+=triangle[i-1][0];
                else if(j==triangle[i].size()-1)
                    triangle[i][triangle[i].size()-1]+=triangle[i-1][triangle[i-1].size()-1];
                else
                    triangle[i][j]=triangle[i][j]+min(triangle[i-1][j-1],triangle[i-1][j]);
            }
        }
        int ans=triangle[triangle.size()-1][0];
        for(int j=0;j<triangle[triangle.size()-1].size();j++)
            if(triangle[triangle.size()-1][j]<ans)
                ans=triangle[triangle.size()-1][j];
        return ans;
    }    
};
