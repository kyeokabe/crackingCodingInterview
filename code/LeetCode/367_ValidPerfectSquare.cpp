class Solution {
public:
    bool isPerfectSquare(int num) {
        for (long i=0;i<=num;i++){
            long temp = i*i;
            if (num==temp)
                return true;
            if (num<temp)
                return false;
        }
        return false;
    }
};
