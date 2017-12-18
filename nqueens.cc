#include <bits/stdc++.h>
using namespace std;

bool checkboard(const vector<int>& grid, int st, int end) {
  // check if 2Q's are in the same row
  for (int i=st; i<end; i++) 
    if (grid[i] == grid[end]) 
      return false;

  // check if 2Q's are on the same diagonal
  for (int i=st; i<end; i++) 
    if ((end - i) == (grid[end] - grid[i])) 
      return false;

  return true;
}

bool placeQ(std::vector<int>& grid, int col) {
  if (col == grid.size()) return true;

  for (int i=0; i<grid.size(); i++) {
    grid[col] = i;
    if(checkboard(grid, 0, col) && placeQ(grid, col+1))
      return true;
  }
  return false;
}

void printGrid(vector<int>& grid) {
  for (int i=0; i<grid.size(); i++) {
    for (int j=0; j<grid.size(); j++)
      if(grid[j] == i) cout << "X ";
      else cout << "- ";
    cout << endl;
  }

  return;
}

int main () {
  int N = 16;
  vector<int> grid (N, -1);
  if(placeQ(grid, 0))
    printGrid(grid);
  else
    cout << "No soln exists" << endl;

  return 0;
}
