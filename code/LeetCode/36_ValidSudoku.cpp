class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> v1;
        for (int i=0;i<10;i++)
            v1.push_back(0);
        
        //checks all cols don't have dups (condition 1)
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                if (board[i][j]!='.'){
                    v1[(int)board[i][j]-48]++;
                    if (v1[(int)board[i][j]-48]>1)
                        return false;
                }
            }
            for (int k=0;k<10;k++)
                v1[k]=0;
        }
        
        //checks all rows don't have dups (condition 2)
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                if (board[j][i]!='.'){
                    v1[(int)board[j][i]-48]++;
                    if (v1[(int)board[j][i]-48]>1)
                        return false;
                }
            }
            for (int k=0;k<10;k++)
                v1[k]=0;
        }     
        
        //check sub boxes (condition 3)
        for (int n=0;n<3;n++){
            for (int k=0;k<3;k++){
                for (int i=3*k;i<3*k+3;i++){
                    for (int j=3*n;j<3*n+3;j++){
                        if (board[i][j]!='.'){
                          v1[(int)board[i][j]-48]++;
                        if (v1[(int)board[i][j]-48]>1)
                         return false;
                        }
                    }
                }
                for (int m=0;m<10;m++)
                    v1[m]=0;
            }
        }
        return true;
    }
};
