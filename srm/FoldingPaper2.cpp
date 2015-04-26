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

class FoldingPaper2
{
public:
    int solve(int W, int H, int A);
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 12; int Arg3 = 1; verify_case(0, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 3; int Arg3 = -1; verify_case(1, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 1; int Arg3 = 4; verify_case(2, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 127; int Arg1 = 129; int Arg2 = 72; int Arg3 = 8; verify_case(3, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 100000; int Arg2 = 100000; int Arg3 = 0; verify_case(4, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 2; int Arg3 = -1; verify_case(5, Arg3, solve(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

const int MAXN=100000;
int dp1[MAXN] = {0};

int FoldingPaper2::solve(int W, int H, int A)
{
	rep(i,MAXN) dp1[i]=0;


	for(int i=1;i*i<=A;++i) if((A%i)==0)
	{
		const int a = i;
		const int b = A/i;


		
	}
}

// BEGIN CUT HERE
int main() {
FoldingPaper2 ___test;
___test.run_test(-1);
}
// END CUT HERE 
