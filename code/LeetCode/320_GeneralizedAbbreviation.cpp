class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        string temp="";
        help(word,ans,temp,0);
        return ans;
    }
    
    void help(string &word, vector<string> &ans,string &temp,int i){          
        if(i==word.length()){
            ans.push_back(temp);
            return;
        } 
        for(int j=0;j<=word.length()-i;j++){
            if(j==0){
                temp+=word[i];
                help(word,ans,temp,i+1);
                temp.pop_back();
            }
            else{
                if(temp.length()>=1)
                    if(temp[temp.length()-1]>='0'&&temp[temp.length()-1]<='9')
                        return;
                temp+=to_string(j);
                int num_pop=to_string(j).length();
                help(word,ans,temp,i+j);
                for(int i=0;i<num_pop;i++)
                    temp.pop_back();
            }
        }
        
    }
    
};
