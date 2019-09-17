class Solution {
public:
    int orangesRotting(vector<vector<int>>& g){
        int count_min=0;
        return iterate(g,count_min);   
    }
    
    int iterate(vector<vector<int>> &g, int count_min){
        int r=g.size();//row size
        int c=g[0].size();//column size
        bool changed=false;//tracks changes next minute

        //if there is a rotten
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(g[i][j]==1){
                    if(i-1>=0&&g[i-1][j]==2){
                        g[i][j]=3;//3 means orange that rots next min
                        changed=true;
                    }
                    if(j+1<c&&g[i][j+1]==2){
                        g[i][j]=3;
                        changed=true;
                    }
                    if(i+1<r&&g[i+1][j]==2){
                        g[i][j]=3;
                        changed=true;
                    }
                    if(j-1>=0&&g[i][j-1]==2){
                        g[i][j]=3;
                        changed=true;
                    }
                }       
        
        //if no orange will rot next min
        if(changed==false){
            //if there is still a fresh orange, return -1
            for(int i=0;i<r;i++)
                for(int j=0;j<c;j++)
                    if(g[i][j]==1)
                        return -1;
            
            //otherwise return count_min
            return count_min;
        }
        //if there was an orange that will rot next min (g[i][j]==3),
        //mark it as rotten 
        else{
            for(int i=0;i<r;i++)
                for(int j=0;j<c;j++)
                    if(g[i][j]==3)
                        g[i][j]=2;    
        }
        //go to next min state
        return iterate(g,count_min+1);
    }
};
