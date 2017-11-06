#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void twosum (vector<int>& arr, int st, int end) {
  int b = st;
  int e = end-1;
  int k = arr[end];

  while (b<e) {
    int sum = arr[b] + arr[e] + k;
    if (sum > 0) e--;
    else if (sum < 0) b++;
    else {
      cout << arr[b] << " " << arr[e] << " " << k << endl; 
      return ;
    }
  }

  return ;
}
void threesum(vector<int>& arr) {
  sort(arr.begin(), arr.end());
  cout << "Input array is : "; 
  for(auto &i : arr) cout << i << " "; cout << endl;

  for (int i=arr.size()-1; i>0; i--) {
    int sum = arr[0]+arr[i-1];
    if (sum > arr[i]) continue;
    else if (sum == arr[i]) { cout << arr[0] << " " << arr[i-1] << " " << arr[i] << endl; return; }
    else twosum(arr, 0, i);
  }
  return;
}

int main (void) {
  vector<int> in;

  in = {3,4,5,-1,-2};

  threesum(in);
  return 0;
}
