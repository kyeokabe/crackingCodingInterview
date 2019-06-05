class Solution {
public:
    bool divisorGame(int N) {
        return (N%2==0);
    }
};

/*

N=1 -> Alice loose
N=2 -> Alice x=1, Alice win
N=3 -> Alice x=1, Alice loose
N=4 -> Alice x=1, Alice win
N=5 -> Alice x=1, Alice loose
N=6 -> Alice x=3

*/
