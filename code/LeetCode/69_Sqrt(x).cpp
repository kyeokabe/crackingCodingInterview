class Solution {
public:
    int mySqrt(int x) {
        double i=0;
        double j=0;
        
        while (j<=x){
            i++;
            j=i*i;
        }
        return (int)(i-1);
    }
};
