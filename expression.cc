#include <bits/stdc++.h>
using namespace std;

class seq_matcher {
public:
	int N;
	int K;
	int op_cnt;

	std::vector<char> operators {'j', 'm', 'a', 'S', 'd', 's'};
	std::vector<int> val;

	int update_expr_val(int v1, int v2, int op_idx) {
		switch(operators[op_idx]) {
			case 'j': return (v1*10+v2);
			case 'm': return v1 * v2;
			case 'a': return v1 + v2;
			case 'S': return v1/10;
      case 'd': return (v2 == 0)  ? 0  : v1/v2;
			case 's': return v1 - v2;
		}

		assert(0);
		return -1;
	}
	void print_sequence (int idx, string& seq_so_far, int expr_val ) {
		if ( idx == N) {
      int val = determine_expr_value(seq_so_far);
			if ( K == val) cout << "Possible Seq: " << seq_so_far << endl;
      return;
		}
    // Operators are join/mul/plus - remaining three are to reverse the operation
		for (int i=0; i<op_cnt; i++) {
			expr_val = update_expr_val(expr_val, val[idx], i);
			seq_so_far += (operators[i] + to_string(val[idx]));
			print_sequence(idx+1, seq_so_far, expr_val);
			seq_so_far.erase(seq_so_far.size()-2, seq_so_far.size()-1);  //assuming size of operand and digit to be one each
			expr_val = update_expr_val(expr_val, val[idx], i+op_cnt);
		}

    return;
	}

  int determine_expr_value(string expr) {
    int idx = 0;
    vector<pair<char,string>> ops;
    while(idx<expr.size()) {
      ops.push_back(pair<char,string>('n', string(1, expr[idx++]))); // digit
      if(idx>=expr.size()) break;
      ops.push_back(pair<char,string>(expr[idx++], "0")); //op
    }

    //resolve all joins -- precedence
    vector<pair<char,string> >::iterator it = find(ops.begin(), ops.end(), pair<char,string>('j', "0"));
    while(it != ops.end()) {
      ops[it-ops.begin()-1].second = ops[it - ops.begin() -1].second + ops[it - ops.begin() +1].second;
      ops.erase(it, it+2);
      it = find(ops.begin(), ops.end(), pair<char,string>('j', "0"));
    }

    //resolve all mul 
    it = find(ops.begin(), ops.end(), pair<char,string>('m', "0"));
    while(it != ops.end()) {
      int num1 = atoi(ops[it - ops.begin() -1].second.c_str());
      int num2 = atoi(ops[it - ops.begin() +1].second.c_str());
      ops[it-ops.begin()-1].second = to_string(num1*num2);
      ops.erase(it, it+2);
      it = find(ops.begin(), ops.end(), pair<char,string>('m', "0"));
    }

    //resolve all add 
    it = find(ops.begin(), ops.end(), pair<char,string>('a', "0"));
    while(it != ops.end()) {
      int num1 = atoi(ops[it - ops.begin() -1].second.c_str());
      int num2 = atoi(ops[it - ops.begin() +1].second.c_str());
      ops[it-ops.begin()-1].second  = to_string(num1+num2);
      ops.erase(it, it+2);
      it = find(ops.begin(), ops.end(), pair<char,string>('a', "0"));
    }

    assert(ops.size() == 1);
    return atoi(ops[0].second.c_str());
  }

};

int main (void) {

  seq_matcher seq;
  cin >> seq.N >> seq.K;

  seq.val.resize(seq.N);
  for(int i=0; i<seq.N; i++) cin >> seq.val[i];

  seq.op_cnt = 3;
  string seq_so_far;
  int seq_expr_val = seq.val[0];
  seq_so_far = to_string(seq.val[0]);
  seq.print_sequence(1, seq_so_far, seq_expr_val);

}
