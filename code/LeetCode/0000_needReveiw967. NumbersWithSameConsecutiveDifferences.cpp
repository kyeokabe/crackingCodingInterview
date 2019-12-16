class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
    
        int n=N;
        
        vector<string> v;
        
        for(int i=1;i<=9;i++)
            v.push_back(to_string(i));
        
        N--;
        
        
        while(N>0){
            int SIZE=v.size();
            for(int i=0;i<SIZE;i++){
                cout<<"diff = "<<(v[i][v[i].length()-1]-48)-K<<endl;
                if(int(v[i][v[i].length()-1]-48)-K>=0)
                    if(int(v[i][v[i].length()-1]-48)-K<=9){
                        string s(1,char(K));
                        string temp=v[i]+s;
                        v.push_back(temp);
                        cout<<"pushed1 "<<temp<<endl;
                    }
                
                if(K-(v[i][v[i].length()-1]-48)>=0)
                    if(K-(v[i][v[i].length()-1]-48)<=9){
                        string s(1,char(K));
                        string temp=v[i]+s;
                        v.push_back(temp);
                        cout<<"pushed2 "<<temp<<endl;
                    }
            }
            
            vector<string> v2;
            for(int i=SIZE;i<v.size();i++)
                v2.push_back(v[i]);
            v=v2;
            N--;
        }
        
        vector<int> ans;
        for(int i=0;i<v.size();i++)
            ans.push_back(stoi(v[i]));
        
        if(n==1)
            ans.push_back(0);
        return ans;
    }
};
