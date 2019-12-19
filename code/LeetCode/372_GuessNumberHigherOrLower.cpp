// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int L=1;
        int H=n;
        
        while(L<H){
            int temp=guess(int((long(H)+long(L))/2));
            if(temp==0)
                return int((long(H)+long(L))/2);
            if(temp==1)
                L=int((long(H)+long(L))/2);
            else
                H=int((long(H)+long(L))/2);
            if(guess(L)==0)
                return L;
            if(guess(H)==0)
                return H;
        }
        return 1;
    }
};
