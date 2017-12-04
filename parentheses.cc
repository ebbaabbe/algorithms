#include <bits/stdc++.h>
using namespace std;

/* Notes: Problem Desc/Formulation: Given N print all fully formed paranthesis
 * add a open and recurse -- print if soln is a match
 * add a close as long as str stays valid
 */
void brackets(string s, int open, int close, int N) {
  if (open == N && close == N)  
    cout << s << endl;
  else {
    if (open < N)
      brackets(s+"(", open+1, close, N);
    if (close<open)
      brackets(s+")", open, close+1, N);
  }
  return;
}
int main() {
  for(int N=1; N<=4; N++) {
    cout << "For N="<<N <<endl;
    brackets("",0,0,N);
  }
  return 0;
}

