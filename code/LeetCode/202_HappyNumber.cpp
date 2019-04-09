class Solution {
public:
    bool isHappy(int n) {
        int sum=0;
        map<int,int> foo;
        while (sum!=1){
            while(n!=0){
                sum+=(n%10)*(n%10);
                n=n/10;
            }
            n=sum;
            sum=0;
            auto it = foo.find(n);
            if (it!=foo.end()&&n!=1)
                return false;
            foo[n]=n;
            if (n==1)
                break;
        }
        return true;
    }
};
