#include <iostream>
#include <vector>

using namespace std;

void qsort(vector<int>& ar, int start, int end) {

  if(start>=end) return; 
  if(start < 0 || end >=ar.size()) return;

  int pivot = ar[end];
  int _end = end-1;
  int _st = start;

  while(_st <= _end) {
    while(_end>=start && ar[_end] > pivot) _end--;
    while(_st<end && ar[_st] < pivot) _st++; 

    if (_st > _end) break;
    if (_st == _end) continue;
    
    //exchange st and end
    int tmp = ar[_end]; ar[_end] = ar[_st]; ar[_st] = tmp;
  }

  //move pivot into position
  ar[end] = ar[_st]; ar[_st] = pivot;

  qsort(ar, start, _st-1);
  qsort(ar, _st+1, end);

  return;

}

int main(void) {
   int _ar_size;
   cin >> _ar_size;
   vector <int>  _ar(_ar_size);
    
   for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
     cin >> _ar[_ar_i]; 
   }

   qsort(_ar, 0, _ar_size-1);
   for (auto &i : _ar) cout << i << " "; cout << endl;
   return 0;
}

