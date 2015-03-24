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

const ll mod = static_cast<ll>(1e9) + 7LL;

ll fp(ll n)
{
	ll res = 1;
	rep(i,n){ res *= (i+1); res %= mod; }

	return res;
}

int main()
{
	ll n;
	cin>>n;

	vector<ll> times(n);
	rep(i,n){ cin>>times[i]; }
	sort(times.begin(), times.end());

	ll t=0;
	rep(i,n){ rep(j,i+1){ t += times[j]; } }

	vector<ll> dup(10001,0);
	rep(i,n){ ++dup[times[i]]; }

	ll d=1;
	rep(i,dup.size()){ if(dup[i]!=0){ d *= fp(dup[i]); d %= mod; } }

	cout<<t<<endl;
	cout<<d<<endl;

	return 0;
}
