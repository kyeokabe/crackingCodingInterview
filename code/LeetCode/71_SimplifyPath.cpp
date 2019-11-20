/*
RECAP

step 1: deleted "/./" and "/." from path

step 1.5: added "/" to the end of the string for convenience of step 3

step 2: deleted duplicate "/" ... watch out for path[0] and path[1] for edge case

step 3: push "xxx/" into stacks, pop stack if new chunk of string is "../" and size allows

step 4: connect the remaining words in the stack together. Pop final "/" if length longer than 1

*/

class Solution {
public:
    string simplifyPath(string path) {
        string ans="/";
        
        int ptr=1;
        
        if(path.length()>1&&path[path.length()-1]=='.'&&path[path.length()-2]=='/')
            path=path.substr(0,path.length()-1);
        
        //remove home directory commands (/./)
        while(ptr<path.length()){
            if(ptr<path.length()-1&&(path[ptr-1]=='/'&&path[ptr]=='.'&&path[ptr+1]=='/'))
               ptr++;
            else{
               ans+=path[ptr];
            }
            ptr++;
        }
        ans+='/';
        ptr=1;
        
        string ans2="/";
        
        while(ptr<ans.length()){
            if(ans[ptr]=='/'&&ans[ptr+1]=='/'){
                ptr++;
                continue;
            }
            else
                ans2+=ans[ptr];
            ptr++;
        }
        
        if(ans2.length()>1&&ans2[1]=='/')
            ans2=ans2.substr(1,ans2.length()-1);
        
        stack<string> q;
        q.push("/");
        ptr=1;
        string temp;
        while(ptr<ans2.length()){
            if(ans2[ptr]!='/')
                temp+=ans2[ptr];
            else{
                temp+='/';
                if(temp=="../"){
                    if(q.size()>1)
                        q.pop();
                }
                else{
                    q.push(temp);
                }
                temp="";
            }
            ptr++;
        }
        string ans3="";
        while(!q.empty()){
            ans3=q.top()+ans3;
            q.pop();
        }
        
        if(ans3.length()>1)
            ans3.pop_back();
        return ans3;
    }
};
