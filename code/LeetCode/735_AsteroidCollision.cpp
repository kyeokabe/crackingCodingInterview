class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> s;
        for(int i=ast.size()-1;i>=0;i--){
            if(s.empty())
                s.push(ast[i]);
            else{
                if(s.top()<0&&ast[i]<0||s.top()>0&&ast[i]>0)
                    s.push(ast[i]);
                else if(s.top()>0&&ast[i]<0)
                    s.push(ast[i]);
                else{
                    while(!s.empty()&&s.top()<0&&ast[i]>0){
                        if(ast[i]>0&&s.top()<0&&abs(ast[i])<abs(s.top()))
                            break;
                        else if(ast[i]>0&&s.top()<0&&abs(ast[i])==abs(s.top())){
                            s.pop();
                            break;
                        }
                        else if(ast[i]>0&&s.top()<0&&abs(ast[i])>abs(s.top())){
                            while(!s.empty()&&ast[i]>0&&s.top()<0&&abs(ast[i])>abs(s.top())){
                                s.pop();
                            }
                            if(!s.empty()&&ast[i]>0&&s.top()<0&&abs(ast[i])==abs(s.top())){
                                s.pop();
                                break;
                            }
                            if(!s.empty()&&ast[i]>0&&s.top()<0&&abs(ast[i])<abs(s.top()))
                                break;
                            s.push(ast[i]);
                        }
                        else{
                            s.push(ast[i]);
                        }
                    }
                }
            }
        }
        
        vector<int> v(s.size(),0);
        int i=0;
        while(!s.empty()){
            v[i]=s.top();
            i++;
            s.pop();
        }
        return v;
    }
};
