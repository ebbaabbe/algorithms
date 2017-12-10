#include <bits/stdc++.h>
using namespace std;

/* Notes: Problem Desc/Formulation
 * Come up with an efficient implimentation of an LRU cache
 */

struct node {
  int val;
  int key;
  node(int k, int v) {key=k; val=v;}
};

class LRUCache {
  private:
    list<node> freq_list;
    unordered_map<int, list<node>::iterator> cache;
    int max_size;

    void evict(int k) {
      freq_list.erase(cache[k]);
      cache.erase(k);
    };

  public:
    LRUCache(int M) { max_size=M; }

    void insert(int k, int v) {
      if(freq_list.size()>=max_size) evict(freq_list.back().key); //make space by eviction

      freq_list.push_front(node(k,v));
      list<node>::iterator it = freq_list.begin();
      cache.insert(pair<int, list<node>::iterator>(k,it));
    }

    int lookup(int k) {
      list<node>::iterator it = cache[k];
      return it->val;
    }

    void update(int k, int v) {
      freq_list.erase(cache[k]); //remove old entry from freq_list

      freq_list.push_front(node(k,v));
      list<node>::iterator newit = freq_list.begin();
      cache[k] = newit;
    }

    void deleteitem(int k) {
      evict(k);
    }

    void dump_cache() {
      cout << "Cache has :";
      list<node>::iterator it = freq_list.begin();
      for(;it!=freq_list.end(); it++) cout << it->key << "-" << it->val << " ";
      cout << endl;
    }
};

int main() {
  int N; // testbed #items
  int W=3; //cache size

  cin >> N;
  vector<int> elems(N);
  for(int i=0; i<N; i++) {
    cin >> elems[i];
  }

  LRUCache cc(W);
  for(int i=0; i<N; i++) {
    cc.insert(i,elems[i]);
  }

  cc.dump_cache();
  cout << "Update key 3 with 10" << endl;
  cc.update(3,10);
  cc.dump_cache();
  cout << "delete key 4 " << endl;
  cc.deleteitem(4);
  cc.dump_cache();

  return 0;
}

