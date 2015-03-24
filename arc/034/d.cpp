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
typedef pair<int,int> pii;
typedef vector<int> vint;
typedef vector<pii> vpii;
typedef vector<vint> det1;
typedef vector<vpii> det2;

int main()
{
	int an,bn,cn;
	cin>>an>>bn>>cn;

	vint as(an), bs(bn);

	rep(i,an){ cin>>as[i]; }
	rep(i,bn){ cin>>bs[i]; }

	vector< vector<double> > dp(bn+1, vector<double>(bn+1, 0) );

	dp[0][0] = 0;
	rep(i,an){ dp[0][0] += as[i]; }

	rep(i,bn) rep(j,bn)
	{
		int ok = j + 1;
		int ng = 1 + cn + i + 1 - ok;
		dp[i+1][j+1] += dp[i][j] * double(bs[i]) * double(ok) / double(ok + ng);
		dp[i+1][j]   += dp[i][j] * double(ng)                 / double(ok + ng);
	}

	double res = 0.f;
	rep(i,bn+1){ res += dp[bn][i]; }

	printf("%.09f\n",res / double(1+cn));

	return 0;
}
