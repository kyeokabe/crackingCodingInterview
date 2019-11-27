class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        vector<int> v(10001,0);
        for(int r=0;r<mat.size();r++){
            unordered_map<int,int> m;
            for(int c=0;c<mat[0].size();c++)
                if(m.find(mat[r][c])==m.end()){
                    m[mat[r][c]]++;
                    v[mat[r][c]]++;
                }
        }
        
        for(int i=1;i<v.size();i++)
            if(v[i]==mat.size())
                return i;
        return -1;
    }
};
