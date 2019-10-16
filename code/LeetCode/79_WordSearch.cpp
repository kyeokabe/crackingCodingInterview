class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.length()==0)
            return false;
        if(word.length()>board.size()*board[0].size())
            return false;
        for(int r=0;r<board.size();r++)
            for(int c=0;c<board[0].size();c++){
                if(board[r][c]==word[0])
                    if(help(r,c,0,board,word)==true)
                        return true;
            }
        return false;
    }
    
    bool help(int r, int c, int i, vector<vector<char>>& board, string &word){
        if(i>word.length())
            return true;
        if(board[r][c]==word[i]){
            if(i+1==word.length())
                return true;
            char temp=board[r][c];
            board[r][c]='.';
            bool conditions=false;
            //go down
            if(r+1<board.size()){
                if(help(r+1,c,i+1,board,word)==true)
                    return true;
            }
            //go up
            if(r-1>=0){
                if(help(r-1,c,i+1,board,word)==true)
                    return true;
            }
            //go right
            if(c+1<board[0].size()){
                if(help(r,c+1,i+1,board,word)==true)
                    return true;
            }
            //go down
            if(c-1>=0){
                if(help(r,c-1,i+1,board,word)==true)
                    return true;
            }
            board[r][c]=temp;
            return false;
        }
        return false;
    }
    
};
