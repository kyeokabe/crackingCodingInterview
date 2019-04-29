class Solution {
public:
    string convertToBase7(int num) {
        
        if (num==0)
            return "0";
        
        bool neg=false;
        if(num<0)
            neg=true;
        num=abs(num);
        stack<int> foo;
        
        while(num!=0){
            foo.push(num%7);
            num=num/7;
        }
        //cout<<foo.size()<<endl;
        
        string ans="";
        if (neg)
            ans+='-';
        while(!foo.empty()){
            char a='0'+foo.top();
            ans=ans+a;
            foo.pop();
        }
        return ans;
    }
};
