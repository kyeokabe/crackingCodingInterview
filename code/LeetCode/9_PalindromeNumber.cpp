class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x<0)
            return false;
        if (x==0)
            return true;
        
        int num_digits=0;
        int y=x;
        while(y>0){
            num_digits++;
            y=y/10;
        }
        
        bool TorF=true;
        
        for (int i=0;i<num_digits/2;i++){
                //check ith digit (i=0,1,...) and num_digit-1-i match
            if(get_ith_num(x,i)!=get_ith_num(x,num_digits-1-i))
                TorF=false;
        }
        return TorF;
    }
    
    //returns ith (i=0,1,2,...) digit number from x
    int get_ith_num(int x, int i){
        for (int j=0;j<i;j++)
            x=x/10;
        return (x%10);
    }
    
};
