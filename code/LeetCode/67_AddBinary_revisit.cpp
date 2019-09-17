class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length()<b.length()){
            string c=a;
            a=b;
            b=c;
        }
        
        int k=a.length()-b.length();
        for (int i=0;i<k;i++)
            b="0"+b;
        
        int carry=0;
        string c="";
        cout<<a<<endl;
        cout<<b<<endl;
        
        for(int i=a.length()-1;i>=0;i--){
            if(a[i]=='0'&&b[i]=='0'&&carry==0)
                c="0"+c;
            else if(a[i]=='0'&&b[i]=='0'&&carry==1){
                c="1"+c;
                carry=0;
            }
            else if(a[i]=='0'&&b[i]=='1'&&carry==0)
                c="1"+c;
            else if(a[i]=='0'&&b[i]=='1'&&carry==1)
                c="0"+c;
            else if(a[i]=='1'&&b[i]=='0'&&carry==0)
                c="1"+c;
            else if(a[i]=='1'&&b[i]=='0'&&carry==1)
                c="0"+c;
            else if(a[i]=='1'&&b[i]=='1'&&carry==0){
                c="0"+c;
                carry=1;
            }
            else if(a[i]=='1'&&b[i]=='1'&&carry==1)
                c="1"+c;
            
        }
        if(carry==1)
            c="1"+c;
        return c;
    }
};
