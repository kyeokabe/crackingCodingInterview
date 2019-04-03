class Solution {
public:
    bool detectCapitalUse(string word) {
        //all char capitals
        bool condition1=true;
        bool condition2=true;
        bool condition3p1=true;
        bool condition3p2=true;

        
        for (int i=0;i<word.length();i++){
            if (!(word[i]>=65&&word[i]<=90))
                condition1=false;
            if (!(word[i]>=97&&word[i]<=122))
                condition2=false;
        }
        
        if (!(word[0]>=65&&word[0]<=90))
            condition3p1=false;
        if (word.length()>=2)
            for (int i=1;i<word.length();i++)
                if (!(word[i]>=97&&word[i]<=122))
                    condition3p2=false;
        
        bool condition3=condition3p1&&condition3p2;
        
        return (condition1||condition2||condition3);
    }
};
