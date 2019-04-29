class Solution {
public:
    int maximumSwap(int num) {
        //this solution was adapted from Stephan Pochmann
        //https://leetcode.com/problems/maximum-swap/discuss/107137/3-5-lines-PythonC%2B%2BJavaRuby
        int ans=num;
        for(int i=1;i<=num;i=i*10)
            for(int j=i;j<=num;j=j*10){
                ans=max(ans,num+(num/i)%10*(j-i)+(num/j)%10*(i-j));
            }
        return ans;
    }
};
