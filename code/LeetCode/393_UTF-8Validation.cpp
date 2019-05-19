class Solution {
public:
    bool validUtf8(vector<int>& data) {
        vector<string> s;
        for(int i=0;i<data.size();i++){
            int count=0;
            queue<char> q;
            string temp="";
            while(data[i]!=0){
                if(data[i]%2==1){
                    q.push('1');
                }
                else{
                    q.push('0');
                }
                ++count;
                data[i]=data[i]/2;
            }
            while(count!=8){
                q.push('0');
                ++count;
            }
            while(!q.empty()){
               temp=q.front()+temp;
                q.pop();
            }
            s.push_back(temp);
        }
        
        for(int i=0;i<s.size();i++)
            cout<<s[i]<<endl;
        
        for(int i=0;i<s.size();i++){
            if(s[i][0]=='1'&&s[i][1]=='1'&&s[i][2]=='1'&&s[i][3]=='1'&&s[i][4]=='0'){
                if(i+3>=s.size())
                    return false;
                if(!(s[i+1][0]=='1'&&s[i+1][1]=='0'&&s[i+2][0]=='1'&&s[i+2][1]=='0'&&s[i+3][0]=='1'&&s[i+3][1]=='0'))
                    return false;
                i=i+3;
            }
            else if(s[i][0]=='1'&&s[i][1]=='1'&&s[i][2]=='1'&&s[i][3]=='0'){
                if(i+2>=s.size())
                    return false;
                if(!(s[i+1][0]=='1'&&s[i+1][1]=='0'&&s[i+2][0]=='1'&&s[i+2][1]=='0'))
                    return false;  
                i=i+2;
            }
            else if(s[i][0]=='1'&&s[i][1]=='1'&&s[i][2]=='0'){
                if(i+1>=s.size())
                    return false;
                if(!(s[i+1][0]=='1'&&s[i+1][1]=='0'))
                    return false;  
                i=i+1;
            }
            else if(s[i][0]=='0'){
                //do nothing
                int aaa=9;
            }
            else
                return false;
            
        }
        return true;
    }
};
