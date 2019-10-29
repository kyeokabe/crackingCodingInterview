//very good video explanation
//https://www.youtube.com/watch?v=_mbnPPHJmTQ

//initially my solution idea was something like
/*
int blob(int i){
    if(s[i]=='#')
        return i+1;
    else{
        if(s[i+1]=='#')
            return blob(i+2);
        else
            return blob(blob(i+1));
    }
}
*/
//however, handling several edge cases becomes a headache

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int i=0;
        int arrow=1;
        while(i<preorder.length()){
            if(arrow<=0&&i!=preorder.length())
                return false;
            if(preorder[i]=='#'){
                arrow--;
                i++;
                continue;
            }
            else if(preorder[i]==','){
                i++;
                continue;
            }
            else{
                i++;
                arrow++;
                while(i<preorder.length()&&(preorder[i]!=','&&preorder[i]!='#'))
                    i++;
            }
        }
        return (arrow==0)?true:false;
    }
};
