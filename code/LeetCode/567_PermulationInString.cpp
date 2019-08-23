class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())
            return false;
        
        //make map that contains chars and freq of s1
        unordered_map <char,int> m;
        for(int i=0;i<s1.length();i++){
            auto it = m.find(s1[i]);
            if(it!=m.end()){
                ++it->second;
            }
            else
                m.insert({s1[i],1});
        }
        
        
        int NumOfIter=s2.length()-s1.length()+1;
        int ptr=0;
                
        for(int i=0;i<NumOfIter;i++){
            int wordlength=0;
            unordered_map<char,int> m2;
            m2=m;
            for(int j=ptr;j<ptr+s1.length();j++){
                if(ptr+s1.length()>s2.length())
                    return false;

                auto it=m2.find(s2[j]);
                
                if(it==m2.end()){
                    ptr++;
                    break;
                }
                
                if(it->second==0){
                    ptr++;
                    break;
                }
                it->second--;
                wordlength++;
                if(wordlength==s1.length())
                    return true;
            }
        }
        
        return false;
    }
};
