/*
interesting question!
*/

class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N==1)
            return 0;
        if (K%2==1)
            return kthGrammar(N-1,(K+1)/2);
        if (kthGrammar(N-1,K/2)==0)
            return 1;
        else
            return 0;
    }
    
};
