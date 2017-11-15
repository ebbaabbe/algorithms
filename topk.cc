#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class min_heap {
  private:
    set<int> _arr;
    int _k;

  public:
    min_heap(int k) {
      _k = k;
    }

    void push(int v) {
      //initial phase
      if (_arr.size() < _k) _arr.insert(v);

      if (v<*_arr.begin()) return;

      _arr.insert(v);

      // if element was not in set
      if(_arr.size()>_k) _arr.erase(_arr.begin());

      return;
    }

    void print_max_k() {
      for (auto &i : _arr) cout << i << " ";
      cout << endl;
      return;
    }
};

int main() {
  vector<int> test_ip;

  test_ip = {1,2,3,4,5,6,7,8,9};
  min_heap m(3);
  for (auto &i: test_ip) {
    cout << "Insert new elem: " << i << endl;
    m.push(i);
    m.print_max_k();
  }
}
