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

#define REP(i,p,n) for(ll i=p;i<n;++i)
#define rep(i,n) REP(i,0,n)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vint;
typedef vector<pii> vpii;
typedef vector<vint> det1;
typedef vector<vpii> det2;

ll mod = 1000000007;
ll N,K;
vint ATK, DEF;

int main()
{
	cin>>N>>K;
	if(N>20){ return 0; }

	ATK.assign(N,0);
	DEF.assign(N,0);
	rep(i,N){ cin>>ATK[i]>>DEF[i]; }

	ll min_s = ll(1e+9);
	ll min_num = 0;

	rep(i,1<<N)
	{
		ll k = 0;
		rep(j,N){ if((i>>j)&1){ ++k; } }
		if(k!=K){ continue; }

		ll s = 0;
		REP(j,0,N) REP(t,j+1,N) if(((i>>j)&1)&&((i>>t)&1))
		{
			s = max<ll>(s, max<ll>(abs(ATK[j]-ATK[t]),abs(DEF[j]-DEF[t])));
		}

		if(s<min_s)
		{
			min_s = s;
			min_num = 1;
		}
		else if(s==min_s)
		{
			++min_num;
		}
	}

	cout<<min_s<<endl;
	cout<<(min_num%mod)<<endl;

	return 0;
}
