class Solution {
public:
    int minAddToMakeValid(string S) {
        int open=0;
        int closed=0;
        int ans=0;
        for(int i=0;i<S.length();i++){
            if(S[i]==')'){
                if(open>closed){
                    closed++;
                    continue;
                }
                else{
                    while(open<=closed){
                        open++;
                        ans++;
                    }
                    closed++;
                }
            }
            else{
                open++;
            }
        }
        ans+=open-closed;
        return ans;
    }
};
