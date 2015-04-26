#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <string>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define REP(i,p,n) for(int i=p;i<n;++i)
#define rep(i,n) REP(i,0,n)

typedef long long int ll;
typedef complex<double> point;
typedef pair<int,int> pii;
typedef vector<int> vint;
typedef vector<pii> vpii;
typedef pair<int,int> pii;
typedef vector<vint> det1;
typedef vector<vpii> det2;

class BichromeBoard
{
public:
    string ableToDraw(vector <string> board);
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"W?W",
 "??B",
 "???"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(0, Arg1, ableToDraw(Arg0)); }
	void test_case_1() { string Arr0[] = {"W??W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Impossible"; verify_case(1, Arg1, ableToDraw(Arg0)); }
	void test_case_2() { string Arr0[] = {"??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(2, Arg1, ableToDraw(Arg0)); }
	void test_case_3() { string Arr0[] = {"W???",
 "??B?",
 "W???",
 "???W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(3, Arg1, ableToDraw(Arg0)); }
	void test_case_4() { string Arr0[] = {"W???",
 "??B?",
 "W???",
 "?B?W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Impossible"; verify_case(4, Arg1, ableToDraw(Arg0)); }
	void test_case_5() { string Arr0[] = {"B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(5, Arg1, ableToDraw(Arg0)); }

// END CUT HERE

};

string BichromeBoard::ableToDraw(vector <string> board)
{
	char c[2] = {0};

	rep(y,board.size()) rep(x,board[0].size())
	{
		if(board[y][x]=='?'){ continue; }

		int k = (x+y)%2;

		bool ok = (c[k] == 0       || c[k]       == board[y][x])
			   && (c[(k+1)%2] == 0 || c[(k+1)%2] != board[y][x]);

		if(!ok){ return "Impossible"; }

		c[k] = board[y][x];
	}

	return "Possible";
}

// BEGIN CUT HERE
int main() {
BichromeBoard ___test;
___test.run_test(-1);
}
// END CUT HERE 
