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

const int MAXN=100000;
const int MAXM=100000;
int N,M;
det1 G;
vint V;

bool dfs(int now)
{
	if(V[now]){ return false; } else { V[now] = true; }

	rep(i,G[now].size()){ dfs(G[now][i]); }
	return true;
}

int main()
{
	cin>>N>>M;
	G.assign(N,vint());
	V.assign(N,0);

	int a,b;
	rep(i,M)
	{
		cin>>a>>b;
		--a;
		--b;

		G[a].push_back(b);
		G[b].push_back(a);
	}

	int ans = 0;
	rep(i,N){ if(dfs(i)){ ++ans; } }

	cout<<(ans-1)<<endl;

	return 0;
}
