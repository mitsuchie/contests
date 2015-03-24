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

const int MAXN=401;
int costsA[MAXN][MAXN];
int costsB[MAXN][MAXN];

int main()
{
	rep(i,MAXN){ rep(j,MAXN){ costsA[i][j]=static_cast<int>(1e9); } }
	rep(i,MAXN){ rep(j,MAXN){ costsB[i][j]=static_cast<int>(1e9); } }
	
	int n, m;
	cin>>n>>m;

	rep(i,m)
	{
		int a,b,c;
		cin>>a>>b>>c;
		--a;
		--b;

		costsA[a][b] = min(costsA[a][b], c);
		costsA[b][a] = min(costsA[b][a], c);
		costsB[a][b] = min(costsB[a][b], c);
		costsB[b][a] = min(costsB[b][a], c);
	}

	int k;
	cin>>k;

	rep(i,k)
	{
		int a,b,c;
		cin>>a>>b>>c;
		--a;
		--b;

		costsB[a][b] = min(costsB[a][b], c);
		costsB[b][a] = min(costsB[b][a], c);
	}

	return 0;
}
