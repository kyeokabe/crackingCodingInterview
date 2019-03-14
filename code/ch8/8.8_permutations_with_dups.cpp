//8.8 ... Permutations with Dups
//write a method to compute all permutations of a string
//whose characters are not necessarily unique. The list of
//permutations should not have duplicates.


/*
 Basically a math problem on combinations.
Key is to realize that at most the combinations
are that when assuming all chars are unique.
 
To count duplicates, simply think how many combinations
a char with dups can have.
 
i.e. A1,A2,A3 can have 3! combinations
     B1,B2,B3,B4 can have 4! combinations

divide maximum unique combinations with product of
possible overlapping combinations
(e.g. C,A1~3,B1~4 = 8!/(3!*4!))
*/

#include <iostream>
#include<stdio.h>
using namespace std;


int main() {

    string foo="bbbaaaac";
    
    int ascii_list[128];
    for (int i=0;i<128;i++)
        ascii_list[i]=0;
    
    for (int i=0;i<foo.length();i++){
        ascii_list[+foo[i]]++;
    }
    
    int numerator=1;
    for (int i=1;i<=foo.length();i++){
        numerator=numerator*i;
    }
    
    int denominator=1;
    for (int i=0;i<128;i++)
        if (ascii_list[i]>=2)
            for (int j=1;j<=ascii_list[i];j++)
                denominator=denominator*j;
    
    int ways=numerator/denominator;
    
    cout << "permutations = " << ways <<endl;
    return ways;
}

/*
 beaa
 ebaa
 baea
 eaba
 abea
 aeba
 eaab
 baae
 abae
 aeab
 aabe
 aaeb
 */
