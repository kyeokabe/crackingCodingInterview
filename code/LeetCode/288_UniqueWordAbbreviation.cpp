class ValidWordAbbr {
unordered_map<string,int> m_orig;
unordered_map<string,int> m_abbr;
    
public:
    ValidWordAbbr(vector<string>& d) {
        for(int i=0;i<d.size();i++){
            string temp;
            if(d[i].length()<=2){
                temp=d[i];
            }
            else{
                temp+=d[i][0];
                int foo=d[i].length()-2;
                temp+=to_string(foo);
                temp+=d[i][d[i].length()-1];     
            }
            
            auto it=m_abbr.find(temp);
            if(it!=m_abbr.end()){
                auto it2=m_orig.find(d[i]);
                if(it2!=m_orig.end()){
                    //do nothing
                }
                else{
                    m_orig[d[i]]++;
                    m_abbr[temp]++;
                }
            }
            else{
                m_orig[d[i]]++;
                m_abbr[temp]++;
            }
        }
    }
    
    bool isUnique(string word) {
        string temp;
        if(word.length()<=2)
            temp=word;
        else{
            temp+=word[0];
            int foo=word.length()-2;
            temp+=to_string(foo);
            temp+=word[word.length()-1];
        }
        
        auto it=m_abbr.find(temp);
        if(it==m_abbr.end())
            return true;
        else{
            auto it2=m_orig.find(word);
            if(it2!=m_orig.end()&&it->second==1)
                return true;
            return false;
            }
    }
};
