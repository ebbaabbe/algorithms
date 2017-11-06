#include <cstdio>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

int main (void) {
  string ip_str;
  cin >> ip_str;

  cout << "Input: " << ip_str << endl;

  int str_st_idx = 0;
  bool isplus = true;
  int sign_idx = 0;
  int str_end_idx = 0;

  while (str_st_idx < ip_str.size()) {
    char c = ip_str[str_st_idx];

    if (c == '+') { isplus = true; sign_idx=str_st_idx; }
    if (c == '-') { isplus = false; sign_idx=str_st_idx; }
    if (isdigit(c)) break;
    str_st_idx++;
  }

  str_end_idx = str_st_idx;
  while (str_end_idx<ip_str.size()) {
    char c = ip_str[str_end_idx];
    if (!isdigit(c)) break;
    str_end_idx++;
  }

  // either the end or pointing to a non-digit
  str_end_idx--;

  // Only use sign if its next to the start
  if(sign_idx+1 != str_st_idx) isplus = true;

  int ans = 0, didx = 0;
  for(int i=str_end_idx; i>=str_st_idx; i--) {
    int di = ip_str[i]-'0';
    ans += (di * pow(10, didx++));
  }

  if(!isplus) ans = ans * -1;

  cout << "Output: " << ans;

  return 0;
}
