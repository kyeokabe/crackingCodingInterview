**1. define a stack and queue**

```
#include <stack>
#include <queue>
using namespace std;

stack<int> foo1;
queue<int> foo2;

foo1.push(2); // pushes "2" into stack
foo1.top();
foo1.pop();
foo2.size();

foo2.push(4);
foo2.front();
foo2.pop();
foo2.size();
```

**2. convert char into an integer based on ascii code**

```
char foo;
foo='a';

cout<<(int)foo<<endl; //outputs 97
```


**3. get the length of a string**

```
string foo;
foo="123456";

cout<<foo.length()<<endl; //outputs 6
```
