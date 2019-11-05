class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='X'&&i==0&&j==0)
                    ans++;
                else if(board[i][j]=='X'&&i>0&&j==0&&board[i-1][j]=='.')
                    ans++;
                else if(board[i][j]=='X'&&j>0&&i==0&&board[i][j-1]=='.')
                    ans++;
                else if(board[i][j]=='X'&&i>0&&j>0&&board[i-1][j]=='.'&&board[i][j-1]=='.')
                    ans++;
            }
        }
        return ans;
    }
};
