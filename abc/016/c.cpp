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

int N,M;
const int INF = int(1e8);

const int MAXN = 16;
int dist[MAXN][MAXN];

void warshall_floyd(int n)
{
	rep(k,n) rep(i,n) rep(j,n)
	{
		dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
	}
}

int main()
{
	cin>>N>>M;
	rep(i,N){ rep(j,N){ dist[i][j]=INF; } }

	int a,b;
	rep(i,M)
	{
		cin>>a>>b; --a; --b;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}

	rep(i,N){ dist[i][i]=0; }

	warshall_floyd(N);

	rep(i,N)
	{
		int ans = 0;
		rep(j,N){ if(i!=j && dist[i][j]==2 && dist[i][j]!=INF){ ++ans; } }

		cout<<ans<<endl;
	}

	return 0;
}
