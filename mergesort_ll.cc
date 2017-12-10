#include <bits/stdc++.h>
using namespace std;

/* Notes: Problem Desc/Formulation
 * Sort a singly linked list using merge sort. Sort ascending.
 * (Trivia question: Merge Sort, in general is a good method of sorting anything, because its worst case
 * performance is better than most other sorting methods. For Linked Lists however, Merge Sort is highly
 * preferred, because it has a distinct advantage. What is that advantage?)
 *
 * I think you can get away without the auxillary space o(1) extra space
 */

struct node {
  int val;
  node* next;
  node(int v) { val = v; next = NULL; }
};

int getLen(node* n) {
  int cnt = 0;
  while(n!=NULL && ++cnt)  n = n->next; 
  return cnt;
}

// expects cnt to be less than linked list len
node* getNodeAt(node* n, int cnt) {
  while(cnt-- && n) n=n->next;
  return n;
}

void printList(node* tmp) {
  while(tmp!=NULL) {
    cout << tmp->val << " ";
    tmp = tmp->next;
  }
  cout << endl;
  return;
}

// Merge two sorted lists
// Return head of sorted list
node* merge(node* l1, node* l2) {
  node* head = NULL;
  if(l1->val <= l2->val) { head = l1; l1=l1->next; }
  else { head = l2; l2=l2->next; }
  node* curr = head;

  while(l1!=NULL && l2!=NULL) {
    if(l1->val <= l2->val && curr) { curr->next = l1; l1 = l1->next; }
    else { curr->next = l2; l2 = l2->next; }
    curr = curr->next;
  }

  // merge remainder segments
  while(l1!=NULL && curr) { curr->next = l1; l1=l1->next; curr = curr->next; }
  while(l2!=NULL && curr) { curr->next = l2; l2=l2->next; curr = curr->next; }

  return head;
}
// Divide and Conquer
// return head of sorted list
node* msort(node* h) {
  int end = getLen(h)-1;
  if(end == 0) return h;

  int st = 0; // broken up lists; always start at 0
  int mid = st + (end-st)/2;
  node* h1 = h;
  node* h2 = getNodeAt(h, mid);
  node* h3 = getNodeAt(h, end);

  node* tmp = h2->next; h2->next = NULL; h2 = tmp;  // break up lists 
  h3->next = NULL;

  node* p1 = msort(h1);
  node* p2 = msort(h2);
  node* n = merge(p1, p2);

  return n;
}

int main() {
  vector<int> arr {5,4,3,2,5};
  node* head = new node(arr[0]);
  node* tmp = head;
  for(int i=1; i<arr.size(); i++) {
    tmp->next = new node(arr[i]);
    tmp = tmp->next;
  }

  cout << "List is "; printList(head);

  node* sorted = msort(head);
  cout << "Sorted list is "; printList(sorted);


  return 0;
}

