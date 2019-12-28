class Solution {
public:
    string numberToWords(int num) {
        if(num==0)
            return "Zero";
        
        string ans;
        
        if(num>=pow(10,9)){
            int temp=num-num%(POW(10,9));
            temp/=POW(10,9);
            ans+=help(temp);
            ans+=" Billion ";
            num=num%(POW(10,9));
        }
        
        if(num>=pow(10,6)){
            int temp=num-num%(POW(10,6));
            temp/=POW(10,6);
            ans+=help(temp);
            ans+=" Million ";
            num=num%(POW(10,6));
        }
        
        if(num>=POW(10,3)){
            int temp=num-num%(POW(10,3));
            temp/=POW(10,3);
            ans+=help(temp);
            ans+=" Thousand ";
            num=num%(POW(10,3));
        }
        
        if(num!=0)
            ans+=help(num);
        string ans2=ans.substr(0,1);
        for(int i=1;i<ans.length();i++){
            if(ans[i]==' '&&ans[i-1]==' '){
                //do nothing
            }
            else{
                ans2+=ans[i];
            }
        }
        if(ans2.back()==' ')
            ans2.pop_back();
        return ans2;
    }
    
    int POW(int a,int b){
        int k=1;
        for(int i=0;i<b;i++)
            k=k*a;
        return k;
    }
    
    string help(int n){
        string ans="";
        vector<string> nums={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen","Twenty"};
        vector<string> tens={"Zero","Tens","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        
        if(n>99){
            ans+=nums[(n-n%100)/100]+" Hundred ";
            n=n%100;
        }
        if(n==0)
            return ans;
        if(n>=21){
            ans+=tens[n/10];
            n=n%10;
            if(n==0)
                return ans;
            else
            {
                ans+=" ";
                ans+=nums[n];
                return ans;
            }
        }
        else{
            ans+=nums[n];
            return ans;
        }
        
    }
};
