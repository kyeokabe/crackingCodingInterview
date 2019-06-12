class Solution {
public:
    bool canWinNim(int n) {
        if(n%4==0)
            return false;
        return true;
    }
};
/*

1~3 win(true)
4 -> false
5 -> 4 -> true
6 -> 4 -> true
7 -> 4 -> true
8 -> false
9 -> true

*/
