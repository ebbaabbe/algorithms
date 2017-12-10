#include <bits/stdc++.h>
using namespace std;

/* Notes: Problem Desc/Formulation
 * Swap the kth item in a linked list
 * kth item from the front with the kth item
 * from the back
 * Eg: Arr of len 8 and k = 2
 * 1 2 3 4 5 6 7 8 -> 1 7 3 4 5 6 2 8
 */

class LinkedListNode {
  public:
    int val;
    LinkedListNode *next;

    LinkedListNode(int node_value) {
      val = node_value;
      next = NULL;
    }
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, LinkedListNode *tail, int val) {
  if(head == NULL) {
    head = new LinkedListNode(val);
    tail = head;
  }
  else {
    LinkedListNode *node = new LinkedListNode(val);
    tail->next = node;
    tail = tail->next;
  }
  return tail;
}

typedef LinkedListNode node;
LinkedListNode* swapNodes(LinkedListNode* pList, int iK) {
  if(pList == NULL) return pList;

  node* prev_n1 = NULL;
  node* next_n1 = NULL;
  node* n1 = pList;

  while(--iK > 0) {
    prev_n1 = n1;
    n1 = n1->next;
  }
  next_n1 = n1->next;
  if(prev_n1)
    cout << "For n1 prev"<<prev_n1->val << " n1 " << n1->val << " next" << next_n1->val << endl;
  else
    cout << "For n1 prev is null; n1 " << n1->val << " next" << next_n1->val << endl;

  // find n-k elem
  node* prev_n2 = NULL;
  node* next_n2 = NULL;
  node* n2 = pList;
  node* tmp = n1;

  while(tmp->next != NULL) {
    prev_n2 = n2;
    n2 = n2->next;
    tmp = tmp->next;
  }
  next_n2 = n2->next;
  if(next_n2)
  cout << "For n2 prev"<<prev_n2->val << " n2 " << n2->val << " next" << next_n2->val << endl;
  else
  cout << "For n2 prev"<<prev_n2->val << " n2 " << n2->val << " next is null" << endl;

  if(n1 == n2) return pList; //if item is middle item of a odd list

  //swap the nodes n1 with n2
  if(prev_n1)
    prev_n1->next = n2;
  else //start of list
    pList = n2;

  n2->next = next_n1;
  prev_n2->next = n1;
  n1->next = next_n2;

  return pList;
}

int main()
{
  LinkedListNode* res;
  int pList_size = 4;
  int iK = 2;
  //vector<int> arr {0,1,2,3,4,5,6,7,8,9};
  //cout << "array is 0 1 2 3 4 5 6 7 8 9 swap 2n item" << endl;
  vector<int> arr {11,4,2};
  cout << "array is 11 4 2 swap "<< iK << " item" << endl;

  LinkedListNode* pList = NULL;
  LinkedListNode* pList_tail = NULL;

  for(int i = 0; i < pList_size; i++) {
    pList_tail = _insert_node_into_singlylinkedlist(pList, pList_tail, arr[i]);
    if(i == 0) pList = pList_tail;
  }


  res = swapNodes(pList, iK);
  while (res != NULL) {
    cout << res->val << endl;
    res = res->next;
  }

  return 0;
}

