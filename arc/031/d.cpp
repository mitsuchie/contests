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

const int MAXN=11;
const int MAXM=101;
vint S, T;
det1 items;

int main()
{
	int N,M; cin>>N>>M;
	if(N>10){ cout<<"?"<<endl; return 0; }

	S.assign(N,0); rep(i,N){ cin>>S[i]; }
	T.assign(M,0); rep(i,M){ cin>>T[i]; }
	items.assign(N,vint());

	rep(i,N)
	{
		int k; cin>>k;
		items[i].assign(k,0);
		rep(j,k){ cin>>items[i][j]; }
	}
	
	vint used(M,0);
	double ans = 0.0;

	rep(s,1<<N)
	{
		rep(i,M){ used[i] = 0; }
		rep(i,N){ if((s>>i)&1){ rep(j,items[i].size()){ used[items[i][j]-1] = 1; } } }

		int money = 0;
		rep(i,M){ if(used[i]){ money += T[i]; } }

		int exp = 0;
		rep(i,N){ if((s>>i)&1){ exp += S[i]; } }

		if(money==0){ continue; }
		ans = max(ans, double(exp)/double(money));
	}

	printf("%.5f",ans);
	return 0;
}
