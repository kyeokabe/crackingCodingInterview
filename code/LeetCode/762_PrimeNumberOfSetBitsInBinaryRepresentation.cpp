class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int ans=0;
        for(int i=L;i<=R;i++){
            int k=i;
            int num=0;
            while(k>0){
                num+=k%2;
                k/=2;
            }
            if(num==0)
                continue;
            if(num==1)
                continue;
            if(isprime(num))
                ans++;
        }
        return ans;
    }
    
    bool isprime(int num){
        for(int i=2;i<num;i++)
            if(num%i==0)
                return false;
        return true;
    }
};
