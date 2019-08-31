class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        
        if(m.size()==0||m[0].size()==0)
            return false;
        int r=0;
        int c=m[0].size()-1;
                        
        while(r<=m.size()-1&&c>=0){
            if(m[r][c]==t)
                return true;
           
            else if(m[r][c]>t){
                c--;
            }
            else if(m[r][c]<t)
                r++;
        }

        return false;
    }
};
