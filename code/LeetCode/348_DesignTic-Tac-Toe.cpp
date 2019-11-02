class TicTacToe {

private:
    int N;
    vector<vector<int>> v;

public:

    /** Initialize your data structure here. */
    TicTacToe(int n) {
        vector<int> f(n,INT_MIN);
        for(int i=0;i<n;i++)
            v.push_back(f);
        N=n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        player==1?v[row][col]=1:v[row][col]=2;
        int count=N;
        for(int i=0;i<N;i++)
            if(v[i][col]==player)
                count--;
        if(count==0)
            return player;
        
        count=N;
        for(int j=0;j<N;j++)
            if(v[row][j]==player)
                count--;
        if(count==0)
            return player;
        
        count=N;
        for(int i=N-1,j=0;i>=0,j<N;i--,j++)
            if(v[i][j]==player)
                count--;
        if(count==0)
            return player;
        
        count=N;
        for(int i=0, j=0;i<N,j<N;i++,j++)
            if(v[i][j]==player)
                count--;
        if(count==0)
            return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
