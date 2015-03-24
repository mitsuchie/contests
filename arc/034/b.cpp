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

ll f(ll x)
{
	ll res = 0;
	while(x){ res+=(x%10); x/=10; }

	return res;
}

int main()
{
	ll n;
	cin>>n;

	ll ans = 0;
	vector<ll> xs;

	for(ll x=max(0LL,n-18*10);x<=n;++x)
	{
		if( x + f(x) == n ){ ++ans; xs.push_back(x); }
	}

	cout<<ans<<endl;
	rep(i,xs.size()){ cout<<xs[i]<<endl; }

	return 0;
}
