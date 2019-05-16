class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        vector<string> ans;
        int count=list1.size()-1+list2.size()-1+1;
        unordered_map<string,int> m1;
        unordered_map<string,int> m2;
        
        for (int i=0;i<list1.size();i++)
            m1[list1[i]]=i;
        
        for (int i=0;i<list2.size();i++)
            m2[list2[i]]=i;
        
        for(auto it1=m1.begin();it1!=m1.end();it1++){
            auto it2=m2.find(it1->first);
            if(it2!=m2.end()){
                if(it1->second+it2->second==count)
                    ans.push_back(it1->first);
                else if(it1->second+it2->second<count){
                    ans={};
                    ans.push_back(it1->first);
                    count=it1->second+it2->second;
                }
            }    
        }
        return ans;
    }
};
