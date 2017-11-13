#include<iostream>
#include<vector>

using namespace std;

class node
{
public:
	int val;
	node* next;
	static int cnt;

	node() {
		val = cnt++;
		next = NULL;
	}
};
int node::cnt = 0;

void print_list(node* n, int cnt) {
	cout << "List is: ";
	while(cnt--) {
		cout << n->val << " ";
		n = n->next;
	}
	cout << endl;
}

class cycle_detection
{
public:
	node* loop_start;   // start of the cycle
	node* meet;			// half way point in loop
	int loop_node_cnt;  // if loop exists len of the cycle

	cycle_detection(node* h) {
		node* start = h;
		meet = NULL;
		loop_start = NULL;
		loop_node_cnt = 0;

		node* slow_p = h;
		node* fast_p = h;

		while(1) {
			if (slow_p) slow_p = slow_p->next;
			if (fast_p && fast_p->next) fast_p = fast_p->next->next;

			if(slow_p == fast_p) { meet = slow_p; break; }
			
			if (slow_p == NULL || fast_p == NULL || (fast_p && fast_p->next == NULL)) break; //reached end - no loop
			
		}
		
		if(meet) {
			node* n1 = h;
			node* n2 = meet;
			while(n1 != n2) {
				n1 = n1->next;
				n2 = n2->next;
			}
			loop_start = n1;	
		}

		if(loop_start) {
			loop_node_cnt = 1;
			node* tmp = loop_start->next;
			while(tmp != loop_start) {
				loop_node_cnt++; tmp = tmp->next;
			}
		}

		if(meet && loop_start) {
			cout << "Fast/Slow ptrs meet at " << meet->val 
					<< " Loop node cnt: " << loop_node_cnt 
					<< " loop_start: " << loop_start->val << endl;
		}
	}

	~cycle_detection() {}

	bool has_cycle () {
		return meet != NULL;
	}

	void print_cycle () {
		node* n = loop_start;
		int cnt = loop_node_cnt;
		while(cnt--){
			cout << n->val << " ";
			n = n->next;
		}
		cout << endl;
	}
	
};


int main () {
	
	cout << "Insert List Len (N) : "; int N;
	cin >> N;

	vector<node> list(N);

	cout << "Connect ptr at (val; > N for no loop): "; int n1;
	cin >> n1;

	for(int i=0; i<N-1;i++) {
		list[i].next = &list[i+1];
	}
	if(n1 < N)
		list[N-1].next = &list[n1];

	print_list(&list[0],N);

	cycle_detection* cd = new cycle_detection(&list[0]);
	cout << "Has cycle: " << boolalpha << cd->has_cycle() << endl;
	cd->print_cycle();

	return 0;

}