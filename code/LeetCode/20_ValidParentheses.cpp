class Solution {
public:
    bool isValid(string s) {
        if (s=="")
            return true;
        stack <char> foo;
        
        for (int i=0;i<s.length();i++){
            if (s[i]=='(')
                foo.push('(');
            else if(s[i]=='{')
                foo.push('{');
            else if(s[i]=='[')
                foo.push('[');
            
            else if(s[i]==')'){
                if (foo.size()==0)
                    return false;
                else if(foo.top()=='(')
                    foo.pop();
                else
                    return false;
            }
            
            else if(s[i]==']'){
                if (foo.size()==0)
                    return false;
                else if(foo.top()=='[')
                    foo.pop();
                else
                    return false;
            }
            
            else if(s[i]=='}'){
                if (foo.size()==0)
                    return false;
                else if(foo.top()=='{')
                    foo.pop();
                else
                    return false;
            }  
        }
        
        if (foo.size()!=0)
            return false;
        
        return true;
    }
};
