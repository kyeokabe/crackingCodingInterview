class Solution {
public:
    int mirrorReflection(int p, int q) {
        int n=1;
        int m=1;
        while(n*p>m*q){
            m++;
            if(n*p==m*q)
                break;
            if(n*p<m*q){
                n++;
                m=1;
            }
        }
        
        if(n%2==1){
            if(m%2==1)
                return 1;
            else
                return 2;
        }
        else{
                return 0;
        }
    }
};
