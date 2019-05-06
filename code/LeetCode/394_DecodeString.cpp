class Solution {
public:
    string decodeString(string s) {
        while(hasB(s)){
            s=Process(s);
        }
        return s;
    }
    
    bool hasB(string &s){
        for (int i=0;i<s.length();i++)
            if(s[i]=='[')
                return true;
        return false;
    }
    
    string Process(string s){
        int i=-1;//index of [
        for(int j=0;j<s.length();j++)
            if(s[j]=='[')
                i=j;
        int p=-1;//index of ]
        for(int q=i;q<s.length();q++)
            if(s[q]==']'){
                p=q;
                break;
            }
                
        int k=0;//numof reps
        int count=0;
        queue<char> num;

        for(int m=i-1;m>=0;m--){
            if(s[m]>='0'&&s[m]<='9')
                num.push(s[m]);
            else
                break;
        }
        if(num.empty())
            num.push('1');
        while(!num.empty()){
            k+=(int(num.front())-48)*pow(10,count);
            ++count;
            num.pop();
        }
        string temp="";//substring to be repeated
        for(int j=i+1;j<p;j++)
            temp+=s[j];
        string first="";
        for(int j=0;j<i-count;j++)//how to treat minus count
            first+=s[j];
        for(int j=0;j<k;j++)
            first+=temp;
        for(int j=p+1;j<s.length();j++)
            first+=s[j];

        return first;
    }
};
