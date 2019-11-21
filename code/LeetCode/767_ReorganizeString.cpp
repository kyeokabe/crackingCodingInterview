class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char,int> m;
        
        int maxfreq=0;
        char maxchar='a';
        
        for(int i=0;i<S.length();i++){
            m[S[i]]++;
            if(m[S[i]]>(S.length()+1)/2)
                return "";
            if(m[S[i]]>maxfreq){
                maxfreq=m[S[i]];
                maxchar=S[i];
            }
        }
        
        string temp="";
        for(int i=0;i<maxfreq;i++)
            temp+=maxchar;
        m.erase(maxchar);
        auto it=m.begin();
        while(it!=m.end()){
            for(int i=0;i<it->second;i++)
                temp+=it->first;
            it++;
        }
        
        string temp1="";
        string temp2="";
        
        if(S.length()%2==1){
            temp1=temp.substr(0,(temp.length()+1)/2);
            temp2=temp.substr((temp.length()+1)/2,temp.length()-((temp.length()+1)/2));
        }
        else{
            temp1=temp.substr(0,temp.length()/2);
            temp2=temp.substr(temp.length()/2,temp.length()/2);
        }
        string ans;
        int ptr1=0;
        int ptr2=0;
        while(ptr2<temp2.length()){
            ans+=temp1[ptr1];
            ans+=temp2[ptr2];
            ptr1++;
            ptr2++;
        }
        if(ptr1<temp1.length())
            ans+=temp1[ptr1];
        return ans;
    }
};
