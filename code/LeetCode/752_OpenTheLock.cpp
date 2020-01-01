class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> s;
        unordered_set<string> checked;

        for(int i=0;i<deadends.size();i++)
            s.insert(deadends[i]);
                
        string temp="0000";
        checked.insert(temp);

        if(s.find(temp)!=s.end())
            return -1;
        queue<string> q;
        q.push(temp);
        int count=0;
        while(!q.empty()){
            int SIZE=q.size();
            for(int i=0;i<SIZE;i++){
                if(q.front()==target)
                    return count;
                
                for(int j=0;j<4;j++){
                    string temp=q.front();
                    if(temp[j]>='1'){
                        temp[j]-=1;
                    }
                    else
                        temp[j]='9';
                    if(s.find(temp)==s.end()&&checked.find(temp)==checked.end()){
                        checked.insert(temp);
                        q.push(temp);
                    }
                    temp=q.front();
                    if(temp[j]<='8'){
                        temp[j]+=1;
                    }
                    else
                        temp[j]='0';
                    if(s.find(temp)==s.end()&&checked.find(temp)==checked.end()){
                        checked.insert(temp);
                        q.push(temp);
                    }   
                }
                q.pop();
            }
            count++;
        }
        return -1;
    }
};
