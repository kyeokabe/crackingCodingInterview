class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i=left;i<=right;i++){
            while(has0(i)){
                i++;
            }
            if(i>right)
                break;
            if(help(i))
                ans.push_back(i);
        }
        return ans;
    }
    
    bool has0(int i){
        int k=i;
        while(k!=0){
            if(k%10==0)
                return true;
            k=k/10;
        }
        return false;
    }
    
    bool help(int i){
        int k=i;
        stack<int> foo;
        while(k!=0){
            foo.push(k%10);
            k=k/10;
        }
        while(!foo.empty()){
            if (i%foo.top()!=0)
                return false;
            foo.pop();
        }
        return true;
    }
};
