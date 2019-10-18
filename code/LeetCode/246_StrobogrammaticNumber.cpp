class Solution {
public:
    bool isStrobogrammatic(string num) {
        if(num.length()%2==0){
            while(num.length()>0){
                if(num[0]=='6'&&num[num.length()-1]=='9')
                    num=num.substr(1,num.length()-2);
                else if(num[0]=='9'&&num[num.length()-1]=='6')
                    num=num.substr(1,num.length()-2);
                else if(num[0]=='8'&&num[num.length()-1]=='8')
                    num=num.substr(1,num.length()-2);
                else if(num[0]=='0'&&num[num.length()-1]=='0')
                    num=num.substr(1,num.length()-2);
                else if(num[0]=='1'&&num[num.length()-1]=='1')
                    num=num.substr(1,num.length()-2);
                else
                    return false;
            }
            return true;
        }
        else{
            
            while(num.length()>1){
                if(num[0]=='6'&&num[num.length()-1]=='9')
                    num=num.substr(1,num.length()-2);
                else if(num[0]=='9'&&num[num.length()-1]=='6')
                    num=num.substr(1,num.length()-2);
                else if(num[0]=='8'&&num[num.length()-1]=='8')
                    num=num.substr(1,num.length()-2);
                else if(num[0]=='0'&&num[num.length()-1]=='0')
                    num=num.substr(1,num.length()-2);
                else if(num[0]=='1'&&num[num.length()-1]=='1')
                    num=num.substr(1,num.length()-2);
                else
                    return false;
            }
            if(num[0]!='8'&&num[0]!='1'&&num[0]!='0')
                return false;
            return true;
        }
    }
};
