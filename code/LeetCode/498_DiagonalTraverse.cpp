class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& m) {
        int i=0;
        int j=0;
        int count=0;
        vector<int> ans;
        if(m.size()==0||m[0].size()==0)
            return ans;
        
        if(m.size()==1){
            for(int j=0;j<m[0].size();j++)
                ans.push_back(m[0][j]);
            return ans;
        }
        
        if(m[0].size()==1){
            for(int i=0;i<m.size();i++)
                ans.push_back(m[i][0]);
            return ans;
        }
        
        while(!(i==m.size()-1&&j==m[0].size()-1)){
            ans.push_back(m[i][j]);
            if(count%4==0&&j+1<m[0].size()){
                j++;
                count++;
            }
            else if(count%4==0){
                i++;
                count++;
            }
            else if(count%4==1){
                j--;
                i++;
                if(j==0||i==m.size()-1)
                    count++;
            }
            else if(count%4==2&&i+1<m.size()){
                i++;
                count++;
            }
            else if(count%4==2){
                j++;
                count++;
            }
            else if(count%4==3){
                i--;
                j++;
                if(i==0||j==m[0].size()-1)
                    count++;
            }  
        }
        ans.push_back(m[i][j]);
        return ans;
    }
};
