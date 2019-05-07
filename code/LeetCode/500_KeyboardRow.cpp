class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        map<char,char> m1;
        m1['q']='q';
        m1['w']='w';
        m1['e']='e';
        m1['r']='r';
        m1['t']='t';
        m1['y']='y';
        m1['u']='u';
        m1['i']='i';
        m1['o']='o';
        m1['p']='p';
        m1['Q']='Q';
        m1['W']='W';
        m1['E']='E';
        m1['R']='R';
        m1['T']='T';
        m1['Y']='Y';
        m1['U']='U';
        m1['I']='I';
        m1['O']='O';
        m1['P']='P';
        //
        map<char,char> m2;
        m2['a']='a';
        m2['s']='s';
        m2['d']='d';
        m2['f']='f';
        m2['g']='g';
        m2['h']='h';
        m2['j']='j';
        m2['k']='k';
        m2['l']='l';
        m2['A']='A';
        m2['S']='S';
        m2['D']='D';
        m2['F']='F';
        m2['G']='G';
        m2['H']='H';
        m2['J']='J';
        m2['K']='k';
        m2['L']='L';
        //
        map<char,char> m3;
        m3['z']='z';
        m3['x']='x';
        m3['c']='c';
        m3['v']='v';
        m3['b']='b';
        m3['n']='n';
        m3['m']='m';
        m3['Z']='Z';
        m3['X']='X';
        m3['C']='C';
        m3['V']='V';
        m3['B']='B';
        m3['N']='N';
        m3['M']='M';
        
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            if(help(words[i],m1,m2,m3))
                ans.push_back(words[i]);
        }
        return ans;
    }
    bool help(string &s, map<char,char> &m1,map<char,char> &m2,map<char,char> &m3){
        for(int i=0;i<s.length();i++){
            auto it=m1.find(s[i]);
            if(it==m1.end())
                break;
            else
                if(i==s.length()-1)
                    return true;
                
            }
        
        for(int i=0;i<s.length();i++){
            auto it=m2.find(s[i]);
            if(it==m2.end())
                break;
            else
                if(i==s.length()-1)
                    return true;
            }
        
        for(int i=0;i<s.length();i++){
            auto it=m3.find(s[i]);
            if(it==m3.end())
                break;
            else
                if(i==s.length()-1)
                    return true;
            }
        return false;
    }
};
