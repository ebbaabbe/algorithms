#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

int merge (vector<int>& arr, vector<int>& aux, int low, int mid, int end) {
  if (low >= end) return 0;
  
  int inv_cnt = 0;
  int i = low;
  int j = mid+1;
  
  for(int k = low; k<=end; k++) {
    if (i>mid) aux[k] = arr[j++];
    else if (j>end) aux[k] = arr[i++];
    else if (arr[i] < arr[j]) aux[k] = arr[i++];
    else aux[k] = arr[j++];
  }
  
  //copy array
  for (int i=low; i<=end; i++) arr[i] = aux[i];
  
  return inv_cnt;
}

int msort(vector<int>& arr, vector<int>& aux, int s, int e) {
  if (s >= e) return 0;
  int inv_cnt = 0;
  
  int mid = s + (e-s)/2;
  cout << "sort from : "<< s << " to " << e << " mid is " << mid <<endl;
  msort(arr, aux, s, mid);
  msort(arr, aux, mid+1, e);
  inv_cnt += merge(arr, aux, s, mid, e);
 
  return inv_cnt;
}

int main() {
  int N; cin >> N;
  vector<int> ar(N);
  for (int i=0; i<N; i++) {
    cin >> ar[i];
  }

  vector<int> aux(N);
  int cnt = msort(ar, aux, 0, N-1);
  cout << cnt << endl;

  return 0;
}

