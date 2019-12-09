class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& b) {
        while(help(b)){
            //do nothing;
        }
        return b;
    }
    
    bool help(vector<vector<int>> &b){
        bool crushable=false;
        
        for(int r=0;r<b.size();r++){
            for(int c=1;c<b[0].size()-1;c++)
                if((b[r][c-1]==b[r][c]||b[r][c-1]==-b[r][c]))
                    if(b[r][c+1]==b[r][c]||b[r][c+1]==-b[r][c])
                        if(b[r][c]>0||b[r][c-1]>0||b[r][c+1]>0){
                            crushable=true;
                            b[r][c+0]=-abs(b[r][c+0]);
                            b[r][c-1]=-abs(b[r][c-1]);
                            b[r][c+1]=-abs(b[r][c+1]);
                }
        }
        
        for(int r=1;r<b.size()-1;r++){
            for(int c=0;c<=b[0].size()-1;c++)
                if(b[r-1][c]==b[r][c]||b[r-1][c]==-b[r][c])
                   if(b[r+1][c]==b[r][c]||b[r+1][c]==-b[r][c])
                        if(b[r][c]>0||b[r-1][c]>0||b[r+1][c]>0){
                            crushable=true;
                            b[r+0][c]=-abs(b[r+0][c]);
                            b[r-1][c]=-abs(b[r-1][c]);
                            b[r+1][c]=-abs(b[r+1][c]);
                }
        }
        if(!crushable)
            return false;
        
        for(int r=0;r<b.size();r++)
            for(int c=0;c<b[0].size();c++)
                if(b[r][c]<0)
                    b[r][c]=0;
                
        for(int r=b.size()-2;r>=0;r--){
            for(int c=0;c<b[0].size();c++){
                if(b[r][c]!=0&&b[r+1][c]==0){
                    int R=r+1;
                    while(R<=b.size()-1&&b[R][c]==0)
                        R++;
                    R--;
                    swap(b[r][c],b[R][c]);
                }
            }
        }
        
        return crushable;
    }
};
