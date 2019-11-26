class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        
        vector<char> temp(board[0].size(),'0');
        vector<vector<char>> m(board.size(),temp);
        
        for(int r=0;r<board.size();r++){
            for(int c=0;c<board[0].size();c++){
                if(r-1>=0&&c-1>=0&&board[r-1][c-1]=='M')
                    m[r][c]++;
                if(r-1>=0&&board[r-1][c]=='M')
                    m[r][c]++;
                if(r-1>=0&&c+1<board[0].size()&&board[r-1][c+1]=='M')
                    m[r][c]++;
                if(c-1>=0&&board[r][c-1]=='M')
                    m[r][c]++;
                if(c+1<board[0].size()&&board[r][c+1]=='M')
                    m[r][c]++;
                if(r+1<board.size()&&c-1>=0&&board[r+1][c-1]=='M')
                    m[r][c]++;
                if(r+1<board.size()&&board[r+1][c]=='M')
                    m[r][c]++;
                if(r+1<board.size()&&c+1<board[0].size()&&board[r+1][c+1]=='M')
                    m[r][c]++;
            }
        }
        
        vector<vector<char>> v=board;

        if(board[click[0]][click[1]]=='M'){
            v[click[0]][click[1]]='X';
            return v;
        }
        else if(m[click[0]][click[1]]>='1'&&m[click[0]][click[1]]<='8'){
            v[click[0]][click[1]]=m[click[0]][click[1]];
            return v;
        }
        else{
            help(v,m,click[0],click[1]);
            return v;
        }
    }
    
    void help(vector<vector<char>> &v, vector<vector<char>> &m, int r, int c){
        if(v[r][c]=='E'&&m[r][c]=='0'){
            v[r][c]='B';
            if(r-1>=0&&c-1>=0)
                help(v,m,r-1,c-1);
            if(r-1>=0)
                help(v,m,r-1,c);
            if(r-1>=0&&c+1<m[0].size())
                help(v,m,r-1,c+1);
            if(c-1>=0)
                help(v,m,r,c-1);
            if(c+1<m[0].size())
                help(v,m,r,c+1);
            if(r+1<m.size()&&c-1>=0)
                help(v,m,r+1,c-1);
            if(r+1<m.size())
                help(v,m,r+1,c);
            if(r+1<m.size()&&c+1<m[0].size())
                help(v,m,r+1,c+1);
        }
        else if(m[r][c]>='1'&&m[r][c]<='8'){
            v[r][c]=m[r][c];
            return;
        }
    }
    
};
