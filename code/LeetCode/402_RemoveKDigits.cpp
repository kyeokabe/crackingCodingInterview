//tricky
//O(n) time
//O(n) memory
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k>=num.length())
            return "0";
        int numzero=0;
        for(int i=0;i<num.length();i++)
            if(num[i]=='0')
                numzero++;
        if(numzero+k>=num.length())
            return "0";
       
        stack<char> s;
        int count=0;
        
        for(int j=0;j<num.length();j++){
            if(s.empty()||s.top()<=num[j]||count==k)
                s.push(num[j]);
            else{
                 while(!s.empty()&&s.top()>num[j]&&k!=count){
                     s.pop();
                     count++;
                 }
                 s.push(num[j]);
            }
        }
        while(count<k){
            s.pop();
            count++;
        }
        string temp="";
        while(!s.empty()){
            temp=s.top()+temp;
            s.pop();
        }

        int i=0;
        while(i<temp.length()&&temp[i]=='0')
            i++;
        temp=temp.substr(i,temp.length()-i);
        return temp;
    }
};
