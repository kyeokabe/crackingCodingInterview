//adapted from alexander
//https://leetcode.com/problems/accounts-merge/discuss/109157/JavaC%2B%2B-Union-Find

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acts) {
        //maps arbitrary email address to name
        unordered_map<string, string> owner;
        //maps arbitrary email address to parent email address
        unordered_map<string, string> parents;
        unordered_map<string, set<string>> unions;
        for (int i = 0; i < acts.size(); i++) {
            for (int j = 1; j < acts[i].size(); j++) {
                //all email addresses are assigned itself as parent
                parents[acts[i][j]] = acts[i][j];
                //mapps all email address to name
                owner[acts[i][j]] = acts[i][0];
            }
        }
        for (int i = 0; i < acts.size(); i++) {
            string p = find(acts[i][1], parents);
            //remapps all email addresses
            //mapped value is parent of first email
            for (int j = 2; j < acts[i].size(); j++)
                parents[find(acts[i][j], parents)] = p;
        }
        for (int i = 0; i < acts.size(); i++)
            for (int j = 1; j < acts[i].size(); j++){
                //all email addresses are mapped into parent set
                unions[find(acts[i][j], parents)].insert(acts[i][j]);
            }

        vector<vector<string>> res;
        
        for(auto it=unions.begin();it!=unions.end();it++){
            vector<string> temp;
            temp.push_back(owner[it->first]);//inserts name
            vector<string> emails(it->second.begin(),it->second.end());
            for(int i=0;i<emails.size();i++)
                temp.push_back(emails[i]);
            res.push_back(temp);
        }
        
        return res;
    }
private:
    //this function takes arbitrary email address s and 
    //arbitrary email to parent email address map p & return parant email address
    string find(string s, unordered_map<string, string>& p) {
        return p[s] == s ? s : find(p[s], p);
    }
};
