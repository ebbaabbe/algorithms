#include <bits/stdc++.h>
using namespace std;

/* Notes: Problem Desc/Formulation
 * Clone a linked list with next and random pointer 
 * You are given a Double Link List with one pointer of each node pointing to the next node 
 * just like in a single link list. The second pointer however CAN point to any node in 
 * the list and not just the previous node. Now write a program in O(n) time to duplicate this 
 * list. That is, write a program which will create a copy of this list.
 *
 * Let us call the second pointer as arbit pointer as it can point to any arbitrary node in the linked list.
 *
 * ArbitLinked List1
 * 1 -> 2 -> 3 -> 4 -> 5
 * 5 arbit -> 2
 * 4 arbit -> 3
 * 3 arbit -> 5
 * 2 arbit -> 1
 * 1 arbit -> 3
 * Solution with extra space
 */
struct node {
  int val;
  node* next;
  node* arbit;
  node(int v) { val = v; next = NULL; arbit = NULL; }
};

int main() {
  map<int, node*> clonelist;
  vector<int> arr {1,2,3,4,5};
  node* head = new node(arr[0]);
  clonelist.insert(pair<int, node*> (arr[0], head));
  node* tmp = head;
  for(int i=1; i<arr.size(); i++) {
    tmp->next = new node(arr[i]);
    clonelist.insert(pair<int, node*> (arr[i], tmp->next));
    tmp = tmp->next;
  }
  clonelist[5]->arbit = clonelist[2];
  clonelist[4]->arbit = clonelist[3];
  clonelist[3]->arbit = clonelist[5];
  clonelist[2]->arbit = clonelist[1];
  clonelist[1]->arbit = clonelist[3];

  tmp = head;
  while(tmp!=NULL) {
    cout << tmp->val << " ";
    if(tmp->next) cout << " next: " << tmp->next->val ;
    if(tmp->arbit) cout << " arbit: " << tmp->arbit->val ;
    cout << endl;
    tmp = tmp->next;
  }

  //reuse map for cloning
  tmp = head;
  while(tmp!=NULL) {
    node* c = new node(tmp->val);
    clonelist.insert(pair<int, node*> (tmp->val, c));
    tmp = tmp->next;
  }

  tmp = head;
  while(tmp!=NULL) {
    node* cl = clonelist[tmp->val];
    if(tmp->arbit) cl->arbit = clonelist[tmp->arbit->val];
    if(tmp->next)  cl->next = clonelist[tmp->next->val];
    tmp = tmp->next;
  }

  tmp = clonelist[head->val];
  cout << endl << "Cloned list : " << endl;
  while(tmp!=NULL) {
    cout << tmp->val << " ";
    if(tmp->next) cout << " next: " << tmp->next->val ;
    if(tmp->arbit) cout << " arbit: " << tmp->arbit->val ;
    cout << endl;
    tmp = tmp->next;
  }
  return 0;
}

