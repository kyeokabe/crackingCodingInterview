class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int ans=0;
        if(s.length()<=2)
            return s.length();
        char ch1=s[0];
        int count1=0;
        int i=0;
        while(i<s.length()&&s[i]==ch1){
            i++;
            count1++;
        }
        if(i>=s.length())
            return s.length();
        char ch2=s[i];
        int count2=0;
        
        
        while(i<s.length()&&((s[i]==ch1)||(s[i]==ch2))){
            if(s[i]==ch1)
                count1++;
            else if(s[i]=ch2)
                count2++;
            i++;
        }
        if(i>=s.length())
            return s.length();
        int j=0;
        ans=i-j;
        while(i<s.length()){
            if(s[i]!=ch1&&s[i]!=ch2){
                while(count1!=0&&count2!=0){
                    if(s[j]==ch1)
                        count1--;
                    if(s[j]==ch2)
                        count2--;
                    j++;
                }
                if(count1==0)
                    ch1=s[i];
                else
                    ch2=s[i];
                while(i<s.length()&&(s[i]==ch1||s[i]==ch2)){
                    if(s[i]==ch1)
                        count1++;
                    else
                        count2++;
                    i++;
                }
                if(i-j>ans)
                    ans=i-j;
            }
            else{
                while(i<s.length()&&(s[i]==ch1||s[i]==ch2)){
                    if(s[i]==ch1)
                        count1++;
                    else
                        count2++;
                    i++;
                }
            }
        }
        if(i-j>ans)
            ans=i-j;
        //cout<<i<<endl;
        //cout<<j<<endl;
        return ans; 
    }
};
