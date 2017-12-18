#include <iostream>
#include <vector>

using namespace std;

void print_data(vector<vector<int> >& data, int N, int M) {
  cout << "Array is: " << endl;
  for(int i=0; i<N; i++) {
    for (int j=0; j<M; j++) cout << data[i][j] << " ";
    cout << endl;
  }
}

bool find_elem(vector<vector<int> >& data, int st_row, int end_row, int st_col, int end_col, int K) {
  if (end_row<st_row || end_col<st_col || st_row<0 || st_col<0) return false;
  
  if(st_row == end_row && st_col == end_col) return (data[st_row][st_col] == K);
  
  int mid_row = st_row + (end_row-st_row)/2;
  int mid_col = st_col + (end_col-st_col)/2;
  
  if(data[mid_row][mid_col] == K) return true;

  else if (data[mid_row][mid_col] < K) {
    //bottom half || right half
    return (find_elem(data, st_row, end_row, mid_col+1, end_col, K) ||
           find_elem(data, mid_row+1, end_row, st_col, mid_col, K) );
  }
  else {
    //top half or left half
    return (find_elem(data, st_row, end_row, st_col, mid_col-1, K) ||
        find_elem(data, st_row, mid_row-1, mid_col, end_col, K));
  }
}
int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int> > data (N, vector<int> (M));
  
  int K; // elem to look for
  cin >> K;
  
  for(int i=0; i<N; i++) 
    for (int j=0; j<M; j++) { int tmp; cin >> tmp; data[i][j] = tmp; }
  
  print_data(data, N, M);
  cout << "Is elem found ? " << boolalpha << find_elem(data, 0, N-1, 0, M-1, K) << endl;
      
  
  return 0;
}
