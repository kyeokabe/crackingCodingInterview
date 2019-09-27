class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1)
            return s;
        
        int numCols=0;
        int numchar=s.length();
        bool switchme=false;
        
        //compute numCols needed
        while(numchar>0){
            if(switchme==true){
                numchar=numchar-(numRows-2);
                numCols+=(numRows-2);
                switchme=false;
            }
            else{
                numchar=numchar-numRows;
                numCols++;
                switchme=true;
            }
        }
        
        vector<vector<char>> layout;
        
        //make blank template
        for(int i=0;i<numRows;i++){
            vector<char> foo;
            for(int j=0;j<numCols;j++)
                foo.push_back(' ');
            layout.push_back(foo);
            }
                
        //fill temmplate
        int r=0;
        int c=0;
        int count=0;
        bool godown=true;
        while(count<s.length()){
            layout[r][c]=s[count];
            count++;
            if(godown==true){
                if(r+1<=numRows-1)
                    r=r+1;
                else{
                    godown=false;
                    r=r-1;
                    c=c+1;
                }
            }
            else{
                if(r-1>=0){
                    r=r-1;
                    c=c+1;
                }
                else{
                    godown=true;
                    r=r+1;
                }
            }
        }

        string ans="";
        //get answer from layout
        for(int i=0;i<numRows;i++)
            for(int j=0;j<numCols;j++)
                if(layout[i][j]!=' ')
                    ans=ans+layout[i][j];
        return ans;
    }
};
