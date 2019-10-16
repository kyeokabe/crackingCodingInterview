class Solution {
public:
    vector<string> letterCombinations(string digits) {  
        vector<string> ans;
        if(digits=="")
            return ans;
        map<char,set<char>> m;
        set<char> s2,s3,s4,s5,s6,s7,s8,s9;
        
        s2.insert('a');
        s2.insert('b');
        s2.insert('c');
        s3.insert('d');
        s3.insert('e');
        s3.insert('f');
        s4.insert('g');
        s4.insert('h');
        s4.insert('i');
        s5.insert('j');
        s5.insert('k');
        s5.insert('l');
        s6.insert('m');
        s6.insert('n');
        s6.insert('o');
        s7.insert('p');
        s7.insert('q');
        s7.insert('r');
        s7.insert('s');
        s8.insert('t');
        s8.insert('u');
        s8.insert('v');
        s9.insert('w');
        s9.insert('x');
        s9.insert('y');
        s9.insert('z');
        m['2']=s2;
        m['3']=s3;
        m['4']=s4;
        m['5']=s5;
        m['6']=s6;
        m['7']=s7;
        m['8']=s8;
        m['9']=s9;
        string temp="";
        help(digits,m,0,ans,temp);  
        return ans;
    }
    
    void help(string &digits, map<char,set<char>> &m,int i, vector<string> &ans, string &temp){
        if(i==digits.length()){
            ans.push_back(temp);
            return;
        }
        auto it=m.find(digits[i]);
        auto it2=it->second.begin();
        while(it2!=it->second.end()){
            temp+=*it2;
            help(digits,m,i+1,ans,temp);
            temp.pop_back();
            it2++;
        }
    }
};
