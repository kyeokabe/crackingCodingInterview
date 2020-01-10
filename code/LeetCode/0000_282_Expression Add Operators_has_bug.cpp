class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string temp="";
        help(num,temp,target,ans);
        return ans;
    }
    
    void help(string &num, string &temp, int &target, vector<string> &ans){
        if(num.length()==0)
        {
            if(eval(temp,target))
                ans.push_back(temp);
            return;
        }
        
        if(num.length()==1){
            temp=temp+num[0];
            num="";
            help(num,temp,target,ans);
            num=temp[temp.length()-1];
            temp=temp.substr(0,temp.length()-1);
            return;
        }
        
        //addition
        temp=temp+num[0]+"+";
        num=num.substr(1,num.length()-1);
        help(num,temp,target,ans);
        num=temp[temp.length()-2]+num;
        temp=temp.substr(0,temp.length()-2);
        
        //multiplication
        temp=temp+num[0]+"*";
        num=num.substr(1,num.length()-1);
        help(num,temp,target,ans);
        num=temp[temp.length()-2]+num;
        temp=temp.substr(0,temp.length()-2);
        
        //subtraction
        temp=temp+num[0]+"-";
        num=num.substr(1,num.length()-1);
        help(num,temp,target,ans);
        num=temp[temp.length()-2]+num;
        temp=temp.substr(0,temp.length()-2);
    }
    
    bool eval(string temp,int target){
        string temp5=temp;
        cout<<"evaluating: "<<temp<<endl;
        stack<string> s;
        while(temp.length()!=0){
            int i=0;
            while(i<temp.length()&&temp[i]>='0'&&temp[i]<='9')
                i++;
            s.push(temp.substr(0,i));
            if(i==temp.length())
                break;
            temp=temp.substr(i,temp.length()-i);

            if(temp[0]=='*'){
                temp=temp.substr(1,temp.length()-1);
                int k=0;
                while(k<temp.length()&&temp[k]>='0'&&temp[k]<='9')
                    k++;
                long s1=stol(s.top());
                long s2=stol(temp.substr(0,k));
                long s3=s1*s2;
                cout<<"s1 = "<<s1<<endl;
                cout<<"s2 = "<<s2<<endl;
                cout<<"s3 = "<<s3<<endl;

                //cout<<"s3 = "<<s3<<endl;
                s.pop();
                s.push(to_string(s3));
                cout<<"g"<<endl;
                if(k==temp.length())
                    break;
                temp=temp.substr(k,temp.length()-k);

            }
            else if(temp[0]=='+'||temp[0]=='-'){
                s.push(temp.substr(0,1));
                temp=temp.substr(1,temp.length()-1);
            }
        }
        
        cout<<temp<<" break"<<endl;
        cout<<"size of s = "<<s.size()<<endl;
        if(temp5=="1*1+1"){
            while(!s.empty()){
                cout<<s.top()<<endl;
                s.pop();
            }
        }
        
        
        while(s.size()>1){
            cout<<"size of s = "<<s.size()<<endl;
            long s1=stol(s.top());
            s.pop();
            string strr=s.top();
            s.pop();
            if(!s.empty())
                cout<<"s size"<<s.size()<<endl;
            cout<<s.top()<<endl;
            long s2=stol(s.top());
            s.pop();
            cout<<"try here2"<<endl;

            
            if(strr=="+"){
                long g=s2+s1;
                s.push(to_string(g));
            }
            else{
                long g=s2-s1;
                s.push(to_string(g));                
            }
        }
        cout<<"almost"<<endl;
        if(stoi(s.top())==target)
            return true;
        return false;
    }
    
    
};
