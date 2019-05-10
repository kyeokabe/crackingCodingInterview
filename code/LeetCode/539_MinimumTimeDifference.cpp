class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        if(timePoints.size()>60*24)//cool trick seen in discussions
            return 0;
        vector<int> v;
        for(int i=0;i<timePoints.size();i++)
            v.push_back(help(timePoints[i]));
        sort(v.begin(),v.end());
        int a=v[1]-v[0];
        int b=v[0]+24*60-v[v.size()-1];
        int min = a < b ? a : b;
        for(int i=0;i<v.size()-1;i++)
            if(v[i+1]-v[i]<min)
                min=v[i+1]-v[i];
        return min;
    }
    
    int help(string s){
        string s1,s2;
        bool seen =false;
        for(int i=0;i<s.length();i++){
            if(s[i]==':')
                seen=true;
            else if(seen)
                s2+=s[i];
            else
                s1+=s[i];
        }
        return stoi(s2)+stoi(s1)*60;
    }  
};
