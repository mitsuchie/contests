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

const int MAXN = 50;
const int MAXM = 50;
const int MAXL = 10000;
int dp[MAXN+1][MAXM+1][MAXL+1];
int W, N, K;

int A[MAXN];
int B[MAXN];

int dfs(int n,int m,int l)
{
	if(dp[n][m][l] != 0){ return dp[n][m][l]; }
	if(n == N){ return 0; }

	int res = dfs(n+1,m,l);
	if(m<K && l>=A[n]){ res = max(res,dfs(n+1,m+1,l-A[n]) + B[n]); }

	return (dp[n][m][l] = res);
}

int main()
{
	cin>>W>>N>>K;
	rep(i,N){ cin>>A[i]>>B[i]; }
	cout<<dfs(0,0,W)<<endl;

	return 0;
}
