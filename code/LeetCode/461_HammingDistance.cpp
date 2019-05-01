class Solution {
public:
    int hammingDistance(int x, int y) {
        int foo=x^y;
        int ans=0;
        while (foo!=0){
            if (foo%2==1)
                ++ans;
            foo=foo>>1;
        }
        return ans;
    }
};
