// 1.2 Given two strings, write a method to decide if
// one is a permutation of another

/*

Assumed caps are distinguashed and spaces count as well
i.e. "Foo" and "foo" are different and
     "a " and "a   " are different.
 
Used a hash table to evaluate permutations
Pretty straight forward problem

remember:
chars can be converted to int by (int)char command
*/

#include <iostream>
#include <stdio.h>
using namespace std;

bool permutation(string a, string b);

int main() {
    
    string a="opo F";
    string b="F oop";
    
    cout<< "T or F?: "<< permutation(a,b) <<endl;
    
    return 0;
}

bool permutation(string a, string b){
    
    if (a.length()!=b.length())
        return false;
    
    int a_array[128];
    int b_array[128];

    for (int i=0;i<128;i++){
        a_array[i]=0;
        b_array[i]=0;
    }

    for (int i=0;i<a.length();i++){
        a_array[(int)a[i]]++;
        b_array[(int)b[i]]++;
    }
    
    for (int i=0;i<128;i++)
        if (a_array[i]!=b_array[i])
            return false;
    return true;
}
