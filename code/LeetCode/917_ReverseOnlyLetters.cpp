class Solution {
public:
    string reverseOnlyLetters(string S) {
        for(int i=0,j=S.length()-1;i<j;i++,j--){
            while(!isLetter(S[i]))
                i++;
            while(!isLetter(S[j]))
                j--;
            if(i<j)
                swap(S[i],S[j]);
        }
        return S;
    }
    
    bool isLetter(char a){
        if (a>='A'&&a<='Z'||a>='a'&&a<='z')
            return true;
        return false;
    }
};
