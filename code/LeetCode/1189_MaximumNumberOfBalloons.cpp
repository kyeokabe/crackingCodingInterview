class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        int b,a,l,o,n;
        b=a=l=o=n=0;
        
        for(int i=0;i<text.length();i++){
            if(text[i]=='b')
                b++;
            if(text[i]=='a')
                a++;
            if(text[i]=='l')
                l++;
            if(text[i]=='o')
                o++;
            if(text[i]=='n')
                n++;
        }
        cout<<"b = "<<b<<endl;
        cout<<"a = "<<a<<endl;
        cout<<"l = "<<l<<endl;
        cout<<"o = "<<o<<endl;
        cout<<"n = "<<n<<endl;
        
        int ans=0;
        while(b>=1&&a>=1&&l>=2&&o>=2&&n>=1){
            ans+=1;
            b--;
            a--;
            l--;
            l--;
            o--;
            o--;
            n--;
        }
        return ans;
    }
};
