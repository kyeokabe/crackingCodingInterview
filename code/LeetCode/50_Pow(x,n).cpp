class Solution {
public:
    double myPow(double x, int n) {
        double y=x;

        if (n>1){
            if (n%2==0){
                double temp=myPow(x,n/2);
                return temp*temp;
            }
            if (n%2==1){
                double temp=myPow(x,(n-1)/2);
                return y*temp*temp;
            }
        }
        
        if (n<0){
            if (n%2==0){
                double temp=myPow(x,(-(n/2)));
                return 1.0/(temp*temp);
            }
            if (n%2==-1){
                double temp=myPow(x,-((n+1)/2));
                return 1.0/(y*temp*temp);
            }
        }
        
        
        if (n==0)
            return 1.0;
        //if (n==1)
        return x;
    }
};
