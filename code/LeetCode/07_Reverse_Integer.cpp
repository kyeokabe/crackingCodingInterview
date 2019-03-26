/*
took way longer than it should have

trick: use long for internal processing,
then evaluate at the last moment if overflow

idea is easy, taking care of the details  
such as example above is what took time.

*/

class Solution {
public:
    int reverse(int x) {
        //cout<<x<<endl;
        if(x==(-pow(2,31)))
            return 0;
        bool isNeg=false;
        if(x<0)
            isNeg=true;
        x=abs(x);
        
        stack<int> foo;
        int digits=getDigits(x, foo);
        //cout<<x<<endl<<endl;
        long k=0;
        for (int i=0;i<digits;i++){
            //cout<<foo.top()<<" "<<foo.top()*pow(10,i)<<endl;
            k=k+foo.top()*pow(10,i);
            //cout<<"k = "<<k<<endl;
            foo.pop();
            }

        if (isNeg){
            if (k>=pow(2,31))
                return 0;
            return -(int)k;
        }
        if(k>=pow(2,31))
            return 0;
        return k;
    }
    
    int getDigits(int x, stack<int> &foo){
        int digits=0;
        while(x!=0){
            foo.push(x%10);
            x=x/10;
            digits++;
        }
        return digits;
    }
};
