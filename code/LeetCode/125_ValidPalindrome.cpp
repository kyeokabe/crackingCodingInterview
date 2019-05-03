class Solution {
public:
    bool isPalindrome(string s) {
        stack<char> foo;
        stack<char> bar;
        
        for (int i=0;i<s.length();i++){
            if(isalphanum(s[i])){
                foo.push(makesmall(s[i]));
            }       
        }
        
        for (int i=s.length()-1;i>=0;i--){
            if(isalphanum(s[i]))
                bar.push(makesmall(s[i]));
        }
        
        while(!foo.empty()){
            if (foo.top()!=bar.top()){
                //cout<<"foo.top() = "<<foo.top()<<endl;
                //cout<<"bar.top() = "<<bar.top()<<endl;
                return false;
            }
            foo.pop();
            bar.pop();
        }
        return true;
    }
    
    bool isalphanum(char a){
        if(a>='A'&&a<='Z'||a>='a'&&a<='z'||a>='0'&&a<='9')
            return true;
        return false;
    }
    
    char makesmall(char a){
        if (a>='A'&&a<='Z')
            return a+32;
        return a;
    }
    
};
