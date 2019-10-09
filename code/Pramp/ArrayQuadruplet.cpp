/*

*********************
* problem statement *
*********************

Given an unsorted array of integers arr and a number s, write a function findArrayQuadruplet that finds four numbers (quadruplet) in arr that sum up to s. Your function should return an array of these numbers in an ascending order. If such a quadruplet doesn’t exist, return an empty array.

Note that there may be more than one quadruplet in arr whose sum is s. You’re asked to return the first one you encounter (considering the results are sorted).

Explain and code the most efficient solution possible, and analyze its time and space complexities.

***********
* Example *
***********

input:  arr = [2, 7, 4, 0, 9, 5, 1, 3], s = 20
output: [0, 4, 7, 9]

# The ordered quadruplet of (7, 4, 0, 9)
# whose sum is 20. Notice that there
# are two other quadruplets whose sum is 20:
# (7, 9, 1, 3) and (2, 4, 9, 5), but again you’re
# asked to return the just one quadruplet (in an
# ascending order)

***************
* Constraints *
***************

1. [time limit] 5000ms
2. [input] array.integer arr
 where 1 ≤ arr.length ≤ 100
3. [input] integer s
4. [output] array.integer

**************************
* Comments after Solving *
**************************

The meaning of "ascending order" was not clear.
One way of saying it is if there are multiple answers
return the answer which would come first if all answers
were rewritten in ascending order based on element values.

Additionally, the given answer claimed O(1) space, but since the
API had "const" in front of the given array and the algo sorted it,
it didn't seem to be fair to call it O(1) space. 
(I copied the vector and sorted it.)
The idea that sorting O(nlog(n)) was less than O(n*n*n) so might as
well do it was interesting and unique to this problem.
Typically sorting (nlog(n)) is avoided if possible since it is
failry costly (more than linear time).

I did not worry about using unordered_map or unordered_set vs map or set
since n*n*n would be the bottleneck compared to n*logn insert for (sorted)
maps or sets.

*/


#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> findArrayQuadruplet(const vector<int> &arr, int s) 
{
  vector<int> ans;
  if(arr.size()<=3)
    return ans;
  map<int,set<int>> m;
  //build a map
  
  vector<int> v;
  for(int i=0;i<arr.size();i++)
    v.push_back(arr[i]);
  sort(v.begin(),v.end());
  
  for(int i=0;i<v.size();i++){
    auto it=m.find(v[i]);
    if(it==m.end()){
      set<int> s;
      s.insert(i);
      m[v[i]]=s;
    }
    else{
      it->second.insert(i);
    }
  }
  
  for(int i=0;i<v.size()-3;i++){
    for(int j=i+1;j<v.size()-2;j++){
      for(int k=j+1;k<v.size()-1;k++){
        auto it=m.find(s-v[i]-v[j]-v[k]);
        if(it!=m.end()){
          auto it2=it->second.begin();
          while(it2!=it->second.end()&&*it2<=k){
            it2++;
          }
          if(it2!=it->second.end())
            if(*it2>k){
              ans.push_back(v[i]);
              ans.push_back(v[j]);
              ans.push_back(v[k]);
              ans.push_back(v[*it2]);
              return ans;
            }
        }
        
      }
    }
  }
  return ans;
}

int main() {
  return 0;
}
