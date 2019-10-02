class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        q.push(beginWord);
        
        for(int i=0;i<wordList.size();i++)
            if(wordList[i]==beginWord){
                wordList[i]=wordList[wordList.size()-1];
                wordList.pop_back();
            }
        
        int count=1;
        
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                if(q.front()==endWord)
                    return count;
                for(int j=0;j<wordList.size();j++){
                    if(oneDifferent(wordList[j],q.front())){
                        q.push(wordList[j]);
                        wordList[j]=wordList[wordList.size()-1];
                        //took some time to realize I needed the
                        //following two lines to take care of
                        //situations where the new w[j] should be
                        //pushed as well
                        if(j!=wordList.size()-1)
                            j--;
                        wordList.pop_back();
                    }
                }
                q.pop();
            }
            count++;
        }
        return 0;
    }
    
    
    
    bool oneDifferent(string a, string b){
        if(a.length()!=b.length())
            return false;
        if(a==b)
            return false;
        
        int i=0;
        while(i!=a.length()){
            if(a[i]!=b[i])
                break;
            i++;
        }
        i++;
        while(i!=a.length()){
            if(a[i]!=b[i])
                break;
            i++;
        }
        if(i!=a.length())
            return false;
        return true;
    }
    
};
