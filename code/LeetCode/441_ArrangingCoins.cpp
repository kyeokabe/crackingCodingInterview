class Solution {
public:
    int arrangeCoins(int n) {
        if(n==0)
            return 0;
        int count=1;
        long sum=0;
        while(n>sum){
            sum+=count;
            if(sum==n)
                return count;
            if(sum>n)
                return count-1;
            count++;
        }
        return -1;
    }
};
