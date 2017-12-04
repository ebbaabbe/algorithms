#include <bits/stdc++.h>

#define CONT set
using namespace std;

/* Attempt at a recursive formulation:
 * get a subset of solns with N-1
 * possible solutions are ()..
 * or ..()
 * or (..)
 * where .. is every item in the set
 * of possible subsets for N-1
 * Note: This approach generates duplicates
 * and hence the set to filter them out. It does not seem to generate all possible
 * solutions. In the case of N=4 only 13 possible permuations are printed.
 * Missing (())(())
 */
CONT <string> brackets(int N) {
  CONT<string> ans;
  if(N==1) {
    ans.insert("01");
    return ans;
  }

  CONT<string> a = brackets(N-1);
  CONT<string>::iterator it = a.begin();

  for(;it!=a.end(); it++) {
    ans.insert("0" + *it+"1");
    ans.insert("01" + *it);
    ans.insert(*it + "01");
  }

  return ans;
}

int main() {
  int N;
  cin >> N;
  CONT<string> ans = brackets(N);
  CONT<string>::iterator it = ans.begin();

  cout << "For N=" << N << " #set="<<ans.size() <<endl;
  for(; it != ans.end(); it++) {
    string p = *it;
    for(int j=0; j<p.size(); j++) {
      if(p[j]=='0') p[j] = '(';
      else p[j] = ')';
    }
    cout << p << endl;
  }

  return 0;
}
