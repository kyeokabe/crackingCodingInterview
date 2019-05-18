class Solution {
public:
    string addStrings(string num1, string num2) {
        while(num1.length()>num2.length()){
            num2="0"+num2;
        }
        while(num1.length()<num2.length()){
            num1="0"+num1;
        }
        string ans="";
        bool carry=false;
        for(int i=0;i<num1.length();i++){
            char temp='0'+(num1[num1.size()-1-i]-48)+(num2[num1.size()-1-i]-48)+carry;
            if (temp>'9'){
                temp=char(temp-10);
                carry=true;
            }
            else
                carry=false;
            ans=temp+ans;
        }
        if(carry)
            ans="1"+ans;
        return ans;
    }
};
