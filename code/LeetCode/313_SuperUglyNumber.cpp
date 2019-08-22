class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        //deal with trivial case
        if(n<=0)
            return 0;
        //v[n-1] is the nth super ugly number in type long long
        vector<long long> v;
        //1 is the 1st super ugly number
        v.push_back(1);
        
        //index[i] contains the current position of
        //the index corresponding to primes[i]
        //where primes[i]*v[index[i]]<v[n]
        
        vector<int> index;
        for(int i=0;i<primes.size();i++){
            index.push_back(0);
        }
        
        while(v.size()<n){
            long long temp=INT_MAX;
            for(int i=0;i<primes.size();i++){
                temp=min(temp,primes[i]*v[index[i]]);
            }
            v.push_back(temp);
            for(int i=0;i<primes.size();i++){
                if(temp>=primes[i]*v[index[i]])
                    index[i]=index[i]+1;
            }
        }
        return int(v[n-1]);
    }
};
