#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool compare_lt(string a, string b) {
  int t1 = atoi(a.substr(1, a.size()-1).c_str());
  int t2 = atoi(b.substr(1, b.size()-1).c_str());
  
  return t1<t2;
}

bool compare_gt(string a, string b) {
  int t1 = atoi(a.substr(1, a.size()-1).c_str());
  int t2 = atoi(b.substr(1, b.size()-1).c_str());
  
  return t1>t2;
}

bool compare_eq(string a, string b) {
  int t1 = atoi(a.substr(1, a.size()-1).c_str());
  int t2 = atoi(b.substr(1, b.size()-1).c_str());
  
  return t1==t2;
}

int partition (vector<string>& arr, int s, int e, string pivot) {
  if (s>=e) return -1;
  
  int low = s;
  int high = e;
  int mid = s;
  
  while (mid<=high) {
    if (compare_lt(arr[mid], pivot)){
      string tmp = arr[mid];
      arr[mid] = arr[low];
      arr[low] = tmp;
      low++; mid++; 
    }
    if (mid<=high && compare_gt(arr[mid], pivot)){
      string tmp = arr[high];
      arr[high] = arr[mid];
      arr[mid] = tmp;
      high--;
    }
    if (mid<=high && compare_eq(arr[mid], pivot)) mid++;
    
  }
  
  return mid-1; 
}

void match_nut_bolt(vector<string>& nuts, vector<string>& bolts, int s, int e) {

  if(s>=e) return;
  int idx = partition(bolts, s, e, nuts[e]);
  idx = partition(nuts, s, e, bolts[idx]);
  
  match_nut_bolt(nuts, bolts, s, idx-1);
  match_nut_bolt(nuts, bolts, idx+1, e);
}

int main() {
  // Ex test case
  cout << "Test case 1" << endl;
  vector<string> nuts1 = {"N3","N2","N1","N4"};
  vector<string> bolts1 = {"B4","B2","B3","B1"};
  match_nut_bolt(nuts1, bolts1, 0, bolts1.size()-1);
  
  /* Ex 2
  cout << "Test case 2" << endl;
  nuts = {"N1","N2","N3","N4"};
  bolts = {"B1","B2","B3","B4"};
  match_nut_bolt(nuts, bolts);
  
  // Ex 3
  cout << "Test case 3" << endl;
  vector<string> nuts3 = {"N10","N7","N12","N4","N5","N2","N3","N14",};
  vector<string> bolts3 = {"B14","B10","B12","B7","B4","B5","B2","B3"};
  match_nut_bolt(nuts, bolts3, 0, bolts3.size()-1);
  for (int i=0; i<nuts3.size(); i++) cout << nuts3[i] << bolts3[i] << endl;
  
  
  // Ex 4
  cout << "Test case 4" << endl;
  vector<string> nuts4 = {"N103","N37","N12","N40","N125","N23","N3","N14"};
  vector<string> bolts4 = {"B14","B103","B12","B37","B40","B125","B23","B3"};
  match_nut_bolt(nuts4, bolts4, 0, bolts4.size()-1);
  for (int i=0; i<nuts4.size(); i++) cout << nuts4[i] << bolts4[i] << endl;
  */
  return 0;
}
