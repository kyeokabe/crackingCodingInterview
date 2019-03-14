//8.7 write a method to compute all permutations of a string of unique characters.

//will assume input only has unique characters w/o duplicates

//3/13/2019
//Seemingly very trivial problem. Not sure why it is under recursion chapter...

#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    string foo="betas";
    //cout <<foo.length()<<endl;
    
    if (foo.length()==0)
        return 0;
    
    int permutations=1;
    for (int i=1;i<=foo.length();i++)
        permutations=permutations*i;
    cout<<"permutations = "<<permutations<<endl<<endl;
    return permutations;
}
