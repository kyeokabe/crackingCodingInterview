class Solution {
public:
    int numberOfWays(int num_people) {
        vector<int> v(1001,0);
        v[0]=1;
        v[2]=1;
        v[4]=2;
        v[6]=5;
        v[8]=14;
        
        return help(num_people,v);
    }
    
    int help(int num_people, vector<int> &v){

        int MOD=pow(10,9)+7;

        if(v[num_people]!=0)
            return v[num_people];
        
        long long count=0;
        for(int i=2;i<=num_people;i+=2){
            long long product_1 = (v[i-1-1]==0)?help(i-1-1,v):v[i-1-1];
            long long product_2 = (v[num_people-i]==0)?help(num_people-i,v):v[num_people-i];
            count+=((product_1%MOD)*(product_2%MOD))%MOD;
            count=count%MOD;
        }
        
        v[num_people]=int(count%MOD);
        return count;
    }
    
};
