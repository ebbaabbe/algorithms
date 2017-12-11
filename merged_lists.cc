#include <bits/stdc++.h>
using namespace std;

/* Notes: Problem Desc/Formulation
 * Given two singly linked lists L1 and L2 containing non-negative integers. 
 * You have to find the intersection of given linked lists if any.
 * Intersection of two linked lists is the first common node (first node with the same address).
 *
 * Input: There are two arguments L1 and L2 denoting pointers to head of the linked lists.
 * Output: If given linked lists intersects then return the value in the first 
 * node where intersection begins, else return -1.
 *
 * Constraints: 
 * 1. 0 <= value stored in nodes <= 10^9
 * 2. You are not allowed to modify the given linked lists.
 * 3. Let N1 denote number of nodes in L1 and N2 denote number of nodes in L2. Then 0 <= N1, N2 <= 10^5.
 *
 * Expected solution: Linear time complexity, with constant extra space.
 *
 */

struct node {
  int val;
  node* next;
  node(int v) { val = v; next = NULL; }
};

node* get_node_at(node* n, int cnt) {
  while(n && --cnt) n = n->next;
  return n;
}

pair<int,node*> get_length(node* n) {
  int cnt = 1;
  while (n->next && cnt++) n = n->next;
  return pair<int,node*>(cnt+1, n);
}

int get_intersection(node* l1, node* l2) {
  pair<int,node*> p1 = get_length(l1);
  pair<int,node*> p2 = get_length(l2);
  int len1 = p1.first;
  int len2 = p2.first;

  node* e1 = p1.second;
  node* e2 = p2.second;
  if(e1 != e2) return -1;

  int diff; node* h1, *h2;
  if(len1 < len2) { h1 = l2; h2 = l1; diff = len2-len1; }
  else  { h1=l1; h2=l2; diff=len1-len2; }

  while(diff--) h1=h1->next;

  while(h1!=h2) { h1=h1->next; h2=h2->next; }

  return h1->val;
}

int main() {
  vector<int> arr1 {1,2,3,4,5,6,7,8};
  vector<int> arr2 {100,120};
  int k = 5; // join arr2 to kth node of arr1
  node* l1, *l2;

  if(arr1.size()) l1 = new node(arr1[0]);
  node* tmp = l1; for(int i=1; i<arr1.size(); i++) { tmp->next = new node(arr1[i]); tmp = tmp->next; }

  if(arr2.size()) l2 = new node(arr2[0]);
  tmp = l2; for(int i=1; i<arr2.size(); i++) { tmp->next = new node(arr2[i]); tmp = tmp->next; }
  
  //test
  cout << "Node at " << k << " is " << get_node_at(l1,k)->val << endl;
  tmp->next = get_node_at(l1, k);
  cout << "L1 len " << get_length(l1).first << endl;
  cout << "L2 len " << get_length(l2).first << endl;

  cout << "Intersect at " << get_intersection(l1,l2) << endl;

  return 0;
}

