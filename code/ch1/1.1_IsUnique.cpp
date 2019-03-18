// 1.1 Is Unique
// Implement an algorithm to determine if a string has all unique characters
// What if you cannot use additional data structures?

/*

 Cannot use additional data structure case not solved yet.
 
remember:
chars can be converted to int by (int)char command
string.length() gets length of string
*/

#include <iostream>
#include <stdio.h>
using namespace std;

bool isUnique(string a);

int main() {
    
    string a="vnwpoCac";
    bool isunique=isUnique(a);
    
    if (isunique)
        cout<< "chars are unique"<<endl;

    if (isunique!=true)
        cout<< "chars are not unique"<<endl;
    
    return 0;
}

bool isUnique(string a){
    
    int array[128];
    
    for (int i=0;i<128;i++)
        array[i]=0;
    
    for (int i=0;i<a.length();i++){
        array[(int)a[i]]++;
        if (array[(int)a[i]]>1)
            return false;
    }
    
    return true;
}
