class Solution {
public:
    string addBinary(string a, string b) {
        int a_len=a.length();
        int b_len=b.length();
        
        if (a_len>b_len)
            for (int i=0;i<(a_len-b_len);i++)
                b="0"+b;
        else
            for (int i=0;i<(b_len-a_len);i++)
                a="0"+a;
        
        string c="";
        
        a_len=a.length();
        int carry=0;
        for (int i=0;i<a_len;i++){
            if (a[a_len-1-i]=='0' && b[a_len-1-i]=='0' && carry==0){
                c="0"+c;
            }
            else if (a[a_len-1-i]=='1' && b[a_len-1-i]=='0' && carry==0)
                c="1"+c;
            else if (a[a_len-1-i]=='0' && b[a_len-1-i]=='1' && carry==0)
                c="1"+c;
            else if (a[a_len-1-i]=='1' && b[a_len-1-i]=='1' && carry==0){
                c="0"+c;
                carry=1;
            }
            else if(a[a_len-1-i]=='0' && b[a_len-1-i]=='0' && carry==1){
                c="1"+c;
                carry=0;
            }
            else if (a[a_len-1-i]=='1' && b[a_len-1-i]=='0' && carry==1){
                c="0"+c;
            }
            else if (a[a_len-1-i]=='0' && b[a_len-1-i]=='1' && carry==1){
                c="0"+c;
            }
            else if (a[a_len-1-i]=='1' && b[a_len-1-i]=='1' && carry==1){
                c="1"+c;
            }

        }
        
        if (carry==1)
            c="1"+c;
        
        return c;
    }
};
