class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        
        vector<string> ans;
        vector<string> nums;
        vector<vector<string>> chars;

        for(int i=0;i<logs.size();i++){
            
            int j=0;
            while(logs[i][j]!=' ')
                j++;
            while(logs[i][j]==' ')
                j++;
            
            if(logs[i][j]>='0'&&logs[i][j]-57<=0)
                nums.push_back(logs[i]);
            else{
                vector<string> temp={logs[i].substr(j,logs[i].length()-j),logs[i]};
                chars.push_back(temp);
            }
        }
        
        sort(chars.begin(),chars.end());
        
        for(int i=0;i<chars.size();i++){
            ans.push_back(chars[i][1]);
        }
        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[i]);
        }
        return ans;
    }
};
