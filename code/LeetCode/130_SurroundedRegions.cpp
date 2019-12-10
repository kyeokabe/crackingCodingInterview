class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        if(board.size()<=2||board[0].size()<=2)
            return;
        
        for(int r=0;r<board.size();r++){
            if(board[r][0]=='O')
                help(board,r,0,'O','Y');
            if(board[r][board[0].size()-1]=='O')
                help(board,r,board[0].size()-1,'O','Y');
        }
        
        for(int c=0;c<board[0].size();c++){
            if(board[0][c]=='O')
                help(board,0,c,'O','Y');
            if(board[board.size()-1][c]=='O')
                help(board,board.size()-1,c,'O','Y');
        }
        
        for(int r=1;r<board.size()-1;r++){
            for(int c=1;c<board[0].size()-1;c++){
                if(board[r][c]=='O')
                    help(board,r,c,'O','X');
            }
        }
        
        for(int r=0;r<board.size();r++){
            if(board[r][0]=='Y')
                help(board,r,0,'Y','O');
            if(board[r][board[0].size()-1]=='Y')
                help(board,r,board[0].size()-1,'Y','O');
        }
        
        for(int c=0;c<board[0].size();c++){
            if(board[0][c]=='Y')
                help(board,0,c,'Y','O');
            if(board[board.size()-1][c]=='Y')
                help(board,board.size()-1,c,'Y','O');
        }
        return;
    }
    
    void help(vector<vector<char>>& board,int r, int c,char ch_from,char ch_to){
        board[r][c]=ch_to;
        if(r-1>=0&&board[r-1][c]==ch_from)
            help(board,r-1,c,ch_from,ch_to);
        if(r+1<board.size()&&board[r+1][c]==ch_from)
            help(board,r+1,c,ch_from,ch_to);
        if(c-1>=0&&board[r][c-1]==ch_from)
            help(board,r,c-1,ch_from,ch_to);
        if(c+1<board[0].size()&&board[r][c+1]==ch_from)
            help(board,r,c+1,ch_from,ch_to);
    }
    
};
