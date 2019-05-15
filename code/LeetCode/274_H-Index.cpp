class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h=0;
        sort(citations.begin(),citations.end(),[](int a, int b){return a>b;});
        for(int i=0;i<citations.size();i++){
            if(citations[i]>=i+1)
                ++h;
            else
                break;
        }
        return h;
    }
};
