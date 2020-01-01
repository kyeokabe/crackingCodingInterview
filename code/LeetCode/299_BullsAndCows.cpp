class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0;
        int cows=0;
        string ans;
        
        int i=0;
        
        while(i!=secret.length()){
            if(secret[i]==guess[i]){
                bulls++;
                secret[i]='X';
                guess[i]='X';
            }
            else{
                //do nothing
            }
            i++;
        }
        vector<int> v1(10,0);
        vector<int> v2(10,0);
        i=0;
        while(i!=secret.length()){
            if(secret[i]>='0'&&secret[i]<='9'){
                v1[secret[i]-48]++;
                v2[guess[i]-48]++;
            }
            i++;
        }
        for(int j=0;j<v1.size();j++)
            cows+=min(v1[j],v2[j]);
        ans=to_string(bulls)+"A"+to_string(cows)+"B";
        return ans;
    }
};
