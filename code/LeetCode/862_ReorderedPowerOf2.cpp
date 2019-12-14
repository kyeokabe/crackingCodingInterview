class Solution {
public:
    bool reorderedPowerOf2(int N) {
        vector<int> v;
        while(N!=0){
            v.push_back(N%10);
            N/=10;
        }
        sort(v.begin(),v.end());
        if(v[0]!=0){
            int temp=0;
            int j=0;
            for(int i=v.size()-1;i>=0;i--){
                temp+=v[i]*pow(10,j);
                j++;
            }
            for(int i=0;i<=31;i++)
                if(temp==pow(2,i))
                    return true;
        }
        while(next_permutation(v.begin(),v.end())){
            if(v[0]!=0){
                int temp=0;
                int j=0;
                for(int i=v.size()-1;i>=0;i--){
                    temp+=v[i]*pow(10,j);
                    j++;
                }
                for(int i=0;i<=31;i++)
                    if(temp==pow(2,i))
                        return true;
            }
        }
        return false;
    }
};
