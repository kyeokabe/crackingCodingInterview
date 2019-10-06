class Solution {
public:
    int countVowelPermutation(int n) {
        if(n==0)
            return 1;//based on testcase run
        int a=1;
        int e=1;
        int i=1;
        int o=1;
        int u=1;
        
        int m=1;
        
        while(m<n){
            
            //declare updated vals
            long new_a=0,new_e=0,new_i=0,new_o=0,new_u=0;
            
            //a rules
            new_e+=a;
            //e rules
            new_a+=e;
            new_i+=e;
            //i rules
            new_a+=i;
            new_e+=i;
            new_o+=i;
            new_u+=i;
            //o rules
            new_i+=o;
            new_u+=o;
            //u rules
            new_a+=u;
            
            //update old values
            a=(new_a%int(pow(10,9)+7));
            e=(new_e%int(pow(10,9)+7));
            i=(new_i%int(pow(10,9)+7));
            o=(new_o%int(pow(10,9)+7));
            u=(new_u%int(pow(10,9)+7));
            
            m++;
        }
        
        int temp1=(a+e)%int(pow(10,9)+7);
        int temp2=(i+o)%int(pow(10,9)+7);
        int temp3=(temp1+temp2)%int(pow(10,9)+7);
        int ans=(temp3+u)%int(pow(10,9)+7);
        
        return ans;
    }
};
